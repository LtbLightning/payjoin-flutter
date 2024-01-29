import 'package:flutter/cupertino.dart';

import 'generated/frb_generated.dart';

class Payjoin {
  static Future<void> initialize() async {
    try {
      await RustLib.init();
    } catch (e) {
      debugPrint(e.toString());
      throw Exception(
          "Failed to initialize payjoin: Ensure that Payjoin.initialize() is called and awaited (if in an async environment) before using Payjoin service.");
    }
  }
}
