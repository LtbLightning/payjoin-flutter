import 'dart:convert';

import 'package:bdk_flutter/bdk_flutter.dart';
import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:payjoin_flutter/common.dart' as common;
import 'package:payjoin_flutter/send.dart';
import 'package:payjoin_flutter/uri.dart' as pay_join_uri;
import 'package:payjoin_flutter_example/bdk_client.dart';
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
  final sender = BdkClient(
      "wpkh(tprv8ZgxMBicQKsPdgsqhkRVYkBBULxG3HvyXtwhWKEgfH4bsU8bmaqhdbZvxq4Z7BLFtUrT58ynRDrBcfG3vNpNHsKTV5xCEgRoKaNNzcVW3HW/84'/1'/0'/0/*)#ln3hfgcf");
  final receiver = BdkClient(
      "wpkh(tprv8ZgxMBicQKsPfKJjrApLfm2BhWhV1JpL3StS8UPagm91Y215JGZktQKTtvErD92RKxEDYD9Sfc9eGZVkuH94NgEHPhz7rpgzhiNm2UPs1G1/84'/1'/0'/0/*)#h8uywf09");

  String displayText = "";
  String pjUri = "";
  late PartiallySignedTransaction senderPsbt;
  late String receiverPsbtBase64;
  late ContextV1 contextV1;

  @override
  void initState() {
    sender.restoreWallet();
    receiver.restoreWallet();
    setState(() {
      displayText = "sender & receiver restored";
    });
    super.initState();
  }

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
                  await sender.syncWallet();
                  await receiver.syncWallet();
                  setState(() {
                    displayText = "sync complete";
                  });
                  debugPrint(
                      "receiver balance: ${(await receiver.getBalance()).toString()}");
                  debugPrint(
                      "sender balance: ${(await sender.getBalance()).toString()}");
                },
                child: Text(
                  "Sync wallets",
                  style: GoogleFonts.manrope(
                      color: Colors.black,
                      fontSize: 14,
                      fontWeight: FontWeight.w800),
                )),
            TextButton(
                onPressed: () async {
                  final address = (await receiver.getNewAddress()).address;
                  final res = await payJoinLibrary.buildPjUri(
                      0.0083285, await address.toQrUri());
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
                final balance = await sender.getBalance();
                debugPrint("Sender Balance: ${balance.toString()}");
                final uri = await pay_join_uri.Uri.fromString(pjUri);
                final address = await uri.address();
                int amount = (((await uri.amount()) ?? 0) * 100000000).toInt();
                final psbt = (await sender.createPsbt(address, amount, 2000));
                debugPrint(
                  "\nOriginal sender psbt: ${await psbt.serialize()}",
                );

                final requestContext =
                    (await (await RequestBuilder.fromPsbtAndUri(
                            psbtBase64: await psbt.serialize(), uri: uri))
                        .buildRecommended(minFeeRate: 0));
                // In a real scenario, the sender would send the request to
                //  the payjoin endpoint of the receiver, here we just keep
                //  the context for the last step.
                final (_, ctx) = await requestContext.extractContextV1();

                setState(() {
                  senderPsbt = psbt;
                  contextV1 = ctx;
                });
              },
              child: Text(
                "Create Sender request psbt using receiver pjUri",
                style: GoogleFonts.manrope(
                    color: Colors.black,
                    fontSize: 14,
                    fontWeight: FontWeight.w800),
              ),
            ),
            TextButton(
                onPressed: () async {
                  final provisionalProposal =
                      await payJoinLibrary.handlePjRequest(
                    await senderPsbt.serialize(),
                    (e) async {
                      final script = ScriptBuf(bytes: e);

                      return (await receiver.getAddressInfo(script));
                    },
                  );
                  final unspent = await receiver.listUnspent();
                  // Select receiver payjoin inputs.
                  Map<int, common.OutPoint> candidateInputs = {
                    for (var input in unspent)
                      input.txout.value: common.OutPoint(
                          txid: input.outpoint.txid.toString(),
                          vout: input.outpoint.vout)
                  };
                  final selectedOutpoint = await provisionalProposal
                      .tryPreservingPrivacy(candidateInputs: candidateInputs);
                  var selectedUtxo = unspent.firstWhere(
                      (i) =>
                          i.outpoint.txid == selectedOutpoint.txid &&
                          i.outpoint.vout == selectedOutpoint.vout,
                      orElse: () => throw Exception('UTXO not found'));
                  var txoToContribute = common.TxOut(
                    value: selectedUtxo.txout.value,
                    scriptPubkey: selectedUtxo.txout.scriptPubkey.bytes,
                  );

                  var outpointToContribute = common.OutPoint(
                    txid: selectedUtxo.outpoint.txid.toString(),
                    vout: selectedUtxo.outpoint.vout,
                  );

                  await provisionalProposal.contributeWitnessInput(
                      txo: txoToContribute, outpoint: outpointToContribute);
                  final newReceiverAddress = await receiver.getNewAddress();
                  await provisionalProposal.substituteOutputAddress(
                      address: await newReceiverAddress.address.asString());
                  final payJoinProposal = await provisionalProposal
                      .finalizeProposal(processPsbt: (e) async {
                    debugPrint("\n Receiver response unsigned psbt: $e");
                    return await (await receiver.signPsbt(
                            await PartiallySignedTransaction.fromString(e)))
                        .serialize();
                  });
                  final receiverPsbt = await payJoinProposal.psbt();
                  debugPrint("\n Receiver response psbt: $receiverPsbt");
                  setState(() {
                    receiverPsbtBase64 = receiverPsbt;
                  });
                },
                child: Text(
                  "Create Receiver response psbt",
                  style: GoogleFonts.manrope(
                      color: Colors.black,
                      fontSize: 14,
                      fontWeight: FontWeight.w800),
                )),
            TextButton(
                onPressed: () async {
                  final processedReceiverResponsePsbt =
                      await contextV1.processResponse(
                          response: utf8.encode(receiverPsbtBase64));
                  final finalizedPsbt = (await sender.signPsbt(
                      await PartiallySignedTransaction.fromString(
                          processedReceiverResponsePsbt)));
                  debugPrint(
                      'Processed and finalized sender psbt: ${await finalizedPsbt.serialize()}');
                  final res = await sender.broadcastPsbt(finalizedPsbt);
                  debugPrint("Broadcast success: $res");
                },
                child: Text(
                  "Process response and broadcast final Sender psbt",
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
