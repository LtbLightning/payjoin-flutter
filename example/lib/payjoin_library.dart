import 'dart:async';
import 'dart:convert';
import 'dart:typed_data';

import 'package:flutter/cupertino.dart';
import 'package:payjoin_flutter/common.dart' as common;
import 'package:payjoin_flutter/receive/v1.dart' as v1;
import 'package:payjoin_flutter/receive/v2.dart';
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
    final provisionalProposal =
        await handleUncheckedProposal(unchecked, isOwned);
    return provisionalProposal;
  }

  Future<v1.ProvisionalProposal> handleUncheckedProposal(
      v1.UncheckedProposal uncheckedProposal,
      Future<bool> Function(Uint8List) isOwned) async {
    // A consumer wallet has some manual interaction to initiate a payjoin, it
    //  is not a server that can receive a lot of requests without the user
    //  being aware of it. Therefore we say a consumer wallet app is an
    //  interactive receiver and an automatic payment processor is
    //  non-interactive.
    //
    //  The way to check a proposal for these cases are different:
    //   - For an interactive receiver, you can just call
    //      `assumeInteractiveReceiver` as used here in the example code.
    //   - For a non-interactive receiver, you would extract the original tx
    //      with `extractTxToScheduleBroadcast` and check if it can be
    //      broadcasted in `checkBroadcastSuitability`. This way, if the sender
    //      doesn't complete the payjoin, you can still broadcast the original
    //      tx and get your funds. This protects against sender maliciousness of
    //      probing your utxo set amongst other things.

    final inputsOwned = await uncheckedProposal.assumeInteractiveReceiver();
    /*
      // Non-interactive receiver example code:
      final originalTx = await uncheckedProposal.extractTxToScheduleBroadcast();
      final inputsOwned = await uncheckedProposal.checkBroadcastSuitability(
          canBroadcast: (e) async {
        // Here you would check if the original tx is a valid tx that pays you 
        //  and that can be broadcasted.
        return true;
      });
    */

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
