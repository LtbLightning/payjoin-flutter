import 'dart:async';

import 'package:flutter_rust_bridge/flutter_rust_bridge_for_generated.dart';
import 'package:payjoin_flutter/src/generated/api/uri.dart';
import 'package:payjoin_flutter/src/generated/lib.dart';

import 'common.dart';
import 'src/generated/api/receive.dart';
import 'uri.dart' as uri;
import 'bitcoin_ffi.dart' as bitcoin;

class NewReceiver {
  final FfiNewReceiver _ffiNewReceiver;
  NewReceiver._({required ffiNewReceiver}) : _ffiNewReceiver = ffiNewReceiver;

  static Future<NewReceiver> create(
      {required String address,
      required Network network,
      required String directory,
      required uri.OhttpKeys ohttpKeys,
      BigInt? expireAfter}) async {
    final res = await FfiNewReceiver.create(
        directory: directory,
        ohttpKeys: ohttpKeys,
        address: address,
        expireAfter: expireAfter,
        network: network);
    return NewReceiver._(ffiNewReceiver: res);
  }

  Future<ReceiverToken> persist(
      {required DartReceiverPersister persister}) async {
    return await _ffiNewReceiver.persist(persister: persister);
  }
}

class Receiver {
  final FfiReceiver _ffiReceiver;
  Receiver._({required ffiReceiver}) : _ffiReceiver = ffiReceiver;

  static Future<Receiver> load(
      {required DartReceiverPersister persister,
      required ReceiverToken token}) async {
    final res = await FfiReceiver.load(token: token, persister: persister);
    return Receiver._(ffiReceiver: res);
  }

  Future<(Request, ClientResponse)> extractReq(
      {required String ohttpRelay}) async {
    final res = await _ffiReceiver.extractReq(ohttpRelay: ohttpRelay);
    final request = Request(
      url: await uri.Url.fromStr(res.$1.url.asString()),
      contentType: res.$1.contentType,
      body: res.$1.body,
    );
    return (request, res.$2);
  }

  Future<UncheckedProposal?> processRes(
      {required List<int> body, required ClientResponse ctx}) async {
    final res = await _ffiReceiver.processRes(body: body, ctx: ctx);
    if (res != null) {
      return UncheckedProposal._(ffiUncheckedProposal: res);
    } else {
      return null;
    }
  }

  String id() {
    return _ffiReceiver.id();
  }

  Future<FfiPjUri> pjUri() async {
    return await _ffiReceiver.pjUri();
  }

  String toJson() {
    return _ffiReceiver.toJson();
  }

  static Receiver fromJson(String json) {
    final res = FfiReceiver.fromJson(json: json);
    return Receiver._(ffiReceiver: res);
  }

  Future<ReceiverToken> key() async {
    return _ffiReceiver.key();
  }
}

class UncheckedProposal {
  final FfiUncheckedProposal _ffiUncheckedProposal;
  UncheckedProposal._({required ffiUncheckedProposal})
      : _ffiUncheckedProposal = ffiUncheckedProposal;

  ///The Sender’s Original PSBT
  Future<Uint8List> extractTxToScheduleBroadcast({hint}) async {
    return _ffiUncheckedProposal.extractTxToScheduleBroadcast();
  }

  ///Call after checking that the Original PSBT can be broadcast.
  /// Receiver MUST check that the Original PSBT from the sender can be broadcast, i.e. testmempoolaccept bitcoind rpc returns { “allowed”: true,.. } for gettransactiontocheckbroadcast() before calling this method.
  /// Do this check if you generate bitcoin uri to receive Payjoin on sender request without manual human approval, like a payment processor. Such so called “non-interactive” receivers are otherwise vulnerable to probing attacks. If a sender can make requests at will, they can learn which bitcoin the receiver owns at no cost. Broadcasting the Original PSBT after some time in the failure case makes incurs sender cost and prevents probing.
  /// Call this after checking downstream.
  Future<MaybeInputsOwned> checkBroadcastSuitability(
      {BigInt? minFeeRate,
      required FutureOr<bool> Function(Uint8List p1) canBroadcast,
      hint}) async {
    final res = await _ffiUncheckedProposal.checkBroadcastSuitability(
        minFeeRate: minFeeRate, canBroadcast: canBroadcast);
    return MaybeInputsOwned._(ffiMaybeInputsOwned: res);
  }

