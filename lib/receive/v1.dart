import 'dart:async';

import 'package:flutter_rust_bridge/flutter_rust_bridge_for_generated.dart';

import '../common.dart' as common;
import '../common.dart';
import '../src/config.dart';
import '../src/exceptions.dart';
import '../src/generated/api/receive.dart' as receive;
import '../src/generated/utils/error.dart' as error;

class UncheckedProposal extends receive.UncheckedProposal {
  UncheckedProposal._({required super.field0});
  static Future<UncheckedProposal> fromRequest({
    required List<int> body,
    required String query,
    required common.Headers headers,
  }) async {
    try {
      await PConfig.initializeApp();
      final res = await receive.UncheckedProposal.fromRequest(
          body: body, query: query, headers: headers);
      return UncheckedProposal._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

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
  Future<MaybeInputsOwned> checkBroadcastSuitability(
      {int? minFeeRate,
      required FutureOr<bool> Function(Uint8List) canBroadcast,
      hint}) async {
    try {
      final res = await receive.UncheckedProposal.checkBroadcastSuitability(
          minFeeRate: minFeeRate, canBroadcast: canBroadcast, ptr: this);
      return MaybeInputsOwned._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  ///Call this method if the only way to initiate a Payjoin with this receiver requires manual intervention, as in most consumer wallets.
  /// So-called “non-interactive” receivers, like payment processors,
  /// that allow arbitrary requests are otherwise vulnerable to probing attacks. Those receivers call gettransactiontocheckbroadcast() and attesttestedandscheduledbroadcast() after making those checks downstream
  Future<MaybeInputsOwned> assumeInteractiveReceiver() async {
    try {
      final res =
          await receive.UncheckedProposal.assumeInteractiveReceiver(ptr: this);
      return MaybeInputsOwned._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class MaybeInputsOwned extends receive.MaybeInputsOwned {
  MaybeInputsOwned._({required super.field0});
  Future<MaybeMixedInputScripts> checkInputsNotOwned(
      {required FutureOr<bool> Function(Uint8List) isOwned}) async {
    try {
      final res = await receive.MaybeInputsOwned.checkInputsNotOwned(
          ptr: this, isOwned: isOwned);
      return MaybeMixedInputScripts._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class MaybeMixedInputScripts extends receive.MaybeMixedInputScripts {
  MaybeMixedInputScripts._({required super.field0});

  /// Verify the original transaction did not have mixed input types Call this after checking downstream.
  ///
  /// Note: mixed spends do not necessarily indicate distinct wallet fingerprints. This check is intended to prevent some types of wallet fingerprinting.
  Future<MaybeInputsSeen> checkNoMixedInputScripts() async {
    try {
      final res = await receive.MaybeMixedInputScripts.checkNoMixedInputScripts(
          ptr: this);
      return MaybeInputsSeen._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class MaybeInputsSeen extends receive.MaybeInputsSeen {
  MaybeInputsSeen._({required super.field0});
  Future<OutputsUnknown> checkNoInputsSeenBefore(
      {required FutureOr<bool> Function(OutPoint) isKnown}) async {
    try {
      final res = await receive.MaybeInputsSeen.checkNoInputsSeenBefore(
          ptr: this, isKnown: isKnown);
      return OutputsUnknown._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class OutputsUnknown extends receive.OutputsUnknown {
  OutputsUnknown._({required super.field0});
  Future<ProvisionalProposal> identifyReceiverOutputs(
      {required Future<bool> Function(Uint8List) isReceiverOutput}) async {
    try {
      final res = await receive.OutputsUnknown.identifyReceiverOutputs(
          ptr: this, isReceiverOutput: isReceiverOutput);
      return ProvisionalProposal._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class ProvisionalProposal extends receive.ProvisionalProposal {
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
      {required List<int> tx, required common.OutPoint outpoint, hint}) {
    try {
      return super.contributeNonWitnessInput(tx: tx, outpoint: outpoint);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<void> contributeWitnessInput(
      {required common.TxOut txo, required common.OutPoint outpoint, hint}) {
    try {
      return super.contributeWitnessInput(txo: txo, outpoint: outpoint);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  /// Select receiver input such that the payJoin avoids surveillance. Return the input chosen that has been applied to the Proposal.
  ///
  /// Proper coin selection allows common.dart to resemble ordinary transactions. To ensure the resemblance, a number of heuristics must be avoided.
  ///
  /// UIH “Unnecessary input heuristic” is one class of them to avoid. We define UIH1 and UIH2 according to the BlockSci practice BlockSci UIH1 and UIH2:
  @override
  Future<common.OutPoint> tryPreservingPrivacy(
      {required Map<int, common.OutPoint> candidateInputs, hint}) {
    try {
      return super.tryPreservingPrivacy(candidateInputs: candidateInputs);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<PayjoinProposal> finalizeProposal(
      {required FutureOr<String> Function(String) processPsbt,
      int? minFeeRateSatPerVb}) async {
    try {
      final res = await receive.ProvisionalProposal.finalizeProposal(
          processPsbt: processPsbt,
          minFeerateSatPerVb: minFeeRateSatPerVb,
          ptr: this);
      return PayjoinProposal._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class PayjoinProposal extends receive.PayjoinProposal {
  PayjoinProposal._({required super.field0});

  @override
  Future<bool> isOutputSubstitutionDisabled({hint}) {
    try {
      return super.isOutputSubstitutionDisabled();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<Uint64List> ownedVouts({hint}) async {
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
  Future<List<common.OutPoint>> utxosToBeLocked({hint}) {
    try {
      return super.utxosToBeLocked();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}
