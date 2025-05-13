import 'dart:convert';
import 'dart:typed_data';

import 'package:bdk_flutter/bdk_flutter.dart' as bdk;
import 'package:flutter/widgets.dart';
import 'package:http/http.dart' as http;
import 'package:payjoin_flutter/uri.dart' as pj_uri;
import 'package:payjoin_flutter/send.dart';

class PayjoinManager {
  static const pjUrl = "https://localhost:8088";
  static const ohttpRelay = "https://pj.bobspacebkk.com";
  static const payjoinDirectory = "https://payjo.in";
  static const v1ContentType = "text/plain";
  static const v2ContentType = "message/ohttp-req";

  Future<String> buildV1PjStr(
    int amount,
    String address, {
    String? pj,
  }) async {
    try {
      final pjUri =
          "bitcoin:$address?amount=${amount / 100000000}&pj=${pj ?? pjUrl}";
      debugPrint("pjUri: : $pjUri");
      return pjUri;
    } catch (e) {
      debugPrint(e.toString());
      rethrow;
    }
  }

  Future<pj_uri.Uri> stringToUri(String pj) async {
    try {
      return await pj_uri.Uri.fromStr(pj);
    } catch (e) {
      debugPrint(e.toString());
      rethrow;
    }
  }

  Future<String> buildOriginalPsbt(
    bdk.Wallet senderWallet,
    pj_uri.Uri pjUri,
    int fee,
  ) async {
    final txBuilder = bdk.TxBuilder();
    final address = await bdk.Address.fromString(
        s: pjUri.address(), network: bdk.Network.signet);
    final script = address.scriptPubkey();
    BigInt uriAmount = pjUri.amountSats() ?? BigInt.zero;
    final (psbt, _) = await txBuilder
        .addRecipient(script, uriAmount)
        .feeAbsolute(BigInt.from(fee))
        .finish(senderWallet);
    senderWallet.sign(
      psbt: psbt,
      signOptions: const bdk.SignOptions(
        trustWitnessUtxo: true,
        allowAllSighashes: false,
        removePartialSigs: true,
        tryFinalize: true,
        signWithTapInternalKey: true,
        allowGrinding: false,
      ),
    );

    final psbtBase64 = psbt.asString();
    debugPrint('Original Sender Psbt for request: $psbtBase64');
    return psbtBase64;
  }

  Future<Sender> buildPayjoinRequest(
    String originalPsbt,
    pj_uri.Uri pjUri,
    int fee,
  ) async {
    final senderBuilder = await SenderBuilder.fromPsbtAndUri(
        psbtBase64: originalPsbt, pjUri: pjUri.checkPjSupported());
    final newSender =
        await senderBuilder.buildRecommended(minFeeRate: BigInt.from(250));
    final imp = InMemorySenderPersister();
    final persister = DartSenderPersister(
      save: (sender) async {
        return await imp.save(sender: sender);
      },
      load: (token) async {
        return await imp.load(token: token);
      },
    );
    final token = await newSender.persist(persister: persister);
    final sender = await Sender.load(token: token, persister: persister);
    return sender;
  }

  Future<String> requestAndPollV2Proposal(
    Sender sender,
  ) async {
    debugPrint('Sending V2 Proposal Request...');
    try {
      // Extract the request and context once
      final (request, postCtx) = await sender.extractV2(
        ohttpProxyUrl: await pj_uri.Url.fromStr(ohttpRelay),
      );

      // Post the request to the server
      final response = await http.post(
        Uri.parse(request.url.asString()),
        headers: {
          'Content-Type': v2ContentType,
        },
        body: request.body,
      );

      // Process the server response to get the context
      final getCtx =
          await postCtx.processResponse(response: response.bodyBytes);

      // Loop to extract (request, ctx) from get_ctx
      while (true) {
        debugPrint('Polling for V2 Proposal...');
        try {
          final (getReq, ohttpCtx) = await getCtx.extractReq(
            ohttpRelay: ohttpRelay,
          );

          // Post the loop request to the server
          final loopResponse = await http.post(
            Uri.parse(getReq.url.asString()),
            headers: {
              'Content-Type': v2ContentType,
            },
            body: getReq.body,
          );

          // Process the loop response
          final proposal = await getCtx.processResponse(
              response: loopResponse.bodyBytes, ohttpCtx: ohttpCtx);

          // If a valid proposal is received, return it
          if (proposal != null) {
            debugPrint('Received V2 proposal: $proposal');
            return proposal;
          }

          debugPrint('No valid proposal received, retrying after 2 seconds...');

          // Add a delay to avoid spamming the server with requests
          await Future.delayed(const Duration(seconds: 2));
        } catch (e) {
          // If the session times out or another error occurs, rethrow the error
          rethrow;
        }
      }
    } catch (e) {
      // If the initial request fails, rethrow the error
      rethrow;
    }
  }