  ///Call this method if the only way to initiate a Payjoin with this receiver requires manual intervention, as in most consumer wallets.
  /// So-called “non-interactive” receivers, like payment processors,
  /// that allow arbitrary requests are otherwise vulnerable to probing attacks. Those receivers call gettransactiontocheckbroadcast() and attesttestedandscheduledbroadcast() after making those checks downstream
  Future<MaybeInputsOwned> assumeInteractiveReceiver({hint}) async {
    final res = await _ffiUncheckedProposal.assumeInteractiveReceiver();
    return MaybeInputsOwned._(ffiMaybeInputsOwned: res);
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
    final res =
        await _ffiMaybeInputsOwned.checkInputsNotOwned(isOwned: isOwned);
    return MaybeInputsSeen._(ffiMaybeInputsSeen: res);
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
    final res =
        await _ffiMaybeInputsSeen.checkNoInputsSeenBefore(isKnown: isKnown);
    return OutputsUnknown._(ffiOutputsUnknown: res);
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
    final res = await _ffiOutputsUnknown.identifyReceiverOutputs(
        isReceiverOutput: isReceiverOutput);
    return WantsOutputs._(ffiWantsOutputs: res);
  }
}

class WantsOutputs {
  final FfiWantsOutputs _ffiWantsOutputs;
  WantsOutputs._({required ffiWantsOutputs})
      : _ffiWantsOutputs = ffiWantsOutputs;

  Future<bool> isOutputSubstitutionDisabled({hint}) {
    return _ffiWantsOutputs.isOutputSubstitutionDisabled();
  }

  Future<WantsOutputs> replaceReceiverOutputs(
      {required List<TxOut> replacementOutputs,
      required bitcoin.Script drainScript}) async {
    final res = await _ffiWantsOutputs.replaceReceiverOutputs(
        replacementOutputs: replacementOutputs, drainScript: drainScript);
    return WantsOutputs._(ffiWantsOutputs: res);
  }

  Future<WantsOutputs> substituteReceiverScript(
      {required bitcoin.Script outputScript}) async {
    final res = await _ffiWantsOutputs.substituteReceiverScript(
        outputScript: outputScript);
    return WantsOutputs._(ffiWantsOutputs: res);
  }

  Future<WantsInputs> commitOutputs() async {
    final res = await _ffiWantsOutputs.commitOutputs();
    return WantsInputs._(ffiWantsInputs: res);
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
    final res = await _ffiWantsInputs.tryPreservingPrivacy(
        candidateInputs: candidateInputs);
    return InputPair._(field0: res.field0);
  }

  Future<WantsInputs> contributeInputs(
      {required List<InputPair> replacementInputs}) async {
    final res = await _ffiWantsInputs.contributeInputs(
        replacementInputs: replacementInputs);
    return WantsInputs._(ffiWantsInputs: res);
  }

  Future<ProvisionalProposal> commitInputs() async {
    final res = await _ffiWantsInputs.commitInputs();
    return ProvisionalProposal._(field0: res.field0);
  }
}

class InputPair extends FfiInputPair {
  InputPair._({required super.field0});

  static Future<InputPair> newInstance(TxIn txin, PsbtInput psbtin) async {
    final res = await FfiInputPair.newInstance(txin: txin, psbtin: psbtin);
    return InputPair._(field0: res.field0);
  }
}

class ProvisionalProposal extends FfiProvisionalProposal {
  ProvisionalProposal._({required super.field0});

  @override
  Future<PayjoinProposal> finalizeProposal({
    required FutureOr<String> Function(String) processPsbt,
    BigInt? minFeeRateSatPerVb,
    BigInt? maxFeeRateSatPerVb,
  }) async {
    final res = await super.finalizeProposal(
      processPsbt: processPsbt,
      minFeeRateSatPerVb: minFeeRateSatPerVb,
      maxFeeRateSatPerVb: maxFeeRateSatPerVb,
    );
    return PayjoinProposal._(field0: res.field0);
  }
}

class PayjoinProposal extends FfiPayjoinProposal {
  PayjoinProposal._({required super.field0});

  @override
  Future<void> processRes(
      {required List<int> res, required ClientResponse ohttpContext}) {
    return super.processRes(ohttpContext: ohttpContext, res: res);
  }

  @override
  Future<(Request, ClientResponse)> extractReq(
      {required String ohttpRelay}) async {
    final res = await super.extractReq(ohttpRelay: ohttpRelay);
    final request = Request(
      url: await uri.Url.fromStr(res.$1.url.asString()),
      contentType: res.$1.contentType,
      body: res.$1.body,
    );
    return (request, res.$2);
  }

  @override
  Future<String> psbt({hint}) {
    return super.psbt();
  }
}
