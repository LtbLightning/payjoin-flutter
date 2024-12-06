import 'dart:async';

import 'package:flutter_rust_bridge/flutter_rust_bridge_for_generated.dart';

import 'common.dart';
import 'src/exceptions.dart';
import 'src/generated/api/receive.dart';
import 'src/generated/utils/error.dart' as error;
import 'uri.dart';
import 'bitcoin_ffi.dart';

class Receiver {
  final FfiReceiver _ffiReceiver;
  Receiver._({required ffiReceiver}) : _ffiReceiver = ffiReceiver;

  static Future<Receiver> create(
      {required String address,
      required Network network,
      required Url directory,
      required OhttpKeys ohttpKeys,
      required Url ohttpRelay,
      BigInt? expireAfter}) async {
    try {
      final res = await FfiReceiver.create(
          directory: directory,
          ohttpKeys: ohttpKeys,
          ohttpRelay: ohttpRelay,
          address: address,
          expireAfter: expireAfter,
          network: network);
      return Receiver._(ffiReceiver: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<(Request, ClientResponse)> extractReq() async {
    try {
      final res = await _ffiReceiver.extractReq();
      final request = Request(
        url: await Url.fromStr(res.$1.url.asString()),
        contentType: res.$1.contentType,
        body: res.$1.body,
      );
      return (request, res.$2);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<UncheckedProposal?> processRes(
      {required List<int> body, required ClientResponse ctx}) async {
    try {
      final res = await _ffiReceiver.processRes(body: body, ctx: ctx);
      if (res != null) {
        return UncheckedProposal._(ffiUncheckedProposal: res);
      } else {
        return null;
      }
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  /// The contents of the `&pj=` query parameter including the base64url-encoded public key receiver subdirectory.
  /// This identifies a session at the payjoin directory server.
  Future<Url> pjUrl() async {
    final res = await _ffiReceiver.pjUrl();
    return Url.fromStr(res.asString());
  }

  PjUriBuilder pjUriBuilder() {
    final res = _ffiReceiver.pjUriBuilder();
    return PjUriBuilder(internal: res.internal);
  }

  String toJson() {
    return _ffiReceiver.toJson();
  }

  static Receiver fromJson(String json) {
    try {
      final res = FfiReceiver.fromJson(json: json);
      return Receiver._(ffiReceiver: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class UncheckedProposal {
  final FfiUncheckedProposal _ffiUncheckedProposal;
  UncheckedProposal._({required ffiUncheckedProposal})
      : _ffiUncheckedProposal = ffiUncheckedProposal;

  ///The Sender’s Original PSBT
  Future<Uint8List> extractTxToScheduleBroadcast({hint}) async {
    try {
      return _ffiUncheckedProposal.extractTxToScheduleBroadcast();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  ///Call after checking that the Original PSBT can be broadcast.
  /// Receiver MUST check that the Original PSBT from the sender can be broadcast, i.e. testmempoolaccept bitcoind rpc returns { “allowed”: true,.. } for gettransactiontocheckbroadcast() before calling this method.
  /// Do this check if you generate bitcoin uri to receive Payjoin on sender request without manual human approval, like a payment processor. Such so called “non-interactive” receivers are otherwise vulnerable to probing attacks. If a sender can make requests at will, they can learn which bitcoin the receiver owns at no cost. Broadcasting the Original PSBT after some time in the failure case makes incurs sender cost and prevents probing.
  /// Call this after checking downstream.
  Future<MaybeInputsOwned> checkBroadcastSuitability(
      {BigInt? minFeeRate,
      required FutureOr<bool> Function(Uint8List p1) canBroadcast,
      hint}) async {
    try {
      final res = await _ffiUncheckedProposal.checkBroadcastSuitability(
          minFeeRate: minFeeRate, canBroadcast: canBroadcast);
      return MaybeInputsOwned._(ffiMaybeInputsOwned: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  ///Call this method if the only way to initiate a Payjoin with this receiver requires manual intervention, as in most consumer wallets.
  /// So-called “non-interactive” receivers, like payment processors,
  /// that allow arbitrary requests are otherwise vulnerable to probing attacks. Those receivers call gettransactiontocheckbroadcast() and attesttestedandscheduledbroadcast() after making those checks downstream
  Future<MaybeInputsOwned> assumeInteractiveReceiver({hint}) async {
    try {
      final res = await _ffiUncheckedProposal.assumeInteractiveReceiver();
      return MaybeInputsOwned._(ffiMaybeInputsOwned: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class MaybeInputsOwned {
  final FfiMaybeInputsOwned _ffiMaybeInputsOwned;
  MaybeInputsOwned._({required ffiMaybeInputsOwned})
      : _ffiMaybeInputsOwned = ffiMaybeInputsOwned;

  ///Check that the Original PSBT has no receiver-owned inputs. Return original-psbt-rejected error or otherwise refuse to sign undesirable inputs.
  /// An attacker could try to spend receiver's own inputs. This check prevents that.
  Future<MaybeInputsSeen> checkInputsNotOwned(
      {required FutureOr<bool> Function(Uint8List p1) isOwned, hint}) async {
    try {
      final res =
          await _ffiMaybeInputsOwned.checkInputsNotOwned(isOwned: isOwned);
      return MaybeInputsSeen._(ffiMaybeInputsSeen: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class MaybeInputsSeen {
  final FfiMaybeInputsSeen _ffiMaybeInputsSeen;
  MaybeInputsSeen._({required ffiMaybeInputsSeen})
      : _ffiMaybeInputsSeen = ffiMaybeInputsSeen;

  /// Make sure that the original transaction inputs have never been seen before.
  /// This prevents probing attacks. This prevents reentrant Payjoin, where a sender
  /// proposes a Payjoin PSBT as a new Original PSBT for a new Payjoin.
  Future<OutputsUnknown> checkNoInputsSeenBefore(
      {required FutureOr<bool> Function(OutPoint p1) isKnown, hint}) async {
    try {
      final res =
          await _ffiMaybeInputsSeen.checkNoInputsSeenBefore(isKnown: isKnown);
      return OutputsUnknown._(ffiOutputsUnknown: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class OutputsUnknown {
  final FfiOutputsUnknown _ffiOutputsUnknown;
  OutputsUnknown._({required ffiOutputsUnknown})
      : _ffiOutputsUnknown = ffiOutputsUnknown;

  /// Find which outputs belong to the receiver
  Future<WantsOutputs> identifyReceiverOutputs(
      {required FutureOr<bool> Function(Uint8List p1) isReceiverOutput,
      hint}) async {
    try {
      final res = await _ffiOutputsUnknown.identifyReceiverOutputs(
          isReceiverOutput: isReceiverOutput);
      return WantsOutputs._(ffiWantsOutputs: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class WantsOutputs {
  final FfiWantsOutputs _ffiWantsOutputs;
  WantsOutputs._({required ffiWantsOutputs})
      : _ffiWantsOutputs = ffiWantsOutputs;

  Future<bool> isOutputSubstitutionDisabled({hint}) {
    try {
      return _ffiWantsOutputs.isOutputSubstitutionDisabled();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<WantsOutputs> replaceReceiverOutputs(
      {required List<TxOut> replacementOutputs,
      required Script drainScript}) async {
    try {
      final res = await _ffiWantsOutputs.replaceReceiverOutputs(
          replacementOutputs: replacementOutputs, drainScript: drainScript);
      return WantsOutputs._(ffiWantsOutputs: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<WantsOutputs> substituteReceiverScript(
      {required Script outputScript}) async {
    try {
      final res = await _ffiWantsOutputs.substituteReceiverScript(
          outputScript: outputScript);
      return WantsOutputs._(ffiWantsOutputs: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<WantsInputs> commitOutputs() async {
    try {
      final res = await _ffiWantsOutputs.commitOutputs();
      return WantsInputs._(ffiWantsInputs: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class WantsInputs {
  final FfiWantsInputs _ffiWantsInputs;
  WantsInputs._({required ffiWantsInputs}) : _ffiWantsInputs = ffiWantsInputs;

  /// Select receiver input such that the payjoin avoids surveillance.
  /// Return the input chosen that has been applied to the Proposal.
  ///
  /// Proper coin selection allows payjoin to resemble ordinary transactions.
  /// To ensure the resemblance, a number of heuristics must be avoided.
  ///
  /// UIH "Unnecessary input heuristic" is one class of them to avoid. We define
  /// UIH1 and UIH2 according to the BlockSci practice
  /// BlockSci UIH1 and UIH2:
  /// if min(out) < min(in) then UIH1 else UIH2
  /// https://eprint.iacr.org/2022/589.pdf
  Future<InputPair> tryPreservingPrivacy(
      {required List<InputPair> candidateInputs}) async {
    try {
      final res = await _ffiWantsInputs.tryPreservingPrivacy(
          candidateInputs: candidateInputs);
      return InputPair._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<WantsInputs> contributeInputs(
      {required List<InputPair> replacementInputs}) async {
    try {
      final res = await _ffiWantsInputs.contributeInputs(
          replacementInputs: replacementInputs);
      return WantsInputs._(ffiWantsInputs: res);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<ProvisionalProposal> commitInputs() async {
    try {
      final res = await _ffiWantsInputs.commitInputs();
      return ProvisionalProposal._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class InputPair extends FfiInputPair {
  InputPair._({required super.field0});

  static Future<InputPair> newInstance(TxIn txin, PsbtInput psbtin) async {
    try {
      final res = await FfiInputPair.newInstance(txin: txin, psbtin: psbtin);
      return InputPair._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class ProvisionalProposal extends FfiProvisionalProposal {
  ProvisionalProposal._({required super.field0});

  @override
  Future<PayjoinProposal> finalizeProposal({
    required FutureOr<String> Function(String) processPsbt,
    BigInt? minFeeRateSatPerVb,
    required BigInt maxFeeRateSatPerVb,
  }) async {
    try {
      final res = await super.finalizeProposal(
        processPsbt: processPsbt,
        minFeeRateSatPerVb: minFeeRateSatPerVb,
        maxFeeRateSatPerVb: maxFeeRateSatPerVb,
      );
      return PayjoinProposal._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class PayjoinProposal extends FfiPayjoinProposal {
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
      final request = Request(
        url: await Url.fromStr(res.$1.url.asString()),
        contentType: res.$1.contentType,
        body: res.$1.body,
      );
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
  Future<String> psbt({hint}) {
    try {
      return super.psbt();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}