  // Future<(bdk.Transaction originalTx, receive.PayjoinProposal)> handleV2Request(
  //   receive.UncheckedProposal uncheckedProposal,
  //   bdk.Wallet receiverWallet,
  // ) async {
  //   final (originalTx, payjoinProposal) = await _handleV2Request(
  //     proposal: uncheckedProposal,
  //     receiverWallet: receiverWallet,
  //   );
  //   final (proposalReq, proposalCtx) = await payjoinProposal.extractV2Req();
  //   final res = await http.post(
  //     Uri.parse(proposalReq.url.asString()),
  //     body: proposalReq.body,
  //     headers: {
  //       'Content-Type': v2ContentType,
  //     },
  //   );
  //   await payjoinProposal.processRes(
  //     res: res.bodyBytes,
  //     ohttpContext: proposalCtx,
  //   );

  //   return (originalTx, payjoinProposal);
  // }

  Future<String> getTxIdFromPsbt(
    String psbtBase64,
  ) async {
    final psbt = await bdk.PartiallySignedTransaction.fromString(psbtBase64);
    final txId = psbt.extractTx().txid();
    return txId;
  }

  Future<String> processV1Proposal(
    Sender sender,
    String proposalPsbt,
  ) async {
    final (_, ctx) = await sender.extractV1();
    final checkedProposal =
        await ctx.processResponse(response: utf8.encode(proposalPsbt));
    debugPrint('Processed Response: $checkedProposal');
    return checkedProposal;
  }

  // Future<String> processV2Proposal(
  //   send.Sender sender,
  //   String proposalPsbt,
  // ) async {
  //   final (_, ctx) = await sender.extractV2(
  //     ohttpProxyUrl: await pj_uri.Url.fromStr(payjoinDirectory),
  //   );
  //   final checkedProposal =
  //       await ctx.processResponse(response: utf8.encode(proposalPsbt));
  //   debugPrint('Processed Response: $checkedProposal');
  //   return checkedProposal!; // Since this is called after the original request, the response should not be null
  // }

  Future<bdk.Transaction> extractPjTx(
      bdk.Wallet senderWallet, String psbtString) async {
    final psbt = await bdk.PartiallySignedTransaction.fromString(psbtString);
    debugPrint('PSBT before: ${psbt.toString()}');
    senderWallet.sign(
        psbt: psbt,
        signOptions: const bdk.SignOptions(
            trustWitnessUtxo: true,
            allowAllSighashes: false,
            removePartialSigs: true,
            tryFinalize: true,
            signWithTapInternalKey: true,
            allowGrinding: false));
    debugPrint('PSBT after: ${psbt.toString()}');
    var transaction = psbt.extractTx();
    return transaction;
  }

  // Future<(bdk.Transaction originalTx, receive.PayjoinProposal)>
  //     _handleV2Request({
  //   required receive.UncheckedProposal proposal,
  //   required bdk.Wallet receiverWallet,
  // }) async {
  //   try {
  //     final originalTxBytes = await proposal.extractTxToScheduleBroadcast();
  //     final originalTx =
  //         await bdk.Transaction.fromBytes(transactionBytes: originalTxBytes);

