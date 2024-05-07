import 'dart:io';

import 'package:bdk_flutter/bdk_flutter.dart';
import 'package:flutter/cupertino.dart';

class BdkClient {
  late Wallet wallet;
  late Blockchain blockchain;
  final String mnemonic;

  Future<List<Descriptor>> getDescriptors(String mnemonicStr) async {
    final descriptors = <Descriptor>[];
    try {
      for (var e in [KeychainKind.externalChain, KeychainKind.internalChain]) {
        final mnemonic = await Mnemonic.fromString(mnemonicStr);
        final descriptorSecretKey = await DescriptorSecretKey.create(
          network: Network.regtest,
          mnemonic: mnemonic,
        );
        final descriptor = await Descriptor.newBip86(
            secretKey: descriptorSecretKey,
            network: Network.regtest,
            keychain: e);
        descriptors.add(descriptor);
      }
      return descriptors;
    } on Exception {
      rethrow;
    }
  }

  BdkClient(this.mnemonic);

  Future<void> restoreWallet() async {
    try {
      final descriptors = await getDescriptors(mnemonic);
      await initBlockchain();
      wallet = await Wallet.create(
          descriptor: descriptors[0],
          changeDescriptor: descriptors[1],
          network: Network.regtest,
          databaseConfig: const DatabaseConfig.memory());
    } on Exception {
      rethrow;
    }
  }

  Future<void> initBlockchain() async {
    String esploraUrl =
        Platform.isAndroid ? 'http://10.0.2.2:30000' : 'http://127.0.0.1:30000';
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
    debugPrint(await res.address.asString());
    return res;
  }

  Future<void> sendTx(String addressStr, int amount) async {
    try {
      final txBuilder = TxBuilder();
      final address =
          await Address.fromString(s: addressStr, network: Network.regtest);
      final script = await address.scriptPubkey();

      final psbt = await txBuilder
          .addRecipient(script, amount)
          .feeRate(1.0)
          .finish(wallet);

      final isFinalized = await wallet.sign(psbt: psbt.$1);
      if (isFinalized) {
        final tx = await psbt.$1.extractTx();
        final res = await blockchain.broadcast(transaction: tx);
        debugPrint(res);
      } else {
        debugPrint("psbt not finalized!");
      }
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

  Future<bool> getAddressInfo(String address) async {
    final addr = await Address.fromString(s: address, network: Network.regtest);
    final res = await wallet.isMine(script: await addr.scriptPubkey());
    return res;
  }

  Future<void> syncWallet() async {
    wallet.sync(blockchain: blockchain);
  }

  Future<List<LocalUtxo>> listUnspent() async {
    return await wallet.listUnspent();
  }
}
