import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:payjoin_flutter/payjoin.dart';

void main() async {
  await Payjoin.initialize();
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  // BdkLibrary lib = BdkLibrary();
  // late Wallet aliceWallet;
  // Blockchain? blockchain;
  @override
  void initState() {
    super.initState();
  }

  Future<Uri> buildPjUri(double amount, String pj) async {
    try {
      // final address = await aliceWallet.getAddress(
      //     addressIndex: const AddressIndex.increase());
      // final qUriAddress = await (await Address.fromString(
      //         s: address.address, network: Network.testnet))
      //     .toQrUri();
      final pjUri =
          "tb1q5tsjcyz7xmet07yxtumakt739y53hcttmntajq?amount=${amount / 100000000.0}&pj=$pj";
      return await Uri.fromStr(uri: pjUri);
    } catch (e) {
      debugPrint(e.toString());
      rethrow;
    }
  }

  Future<RequestContextV1> buildRequestBuilder(String psbt, Uri uri) async {
    try {
      final res = await (await RequestBuilder.fromPsbtAndUri(
              psbtBase64: psbt, uri: uri))
          .buildWithAdditionalFee(
              maxFeeContribution: 10000,
              minFeeRate: 1,
              clampFeeContribution: false);
      return (await res.extractV1());
    } catch (e) {
      debugPrint(e.toString());
      rethrow;
    }
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Payjoin Example App'),
        ),
        body: SingleChildScrollView(
          child: Container(
            padding: const EdgeInsets.all(10),
            child: Column(
              children: [
                TextButton(
                    onPressed: () async {
                      final uri = await buildPjUri(10000000,
                          "https://testnet.demo.btcpayserver.org/BTC/pj");
                      if (kDebugMode) {
                        print(await uri.address());
                      }
                    },
                    child: const Text("Build PjUri"))
              ],
            ),
          ),
        ),
      ),
    );
  }
}
