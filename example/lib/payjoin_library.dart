import 'dart:async';
import 'dart:convert';
import 'dart:typed_data';

import 'package:flutter/cupertino.dart';
import 'package:payjoin_flutter/common.dart' as common;
import 'package:payjoin_flutter/receive/v1.dart' as v1;
import 'package:payjoin_flutter/send.dart' as send;
import 'package:payjoin_flutter/uri.dart' as pj_uri;

class PayJoinLibrary {
  static const pjUrl = "https://localhost:8088";
  static const ohRelay = "https://localhost:8088";
  static const localCertFile = "localhost.der";
  Future<String> buildPjUri(double amount, String address, {String? pj}) async {
    try {
      final pjUri = "$address?amount=$amount&pj=${pj ?? pjUrl}";
      await pj_uri.Uri.fromString(pjUri);
      return pjUri;
    } catch (e) {
      debugPrint(e.toString());
      rethrow;
    }
  }

  Future<v1.ProvisionalProposal> handlePjRequest(
      String psbtBase64, Future<bool> Function(Uint8List) isOwned) async {
    final body = utf8.encode(psbtBase64);

    final headers = common.Headers(map: {
      'content-type': 'text/plain',
      'content-length': body.length.toString(),
    });
    final unchecked = await v1.UncheckedProposal.fromRequest(
        body: body.toList(), query: '', headers: headers);
    final provisionalProposal = await handleUnckedProposal(unchecked, isOwned);
    return provisionalProposal;
  }

  Future<v1.ProvisionalProposal> handleUnckedProposal(
      v1.UncheckedProposal uncheckedProposal,
      Future<bool> Function(Uint8List) isOwned) async {
    // in a payment processor where the sender could go offline, this is where you schedule to broadcast the original_tx
    var _ = await uncheckedProposal.extractTxToScheduleBroadcast();
    final inputsOwned = await uncheckedProposal.checkBroadcastSuitability(
        canBroadcast: (e) async {
      return true;
    });
    // Receive Check 2: receiver can't sign for proposal inputs
    final mixedInputScripts =
        await inputsOwned.checkInputsNotOwned(isOwned: isOwned);

    // Receive Check 3: receiver can't sign for proposal inputs
    final seenInputs = await mixedInputScripts.checkNoMixedInputScripts();
    // Receive Check 4: have we seen this input before? More of a check for non-interactive i.e. payment processor receivers.
    final provisionalProposal =
        await (await seenInputs.checkNoInputsSeenBefore(isKnown: (e) async {
      return false;
    }))
            .identifyReceiverOutputs(isReceiverOutput: isOwned);
    return provisionalProposal;
  }
}