  //     final ownedInputs =
  //         await proposal.checkBroadcastSuitability(canBroadcast: (e) async {
  //       return true;
  //     });
  //     final seenInputs = await ownedInputs.checkInputsNotOwned(
  //         isOwned: (i) => _isOwned(i, receiverWallet));
  //     final wantsInputs =
  //         await (await seenInputs.checkNoInputsSeenBefore(isKnown: (e) async {
  //       return false;
  //     }))
  //             .identifyReceiverOutputs(
  //       isReceiverOutput: (i) => _isOwned(i, receiverWallet),
  //     );

  //     final availableInputs = receiverWallet.listUnspent();
  //     Map<BigInt, types.OutPoint> candidateInputs = {
  //       for (var input in availableInputs)
  //         input.txout.value: types.OutPoint(
  //           txid: input.outpoint.txid.toString(),
  //           vout: input.outpoint.vout,
  //         )
  //     };
  //     final selectedOutpoint = await wantsInputs.tryPreservingPrivacy(
  //       candidateInputs: candidateInputs,
  //     );
  //     var selectedUtxo = availableInputs.firstWhere(
  //         (i) =>
  //             i.outpoint.txid == selectedOutpoint.txid &&
  //             i.outpoint.vout == selectedOutpoint.vout,
  //         orElse: () => throw Exception('UTXO not found'));
  //     var txoToContribute = types.TxOut(
  //       value: selectedUtxo.txout.value,
  //       scriptPubkey: selectedUtxo.txout.scriptPubkey.bytes,
  //     );

  //     var outpointToContribute = types.OutPoint(
  //       txid: selectedUtxo.outpoint.txid.toString(),
  //       vout: selectedUtxo.outpoint.vout,
  //     );
  //     await wantsInputs.contributeWitnessInput(
  //       txo: txoToContribute,
  //       outpoint: outpointToContribute,
  //     );

  //     /* PjUri is generated with pjos=0, so no output substitution is permitted
  //     await payjoin.trySubstituteReceiverOutput(
  //         generateScript: () async => receiverWallet
  //             .getAddress(addressIndex: const bdk.AddressIndex.increase())
  //             .address
  //             .scriptPubkey()
  //             .bytes);*/
  //     final payjoinProposal = await wantsInputs.finalizeProposal(
  //         processPsbt: (i) => _processPsbt(i, receiverWallet));
  //     return (originalTx, payjoinProposal);
  //   } on Exception catch (e) {
  //     debugPrint(e.toString());
  //     rethrow;
  //   }
  // }

  Future<bool> _isOwned(Uint8List bytes, bdk.Wallet wallet) async {
    final script = bdk.ScriptBuf(bytes: bytes);
    return wallet.isMine(script: script);
  }

  Future<String> processPsbt(String preProcessed, bdk.Wallet wallet) async {
    final psbt = await bdk.PartiallySignedTransaction.fromString(preProcessed);
    debugPrint('PSBT before: ${psbt.toString()}');
    wallet.sign(
      psbt: psbt,
      signOptions: const bdk.SignOptions(
        trustWitnessUtxo: true,
        allowAllSighashes: false,
        removePartialSigs: true,
        tryFinalize: true,
        signWithTapInternalKey: true,
        allowGrinding: false,
      ),
    );
    debugPrint('PSBT after: ${psbt.toString()}');
    return psbt.asString();
  }
}

/// A simple in-memory implementation of the `SenderPersister` interface.
/// This class stores the sender data in memory and allows saving and loading
/// of `FfiSender` instances using a token as a key.
class InMemorySenderPersister implements DartSenderPersister {
  final Map<String, Sender> _store = {};

  Future<SenderToken> save({required Sender sender}) async {
    final token = sender.key();
    debugPrint('TOKEN SAVE: ${token.toBytes()}');
    _store[token.toBytes().toString()] = sender;
    return token;
  }

  Future<Sender> load({required SenderToken token}) async {
    debugPrint('TOKEN LOAD: ${token.toBytes()}');
    final sender = _store[token.toBytes().toString()];
    if (sender == null) {
      throw Exception('Sender not found for the provided token.');
    }
    return sender;
  }

  @override
  void dispose() {
    _store.clear();
  }

  @override
  bool get isDisposed => _store.isEmpty;
}
