import 'package:flutter/cupertino.dart';
import 'package:payjoin_flutter/payjoin.dart';

import 'generated/frb_generated.dart';

class UriW extends Uri {
  UriW({required super.field0});
}

class Payjoin {
  static Future<void> initialize() async {
    try {
      if (!PayjoinCore.instance.initialized) {
        await PayjoinCore.init();
      }
    } catch (e) {
      debugPrint(e.toString());
      throw Exception(
          "Failed to initialize payjoin: Ensure that Payjoin.initialize() is called and awaited (if in an async environment) before using Payjoin service.");
    }
  }
}
