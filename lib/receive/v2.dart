import 'dart:async';

import 'package:flutter_rust_bridge/flutter_rust_bridge_for_generated.dart';

import '../common.dart';
import '../src/exceptions.dart';
import '../src/generated/api/receive.dart';
import '../src/generated/utils/error.dart' as error;
import '../uri.dart';

class SessionInitializer extends FfiSessionInitializer {
  SessionInitializer._({required super.field0});

  static Future<SessionInitializer> create(
      {required Url directory,
      required OhttpKeys ohttpKeys,
      required String address,
      required BigInt expireAfter,
      required Network network,
      required Url ohttpRelay}) async {
    try {
      final res = await FfiSessionInitializer.newInstance(
          directory: directory,
          ohttpKeys: ohttpKeys,
          ohttpRelay: ohttpRelay,
          address: address,
          expireAfter: expireAfter,
          network: network);
      return SessionInitializer._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<ActiveSession> processRes(
      {required List<int> body, required ClientResponse ctx}) async {
    try {
      final res = await super.processRes(body: body, ctx: ctx);
      return ActiveSession._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<(Request, ClientResponse)> extractReq() async {
    try {
      final res = await super.extractReq();
      final request = Request(Url.fromStr(res.$1.$1.asString()), res.$1.$2);
      return (request, res.$2);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class ActiveSession extends FfiActiveSession {
  ActiveSession._({required super.field0});

  @override
  Future<(Request, ClientResponse)> extractReq() async {
    try {
      final res = await super.extractReq();
      final request = Request(Url.fromStr(res.$1.$1.asString()), res.$1.$2);
      return (request, res.$2);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<UncheckedProposal?> processRes(
      {required List<int> body, required ClientResponse ctx}) async {
    try {
      final res = await super.processRes(body: body, ctx: ctx);
      if (res != null) {
        return UncheckedProposal._(field0: res.field0);
      } else {
        return null;
      }
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  /// The contents of the `&pj=` query parameter including the base64url-encoded public key receiver subdirectory.
  /// This identifies a session at the payjoin directory server.
  @override
  Url pjUrl() {
    final res = super.pjUrl();
    return Url.fromStr(res.asString());
  }

  @override
  PjUriBuilder pjUriBuilder() {
    final res = super.pjUriBuilder();
    return PjUriBuilder(internal: res.internal);
  }
}

class UncheckedProposal extends FfiV2UncheckedProposal {
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
      {BigInt? minFeeRate,
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

class MaybeInputsOwned extends FfiV2MaybeInputsOwned {
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

class MaybeMixedInputScripts extends FfiV2MaybeMixedInputScripts {
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

class MaybeInputsSeen extends FfiV2MaybeInputsSeen {
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

class OutputsUnknown extends FfiV2OutputsUnknown {
  OutputsUnknown._({required super.field0});

  /// Find which outputs belong to the receiver
  @override
  Future<ProvisionalProposal> identifyReceiverOutputs(
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

class ProvisionalProposal extends FfiV2ProvisionalProposal {
  ProvisionalProposal._({required super.field0});

  @override
  Future<void> trySubstituteReceiverOutput(
      {required FutureOr<Uint8List> Function() generateScript}) {
    try {
      return super.trySubstituteReceiverOutput(generateScript: generateScript);
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
      {required Map<BigInt, OutPoint> candidateInputs, hint}) {
    try {
      return super.tryPreservingPrivacy(candidateInputs: candidateInputs);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<PayjoinProposal> finalizeProposal(
      {required FutureOr<String> Function(String p1) processPsbt,
      BigInt? minFeeRateSatPerVb,
      hint}) async {
    try {
      final res = await super.finalizeProposal(
          processPsbt: processPsbt, minFeeRateSatPerVb: minFeeRateSatPerVb);
      return PayjoinProposal._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class PayjoinProposal extends FfiV2PayjoinProposal {
  PayjoinProposal._({required super.field0});

  @override
  Future<void> processRes(
      {required List<int> res, required ClientResponse ohttpContext}) {
    try {
      return super.processRes(ohttpContext: ohttpContext, res: res);
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

  @override
  Future<(Request, ClientResponse)> extractV2Req() async {
    try {
      final res = await super.extractV2Req();
      final request = Request(Url.fromStr(res.$1.$1.asString()), res.$1.$2);
      return (request, res.$2);
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
