import 'package:bdk_flutter_demo/screens/home.dart';
import 'package:bdk_flutter_demo/styles/theme.dart';
import 'package:flutter/material.dart';
import 'package:payjoin_flutter/common.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    PConfig.initializeApp();
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Payjoin Flutter Demo',
      theme: theme(),
      home: const Home(),
    );
  }
}
