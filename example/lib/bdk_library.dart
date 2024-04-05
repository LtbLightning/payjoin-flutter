// import 'package:bdk_flutter/bdk_flutter.dart';
// import 'package:flutter/cupertino.dart';
//
// class BdkLibrary {
//   Future<Mnemonic> createMnemonic() async {
//     final res = await Mnemonic.create(WordCount.words12);
//     return res;
//   }
//
//   Future<Descriptor> createDescriptor(Mnemonic mnemonic) async {
//     final descriptorSecretKey = await DescriptorSecretKey.create(
//       network: Network.testnet,
//       mnemonic: mnemonic,
//     );
//     final descriptor = await Descriptor.newBip84(
//         secretKey: descriptorSecretKey,
//         network: Network.testnet,
//         keychain: KeychainKind.externalChain);
//     return descriptor;
//   }
//
//   Future<Blockchain> initializeBlockchain() async {
//     return await Blockchain.create(
//         config: const BlockchainConfig.esplora(
//             config:
//                 EsploraConfig(baseUrl: 'https://0.0.0.0:30000', stopGap: 10)));
//   }
//
//   Future<Wallet> restoreWallet(Descriptor descriptor) async {
//     final wallet = await Wallet.create(
//         descriptor: descriptor,
//         network: Network.regtest,
//         databaseConfig: const DatabaseConfig.memory());
//     return wallet;
//   }
//
//   Future<void> sync(Blockchain blockchain, Wallet wallet) async {
//     try {
//       await wallet.sync(blockchain: blockchain);
//     } on EsploraException catch (e) {
//       debugPrint(e.message);
//     }
//   }
//
//   Future<AddressInfo> getAddress(Wallet aliceWallet) async {
//     final address = await aliceWallet.getAddress(
//         addressIndex: const AddressIndex.increase());
//     return address;
//   }
//
//   Future<List<TransactionDetails>> getUnConfirmedTransactions(
//       Wallet wallet) async {
//     List<TransactionDetails> unConfirmed = [];
//     final res = await wallet.listTransactions(includeRaw: true);
//     for (var e in res) {
//       if (e.confirmationTime == null) unConfirmed.add(e);
//     }
//     return unConfirmed;
//   }
//
//   Future<List<TransactionDetails>> getConfirmedTransactions(
//       Wallet wallet) async {
//     List<TransactionDetails> confirmed = [];
//     final res = await wallet.listTransactions(includeRaw: true);
//
//     for (var e in res) {
//       if (e.confirmationTime != null) confirmed.add(e);
//     }
//     return confirmed;
//   }
//
//   Future<Balance> getBalance(Wallet wallet) async {
//     final res = await wallet.getBalance();
//     return res;
//   }
//
//   Future<List<LocalUtxo>> listUnspend(Wallet wallet) async {
//     final res = await wallet.listUnspent();
//     return res;
//   }
//
//   Future<FeeRate> estimateFeeRate(
//     int blocks,
//     Blockchain blockchain,
//   ) async {
//     final feeRate = await blockchain.estimateFee(target: blocks);
//     return feeRate;
//   }
//
//   Future<PartiallySignedTransaction> buildPartiallySignedTransaction(
//       Blockchain blockchain, Wallet wallet, Address address) async {
//     try {
//       final txBuilder = TxBuilder();
//       final script = await address.scriptPubkey();
//       final feeRate = await estimateFeeRate(25, blockchain);
//       final (psbt, _) = await txBuilder
//           .addRecipient(script, 750)
//           .feeRate(feeRate.satPerVb)
//           .finish(wallet);
//       return psbt;
//     } on Exception catch (_) {
//       rethrow;
//     }
//   }
// }
