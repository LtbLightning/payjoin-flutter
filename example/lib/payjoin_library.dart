import 'dart:async';
import 'dart:convert';
import 'dart:typed_data';

import 'package:bdk_flutter/bdk_flutter.dart';
import 'package:flutter/cupertino.dart';
import 'package:payjoin_flutter/common.dart' as common;
import 'package:payjoin_flutter/receive/v1.dart' as v1;
import 'package:payjoin_flutter/send.dart' as send;
import 'package:payjoin_flutter/uri.dart' as pj_uri;
import 'package:payjoin_flutter_example/btc_client.dart';

class PayJoinLibrary {
  static const pjUrl = "https://localhost:8088";
  static const ohRelay = "https://localhost:8088";
  static const localCertFile = "localhost.der";
  Future<String> buildPjUri(double amount, String address, {String? pj}) async {
    try {
      final pjUri = "bitcoin:$address?amount=$amount&pj=${pj ?? pjUrl}";
      await pj_uri.Uri.fromString(pjUri);
      return pjUri;
    } catch (e) {
      debugPrint(e.toString());
      rethrow;
    }
  }

  Future<String> handlePjRequest(
      String psbtBase64, String uriStr, BtcClient client) async {
    final uri = await pj_uri.Uri.fromString(uriStr);
    final (req, cxt) = await (await (await send.RequestBuilder.fromPsbtAndUri(
                psbtBase64: psbtBase64, uri: uri))
            .buildWithAdditionalFee(
                maxFeeContribution: 10000,
                minFeeRate: 0,
                clampFeeContribution: false))
        .extractContextV1();
    final headers = common.Headers(map: {
      'content-type': 'text/plain',
      'content-length': req.body.length.toString(),
    });
    final unchecked = await v1.UncheckedProposal.fromRequest(
        body: req.body.toList(),
        query: (await req.url.query())!,
        headers: headers);
    final payJoinProposal = await handleProposal(unchecked, client);
    final psbt = await payJoinProposal.psbt();
    // Sender checks, signs, finalizes, extracts, and broadcasts
    final checkedPsbt = await cxt.processResponse(response: utf8.encode(psbt));
    return checkedPsbt;
  }

  Future<bool> canBroadcast(Uint8List tx) async {
    return true;
  }

  Future<bool> isKnown(common.OutPoint o) async {
    return false;
  }

  Future<bool> isOwned(Uint8List scriptBytes, BtcClient client) async {
    final script = ScriptBuf(bytes: scriptBytes);
    final address = await (await Address.fromScript(
            script: script, network: Network.regtest))
        .asString();
    return (await client.getAddressInfo(address))["ismine"];
  }

  Future<String> processPsbt(String psbt, BtcClient client) async {
    final res = await client.walletProcessPsbt(psbt);
    return res["psbt"];
  }

  Future<v1.PayjoinProposal> handleProposal(
      v1.UncheckedProposal uncheckedProposal, BtcClient receiver) async {
    try {
      // in a payment processor where the sender could go offline, this is where you schedule to broadcast the original_tx
      var broadcastInFailureCase =
          await uncheckedProposal.extractTxToScheduleBroadcast();
      final inputsOwned = await uncheckedProposal.checkBroadcastSuitability(
          canBroadcast: canBroadcast);
      // Receive Check 2: receiver can't sign for proposal inputs
      final mixedInputScripts = await inputsOwned.checkInputsNotOwned(
          isOwned: (e) => isOwned(e, receiver));

      // Receive Check 3: receiver can't sign for proposal inputs
      final seenInputs = await mixedInputScripts.checkNoMixedInputScripts();
      // Receive Check 4: have we seen this input before? More of a check for non-interactive i.e. payment processor receivers.
      final provisionalProposal =
          await (await seenInputs.checkNoInputsSeenBefore(isKnown: isKnown))
              .identifyReceiverOutputs(
                  isReceiverOutput: (e) => isOwned(e, receiver));
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
          address: "bcrt1qzpq2j0gt74p0dlpj649gf74ksv4a0du037weua");
      final payJoinProposal = await provisionalProposal.finalizeProposal(
          processPsbt: (e) => processPsbt(e, receiver));
      return payJoinProposal;
    } on Exception catch (e) {
      rethrow;
    }
  }
}
