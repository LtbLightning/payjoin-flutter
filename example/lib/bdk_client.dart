import 'dart:io';

import 'package:bdk_flutter/bdk_flutter.dart';
import 'package:flutter/cupertino.dart';

class BdkClient {
  // Bitcoin core credentials
  String localEsploraUrl = 'http://0.0.0.0:30000';

  late Wallet wallet;
  late Blockchain blockchain;
  final String descriptor;

  BdkClient(this.descriptor);

  Future<void> restoreWallet() async {
    try {
      await initBlockchain();
      wallet = await Wallet.create(
          descriptor: await Descriptor.create(
              descriptor: descriptor, network: Network.regtest),
          network: Network.regtest,
          databaseConfig: const DatabaseConfig.memory());
    } on Exception {
      rethrow;
    }
  }

  Future<void> initBlockchain() async {
    String esploraUrl =
        Platform.isAndroid ? 'http://10.0.2.2:30000' : localEsploraUrl;
    try {
      blockchain = await Blockchain.create(
          config: BlockchainConfig.esplora(
              config: EsploraConfig(baseUrl: esploraUrl, stopGap: 10)));
    } on Exception {
      rethrow;
    }
  }

  Future<AddressInfo> getNewAddress() async {
    final res =
        await wallet.getAddress(addressIndex: const AddressIndex.increase());
    return res;
  }

  Future<List<TransactionDetails>> listTransactions() async {
    final res = await wallet.listTransactions(includeRaw: true);
    return res;
  }

  Future<PartiallySignedTransaction> signPsbt(
      PartiallySignedTransaction psbt) async {
    final isFinalized = await wallet.sign(
        psbt: psbt,
        signOptions: const SignOptions(
            multiSig: false,
            trustWitnessUtxo: true,
            allowAllSighashes: false,
            removePartialSigs: true,
            tryFinalize: false,
            signWithTapInternalKey: true,
            allowGrinding: false));
    if (isFinalized) {
      return psbt;
    } else {
      throw Exception("PartiallySignedTransaction not finalized!");
    }
  }

  Future<PartiallySignedTransaction> createPsbt(
      String addressStr, int amount, int fee) async {
    try {
      final txBuilder = TxBuilder();
      final address =
          await Address.fromString(s: addressStr, network: Network.regtest);
      final script = await address.scriptPubkey();
      final (psbt, _) = await txBuilder
          .addRecipient(script, amount)
          .feeAbsolute(fee)
          .finish(wallet);
      return signPsbt(psbt);
    } on Exception {
      rethrow;
    }
  }

  Future<int> getBalance() async {
    final balance = await wallet.getBalance();
    final res = "Total Balance: ${balance.total.toString()}";
    debugPrint(res);
    return balance.total;
  }

  Future<String> broadcastPsbt(PartiallySignedTransaction psbt) async {
    try {
      final tx = await psbt.extractTx();
      final txid = await blockchain.broadcast(transaction: tx);
      return txid;
    } on Exception {
      rethrow;
    }
  }

  Future<bool> getAddressInfo(ScriptBuf script) async {
    final res = await wallet.isMine(script: script);
    return res;
  }

  Future<void> syncWallet() async {
    wallet.sync(blockchain: blockchain);
  }

  Future<List<LocalUtxo>> listUnspent() async {
    return await wallet.listUnspent();
  }
}
