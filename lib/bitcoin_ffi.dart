import 'dart:async';

import 'src/generated/api/bitcoin_ffi.dart';

class Script extends FfiScript {
  Script._({required super.field0});

  static Future<Script> newInstance(
      {required List<int> rawOutputScript}) async {
    final res = await FfiScript.newInstance(rawOutputScript: rawOutputScript);
    return Script._(field0: res.field0);
  }
}
