import 'dart:convert';

import 'package:bdk_flutter/bdk_flutter.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:integration_test/integration_test.dart';
import 'package:payjoin_flutter/common.dart' as common;
import 'package:payjoin_flutter/uri.dart' as pay_join_uri;
import 'package:payjoin_flutter_example/btc_client.dart';
import 'package:payjoin_flutter_example/payjoin_library.dart';

void main() {
  IntegrationTestWidgetsFlutterBinding.ensureInitialized();

  group('v1_to_v1', () {
    setUp(() async {});
    testWidgets('full_cycle', (WidgetTester tester) async {
      final payJoinLib = PayJoinLibrary();
      final sender = BtcClient("receiver");
      final client = BtcClient("");
      final receiver = BtcClient("sender");
      // Receiver creates the payjoin URI
      final pjReceiverAddress = await receiver.getNewAddress();
      final pjSenderAddress = await sender.getNewAddress();
      //Generate blocks to receiver and sender
      await client.sendToAddress(pjSenderAddress, 10);
      await client.sendToAddress(pjReceiverAddress, 1);
      await sender.generate(11, pjSenderAddress);
      await receiver.generate(1, pjReceiverAddress);
      final pjUri = await payJoinLib.buildPjUri(0.0083285, pjReceiverAddress);
      // Sender create a funded PSBT (not broadcast) to address with amount given in the pjUri
      debugPrint("Sender Balance: ${(await sender.getBalance()).toString()}");
      final uri = await pay_join_uri.Uri.fromString(pjUri);
      final address = await uri.address();
      final amount = await uri.amount();
      final senderPsbt =
          (await sender.walletCreateFundedPsbt(amount, address, 2000))["psbt"];
      debugPrint(
        "\nOriginal sender psbt: $senderPsbt",
      );
      final (provisionalProposal, ctx) =
          await payJoinLib.handlePjRequest(senderPsbt, pjUri, (e) async {
        final script = ScriptBuf(bytes: e);
        final address = await (await Address.fromScript(
                script: script, network: Network.regtest))
            .asString();
        return (await receiver.getAddressInfo(address))["ismine"];
      });
      final availableInputs = await receiver.listUnspent([]);
      // Select receiver payjoin inputs.
      Map<int, common.OutPoint> candidateInputs = {};
      for (var e in availableInputs) {
        int amount = (e["amount"] * 100000000).toInt();
        candidateInputs[amount] =
            common.OutPoint(txid: e["txid"], vout: e["vout"]);
      }
      final selectedOutpoint = await provisionalProposal.tryPreservingPrivacy(
          candidateInputs: candidateInputs);

      final selectedUtxo = availableInputs.firstWhere((e) =>
          (e["txid"] == selectedOutpoint.txid) &&
          (e["vout"] == selectedOutpoint.vout));
      final selectedUtxoScriptPubKey =
          await ScriptBuf.fromHex(selectedUtxo["scriptPubKey"]);
      int selectedUtxoAmount = (selectedUtxo["amount"] * 100000000).toInt();
      final txoutToContribute = common.TxOut(
        scriptPubkey: selectedUtxoScriptPubKey.bytes,
        value: selectedUtxoAmount,
      );
      final outputToContribute = common.OutPoint(
          txid: selectedUtxo["txid"], vout: selectedUtxo["vout"]);
      await provisionalProposal.contributeWitnessInput(
          txo: txoutToContribute, outpoint: outputToContribute);
      final newReceiverAddress = await receiver.getNewAddress();
      await provisionalProposal.substituteOutputAddress(
          address: newReceiverAddress);
      final payJoinProposal =
          await provisionalProposal.finalizeProposal(processPsbt: (e) async {
        return (await receiver.walletProcessPsbt(e))["psbt"];
      });
      final receiverPsbt = await payJoinProposal.psbt();
      debugPrint("\n Original receiver psbt: $receiverPsbt");
      final receiverProcessedPsbt =
          await ctx.processResponse(response: utf8.encode(receiverPsbt));
      final senderProcessedPsbt =
          (await sender.walletProcessPsbt(receiverProcessedPsbt))["psbt"];
      final senderFinalizedPsbt =
          (await sender.finalizePsbt(senderProcessedPsbt));
      final res = await sender.sendRawTransaction(senderFinalizedPsbt["hex"]);
      debugPrint("Broadcast success: $res");
    });
  });
}
