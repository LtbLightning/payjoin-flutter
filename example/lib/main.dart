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
  @override
  void initState() {
    super.initState();
  }

  Future<Uri> buildPjUri(double amount, String address, String pj) async {
    try {
      final pjUri = "bitcoin:$address?amount=${amount / 100000000.0}&pj=$pj";
      return await Uri.fromStr(uri: pjUri);
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
                      final uri = await buildPjUri(
                          10000000,
                          "12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX",
                          "https://testnet.demo.btcpayserver.org/BTC/pj");
                      print(await uri.address());
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
