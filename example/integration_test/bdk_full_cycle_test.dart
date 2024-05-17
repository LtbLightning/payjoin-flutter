import 'dart:convert';

import 'package:bdk_flutter/bdk_flutter.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:integration_test/integration_test.dart';
import 'package:payjoin_flutter/common.dart' as common;
import 'package:payjoin_flutter/uri.dart' as pay_join_uri;
import 'package:payjoin_flutter_example/bdk_client.dart';
import 'package:payjoin_flutter_example/btc_client.dart';
import 'package:payjoin_flutter_example/payjoin_library.dart';

void main() {
  IntegrationTestWidgetsFlutterBinding.ensureInitialized();

  group('v1_to_v1', () {
    setUp(() async {});
    testWidgets('full_cycle', (WidgetTester tester) async {
      final payJoinLib = PayJoinLibrary();
      final btcClient = BtcClient("sender");
      await btcClient.loadWallet();
      final sender = BdkClient(
          "puppy interest whip tonight dad never sudden response push zone pig patch");
      final receiver = BdkClient(
          "cart super leaf clinic pistol plug replace close super tooth wealth usage");
      await sender.restoreWallet();
      await receiver.restoreWallet();
      // Receiver creates the payjoin URI
      final pjReceiverAddress = (await receiver.getNewAddress()).address;
      final pjSenderAddress = (await sender.getNewAddress()).address;
      await btcClient.sendToAddress(await pjSenderAddress.asString(), 10);
      await btcClient.sendToAddress(await pjReceiverAddress.asString(), 2);
      await btcClient.generate(11, await pjSenderAddress.asString());
      await receiver.syncWallet();
      await sender.syncWallet();
      final pjUri = await payJoinLib.buildPjUri(
          0.0083285, await pjReceiverAddress.asString());
      // Sender create a funded PSBT (not broadcast) to address with amount given in the pjUri
      debugPrint("Sender Balance: ${(await sender.getBalance()).toString()}");
      final uri = await pay_join_uri.Uri.fromString(pjUri);
      final address = await uri.address();
      int amount = (((await uri.amount()) ?? 0) * 100000000).toInt();
      final senderPsbt = (await sender.createPsbt(address, amount, 2000));
      final senderPsbtBase64 = await senderPsbt.serialize();
      debugPrint(
        "\nOriginal sender psbt: $senderPsbtBase64",
      );
      // Receiver part
      final (provisionalProposal, ctx) =
          await payJoinLib.handlePjRequest(senderPsbtBase64, pjUri, (e) async {
        final script = ScriptBuf(bytes: e);
        return (await receiver.getAddressInfo(script));
      });
      final availableInputs = await receiver.listUnspent();
      // Select receiver payjoin inputs.
      Map<int, common.OutPoint> candidateInputs = {
        for (var input in availableInputs)
          input.txout.value: common.OutPoint(
              txid: input.outpoint.txid.toString(), vout: input.outpoint.vout)
      };
      final selectedOutpoint = await provisionalProposal.tryPreservingPrivacy(
          candidateInputs: candidateInputs);
      var selectedUtxo = availableInputs.firstWhere(
          (i) =>
              i.outpoint.txid.toString() == selectedOutpoint.txid &&
              i.outpoint.vout == selectedOutpoint.vout,
          orElse: () => throw Exception('UTXO not found'));
      var txoToContribute = common.TxOut(
        value: selectedUtxo.txout.value,
        scriptPubkey: selectedUtxo.txout.scriptPubkey.bytes,
      );

      var outpointToContribute = common.OutPoint(
        txid: selectedUtxo.outpoint.txid.toString(),
        vout: selectedUtxo.outpoint.vout,
      );
      await provisionalProposal.contributeWitnessInput(
          txo: txoToContribute, outpoint: outpointToContribute);
      final receiverAddress = (await receiver.getNewAddress()).address;
      await provisionalProposal.substituteOutputAddress(
          address: await receiverAddress.asString());
      final payJoinProposal =
          await provisionalProposal.finalizeProposal(processPsbt: (e) async {
        return await (await receiver
                .signPsbt(await PartiallySignedTransaction.fromString(e)))
            .serialize();
      });
      final receiverPsbt = await payJoinProposal.psbt();
      debugPrint("\n Original receiver psbt: $receiverPsbt");
      final receiverProcessedPsbt =
          await ctx.processResponse(response: utf8.encode(receiverPsbt));
      final senderProcessedPsbt = (await sender.signPsbt(
          await PartiallySignedTransaction.fromString(receiverProcessedPsbt)));

      final txid = await sender.broadcastPsbt(senderProcessedPsbt);
      debugPrint("Broadcast success: $txid");
    });
  });
}
