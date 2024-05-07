import 'dart:convert';

import 'package:bdk_flutter/bdk_flutter.dart';
import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:payjoin_flutter/common.dart' as common;
import 'package:payjoin_flutter/uri.dart' as pay_join_uri;
import 'package:payjoin_flutter_example/btc_client.dart';
import 'package:payjoin_flutter_example/payjoin_library.dart';

void main() async {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  @override
  void initState() {
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
        debugShowCheckedModeBanner: false, home: PayJoin());
  }
}

class PayJoin extends StatefulWidget {
  const PayJoin({super.key});

  @override
  State<PayJoin> createState() => _PayJoinState();
}

class _PayJoinState extends State<PayJoin> {
  static const primaryColor = 0xffC71585;
  PayJoinLibrary payJoinLibrary = PayJoinLibrary();
  BtcClient senderRpc = BtcClient("sender");
  BtcClient receiverRpc = BtcClient("receiver");

  String displayText = "";
  String pjUri = "";
  String senderPsbt = "";
  String processedAndFinalizedPsbt = "";
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color(primaryColor),
        elevation: 0,
        centerTitle: false,
        title: Text('PayJoin App',
            style: GoogleFonts.ibmPlexMono(
                fontWeight: FontWeight.w900,
                fontSize: 18,
                color: Colors.white)), // Set this heigh
      ),
      body: SingleChildScrollView(
        child: Column(
          children: [
            Container(
              margin: const EdgeInsets.only(bottom: 50),
              padding: const EdgeInsets.only(left: 15, right: 15, bottom: 20),
              color: const Color(primaryColor),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.start,
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text("Response: ",
                      textAlign: TextAlign.center,
                      style: GoogleFonts.manrope(
                          color: Colors.white,
                          fontSize: 12,
                          fontWeight: FontWeight.w700)),
                  Expanded(
                    child: SelectableText(
                      displayText,
                      maxLines: 3,
                      textAlign: TextAlign.start,
                      style: GoogleFonts.ibmPlexMono(
                          color: Colors.white,
                          fontSize: 12,
                          fontWeight: FontWeight.w700),
                    ),
                  ),
                ],
              ),
            ),
            TextButton(
                onPressed: () async {
                  await senderRpc.loadWallet();
                  await receiverRpc.loadWallet();
                },
                child: Text(
                  "Init Sender & Receiver",
                  style: GoogleFonts.manrope(
                      color: Colors.black,
                      fontSize: 14,
                      fontWeight: FontWeight.w800),
                )),
            TextButton(
                onPressed: () async {
                  final address = await receiverRpc.getNewAddress();
                  final res =
                      await payJoinLibrary.buildPjUri(0.0083285, address);
                  setState(() {
                    pjUri = res;
                    displayText = res;
                  });
                },
                child: Text(
                  "Build Receiver pj Uri",
                  style: GoogleFonts.manrope(
                      color: Colors.black,
                      fontSize: 14,
                      fontWeight: FontWeight.w800),
                )),
            TextButton(
                onPressed: () async {
                  final balance = await senderRpc.getBalance();
                  debugPrint("Sender Balance: ${balance.toString()}");
                  final uri = await pay_join_uri.Uri.fromString(pjUri);
                  final address = await uri.address();
                  final amount = await uri.amount();
                  final psbt = (await senderRpc.walletCreateFundedPsbt(
                      amount, address, 2000))["psbt"];
                  debugPrint(
                    "\nOriginal sender psbt: $psbt",
                  );
                  setState(() {
                    senderPsbt = psbt;
                  });
                },
                child: Text(
                  "Create Sender psbt using receiver pjUri",
                  style: GoogleFonts.manrope(
                      color: Colors.black,
                      fontSize: 14,
                      fontWeight: FontWeight.w800),
                )),
            TextButton(
                onPressed: () async {
                  final (provisionalProposal, contextV1) = await payJoinLibrary
                      .handlePjRequest(senderPsbt, pjUri, (e) async {
                    final script = ScriptBuf(bytes: e);
                    final address = await (await Address.fromScript(
                            script: script, network: Network.regtest))
                        .asString();
                    return (await receiverRpc
                        .getAddressInfo(address))["ismine"];
                  });
                  final availableInputs = await receiverRpc.listUnspent([]);
                  // Select receiver payjoin inputs.
                  Map<int, common.OutPoint> candidateInputs = {};
                  for (var e in availableInputs) {
                    int amount = (e["amount"] * 100000000).toInt();
                    candidateInputs[amount] =
                        common.OutPoint(txid: e["txid"], vout: e["vout"]);
                  }
                  final selectedOutpoint = await provisionalProposal
                      .tryPreservingPrivacy(candidateInputs: candidateInputs);

                  final selectedUtxo = availableInputs.firstWhere((e) =>
                      (e["txid"] == selectedOutpoint.txid) &&
                      (e["vout"] == selectedOutpoint.vout));
                  final selectedUtxoScriptPubKey =
                      await ScriptBuf.fromHex(selectedUtxo["scriptPubKey"]);
                  int selectedUtxoAmount =
                      (selectedUtxo["amount"] * 100000000).toInt();
                  final txoutToContribute = common.TxOut(
                    scriptPubkey: selectedUtxoScriptPubKey.bytes,
                    value: selectedUtxoAmount,
                  );
                  final outputToContribute = common.OutPoint(
                      txid: selectedUtxo["txid"], vout: selectedUtxo["vout"]);
                  await provisionalProposal.contributeWitnessInput(
                      txo: txoutToContribute, outpoint: outputToContribute);
                  final newReceiverAddress = await receiverRpc.getNewAddress();
                  await provisionalProposal.substituteOutputAddress(
                      address: newReceiverAddress);
                  final payJoinProposal = await provisionalProposal
                      .finalizeProposal(processPsbt: (e) async {
                    return (await receiverRpc.walletProcessPsbt(e))["psbt"];
                  });
                  final receiverPsbt = await payJoinProposal.psbt();
                  debugPrint("\n Original receiver psbt: $receiverPsbt");
                  final receiverProcessedPsbt = await contextV1.processResponse(
                      response: utf8.encode(receiverPsbt));
                  final senderProcessedPsbt = (await senderRpc
                      .walletProcessPsbt(receiverProcessedPsbt))["psbt"];
                  final senderFinalizedPsbt =
                      (await senderRpc.finalizePsbt(senderProcessedPsbt));
                  setState(() {
                    processedAndFinalizedPsbt = senderFinalizedPsbt["hex"];
                  });
                },
                child: Text(
                  "Process and finalize receiver Pj request",
                  style: GoogleFonts.manrope(
                      color: Colors.black,
                      fontSize: 14,
                      fontWeight: FontWeight.w800),
                )),
            TextButton(
                onPressed: () async {
                  final res = await senderRpc
                      .sendRawTransaction(processedAndFinalizedPsbt);
                  debugPrint("Broadcast success: $res");
                },
                child: Text(
                  "Broadcast processed psbt",
                  style: GoogleFonts.manrope(
                      color: Colors.black,
                      fontSize: 14,
                      fontWeight: FontWeight.w800),
                ))
          ],
        ),
      ),
    );
  }
}
