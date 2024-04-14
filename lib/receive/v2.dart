import 'dart:async';

import 'package:flutter_rust_bridge/flutter_rust_bridge_for_generated.dart';

import '../common.dart';
import '../src/exceptions.dart';
import '../src/generated/api/receive.dart' as receive;
import '../src/generated/utils/error.dart' as error;
import '../uri.dart' as uri;

class Enroller extends receive.Enroller {
  Enroller._({required super.field0});

  Future<Enroller> fromRelayConfig(
      {required String relayUrl,
      required String ohttpConfigBase64,
      required String ohttpProxyUrl,
      dynamic hint}) async {
    try {
      final res = await receive.Enroller.fromRelayConfig(
          relayUrl: relayUrl,
          ohttpConfigBase64: ohttpConfigBase64,
          ohttpProxyUrl: ohttpProxyUrl);
      return Enroller._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<String> payjoinSubdir({dynamic hint}) {
    try {
      return super.payjoinSubdir();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<String> subdirectory({dynamic hint}) {
    try {
      return super.subdirectory();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<Enrolled> processResponse(
      {required List<int> body, required ClientResponse clientResponse}) async {
    try {
      final res = await super.processRes(body: body, ctx: clientResponse);
      return Enrolled._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<(Request, ClientResponse)> extractRequest({hint}) async {
    try {
      final res = await super.extractReq();
      final request = Request(
          await uri.Url.fromString((await res.$1.$1.query())!), res.$1.$2);
      return (request, ClientResponse._(field0: res.$2.field0));
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class Enrolled extends receive.Enrolled {
  Enrolled._({required super.field0});
  Future<(Request, ClientResponse)> extractV2Request({hint}) async {
    try {
      final res = await super.extractReq();
      final request = Request(
          await uri.Url.fromString((await res.$1.$1.query())!), res.$1.$2);
      return (request, ClientResponse._(field0: res.$2.field0));
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<UncheckedProposal?> processResponse(
      {required List<int> body, required ClientResponse clientResponse}) async {
    try {
      final res = await super.processRes(body: body, ctx: clientResponse);
      if (res != null) {
        return UncheckedProposal._(field0: res.field0);
      } else {
        return null;
      }
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<String> fallbackTarget({dynamic hint}) {
    try {
      return super.fallbackTarget();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class UncheckedProposal extends receive.V2UncheckedProposal {
  UncheckedProposal._({required super.field0});

  ///The Sender’s Original PSBT
  @override
  Future<Uint8List> extractTxToScheduleBroadcast({hint}) async {
    try {
      return super.extractTxToScheduleBroadcast();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  ///Call after checking that the Original PSBT can be broadcast.
  /// Receiver MUST check that the Original PSBT from the sender can be broadcast, i.e. testmempoolaccept bitcoind rpc returns { “allowed”: true,.. } for gettransactiontocheckbroadcast() before calling this method.
  /// Do this check if you generate bitcoin uri to receive Payjoin on sender request without manual human approval, like a payment processor. Such so called “non-interactive” receivers are otherwise vulnerable to probing attacks. If a sender can make requests at will, they can learn which bitcoin the receiver owns at no cost. Broadcasting the Original PSBT after some time in the failure case makes incurs sender cost and prevents probing.
  /// Call this after checking downstream.
  @override
  Future<MaybeInputsOwned> checkBroadcastSuitability(
      {int? minFeeRate,
      required FutureOr<bool> Function(Uint8List p1) canBroadcast,
      hint}) async {
    try {
      final res = await super.checkBroadcastSuitability(
          minFeeRate: minFeeRate, canBroadcast: canBroadcast);
      return MaybeInputsOwned._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  ///Call this method if the only way to initiate a Payjoin with this receiver requires manual intervention, as in most consumer wallets.
  /// So-called “non-interactive” receivers, like payment processors,
  /// that allow arbitrary requests are otherwise vulnerable to probing attacks. Those receivers call gettransactiontocheckbroadcast() and attesttestedandscheduledbroadcast() after making those checks downstream
  @override
  Future<MaybeInputsOwned> assumeInteractiveReceiver({hint}) async {
    try {
      final res = await super.assumeInteractiveReceiver();
      return MaybeInputsOwned._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class MaybeInputsOwned extends receive.V2MaybeInputsOwned {
  MaybeInputsOwned._({required super.field0});

  ///Check that the Original PSBT has no receiver-owned inputs. Return original-psbt-rejected error or otherwise refuse to sign undesirable inputs.
  /// An attacker could try to spend receiver's own inputs. This check prevents that.
  @override
  Future<MaybeMixedInputScripts> checkInputsNotOwned(
      {required FutureOr<bool> Function(Uint8List p1) isOwned, hint}) async {
    try {
      final res = await super.checkInputsNotOwned(isOwned: isOwned);
      return MaybeMixedInputScripts._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class MaybeMixedInputScripts extends receive.V2MaybeMixedInputScripts {
  MaybeMixedInputScripts._({required super.field0});

  /// Make sure that the original transaction inputs have never been seen before.
  /// This prevents probing attacks. This prevents reentrant Payjoin, where a sender
  /// proposes a Payjoin PSBT as a new Original PSBT for a new Payjoin.
  @override
  Future<MaybeInputsSeen> checkNoMixedInputScripts({hint}) async {
    try {
      final res = await super.checkNoMixedInputScripts();
      return MaybeInputsSeen._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class MaybeInputsSeen extends receive.V2MaybeInputsSeen {
  MaybeInputsSeen._({required super.field0});

  /// Make sure that the original transaction inputs have never been seen before.
  /// This prevents probing attacks. This prevents reentrant Payjoin, where a sender
  /// proposes a Payjoin PSBT as a new Original PSBT for a new Payjoin.
  @override
  Future<OutputsUnknown> checkNoInputsSeenBefore(
      {required FutureOr<bool> Function(OutPoint p1) isKnown, hint}) async {
    try {
      final res = await super.checkNoInputsSeenBefore(isKnown: isKnown);
      return OutputsUnknown._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class OutputsUnknown extends receive.V2OutputsUnknown {
  OutputsUnknown._({required super.field0});

  /// Find which outputs belong to the receiver
  @override
  Future<receive.V2ProvisionalProposal> identifyReceiverOutputs(
      {required FutureOr<bool> Function(Uint8List p1) isReceiverOutput,
      hint}) async {
    try {
      final res = await super
          .identifyReceiverOutputs(isReceiverOutput: isReceiverOutput);
      return ProvisionalProposal._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class ProvisionalProposal extends receive.V2ProvisionalProposal {
  ProvisionalProposal._({required super.field0});

  @override
  Future<void> substituteOutputAddress({required String address, hint}) {
    try {
      return super.substituteOutputAddress(address: address);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<void> contributeNonWitnessInput(
      {required List<int> tx, required OutPoint outpoint, hint}) {
    try {
      return super.contributeNonWitnessInput(tx: tx, outpoint: outpoint);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<void> contributeWitnessInput(
      {required TxOut txo, required OutPoint outpoint, hint}) {
    try {
      return super.contributeWitnessInput(txo: txo, outpoint: outpoint);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  /// Select receiver input such that the common.dart avoids surveillance. Return the input chosen that has been applied to the Proposal.
  ///
  /// Proper coin selection allows common.dart to resemble ordinary transactions. To ensure the resemblance, a number of heuristics must be avoided.
  ///
  /// UIH “Unnecessary input heuristic” is one class of them to avoid. We define UIH1 and UIH2 according to the BlockSci practice BlockSci UIH1 and UIH2:
  @override
  Future<OutPoint> tryPreservingPrivacy(
      {required Map<int, OutPoint> candidateInputs, hint}) {
    try {
      return super.tryPreservingPrivacy(candidateInputs: candidateInputs);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<receive.V2PayjoinProposal> finalizeProposal(
      {required FutureOr<String> Function(String p1) processPsbt,
      int? minFeerateSatPerVb,
      hint}) async {
    try {
      final res = await super.finalizeProposal(
          processPsbt: processPsbt, minFeerateSatPerVb: minFeerateSatPerVb);
      return PayjoinProposal._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class PayjoinProposal extends receive.V2PayjoinProposal {
  PayjoinProposal._({required super.field0});
  @override
  Future<Uint8List> deserializeRes(
      {required List<int> res,
      required receive.ClientResponse ohttpContext,
      hint}) async {
    try {
      return super.deserializeRes(ohttpContext: ohttpContext, res: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<String> extractV1Req({hint}) {
    try {
      return super.extractV1Req();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<(Request, ClientResponse)> extractV2Request({hint}) async {
    try {
      final res = await super.extractV2Req();
      final request = Request(
          await uri.Url.fromString((await res.$1.$1.query())!), res.$1.$2);
      return (request, ClientResponse._(field0: res.$2.field0));
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<bool> isOutputSubstitutionDisabled({hint}) {
    try {
      return super.isOutputSubstitutionDisabled();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<Uint64List> ownedVouts({hint}) {
    try {
      return super.ownedVouts();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<String> psbt({hint}) {
    try {
      return super.psbt();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<List<OutPoint>> utxosToBeLocked({hint}) {
    try {
      return super.utxosToBeLocked();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class ClientResponse extends receive.ClientResponse {
  ClientResponse._({required super.field0});
}
