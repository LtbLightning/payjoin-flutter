import 'package:bdk_flutter/bdk_flutter.dart';
import 'package:flutter/cupertino.dart';

class BdkClient {
  // Bitcoin core credentials
  // String localEsploraUrl = 'http://0.0.0.0:30000';

  late Wallet wallet;
  late Blockchain blockchain;
  final String descriptor;

  BdkClient(this.descriptor);

  Future<void> restoreWallet() async {
    try {
      await initBlockchain();
      wallet = await Wallet.create(
          descriptor: await Descriptor.create(
              descriptor: descriptor, network: Network.signet),
          network: Network.signet,
          databaseConfig: const DatabaseConfig.memory());
      debugPrint(await (await getNewAddress()).address.asString());
    } on Exception {
      rethrow;
    }
  }

  Future<void> initBlockchain() async {
    // String esploraUrl =
    //     Platform.isAndroid ? 'http://10.0.2.2:30000' : localEsploraUrl;
    try {
      blockchain = await Blockchain.create(
          config: const BlockchainConfig.esplora(
              config: EsploraConfig(
                  baseUrl: "https://mutinynet.com/api", stopGap: 10)));
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
    await wallet.sign(
        psbt: psbt,
        signOptions: const SignOptions(
            trustWitnessUtxo: true,
            allowAllSighashes: false,
            removePartialSigs: true,
            tryFinalize: true,
            signWithTapInternalKey: true,
            allowGrinding: false));
    return psbt;
  }

  Future<PartiallySignedTransaction> createPsbt(
      String addressStr, int amount, int fee) async {
    try {
      final txBuilder = TxBuilder();
      final address =
          await Address.fromString(s: addressStr, network: Network.signet);
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
