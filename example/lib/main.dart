import 'package:flutter/material.dart';

void main() async {
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
                      // final uri = await buildPjUri(10000000,
                      //     "https://testnet.demo.btcpayserver.org/BTC/pj");
                      // if (kDebugMode) {
                      //   print(await uri.address());
                      // }
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
