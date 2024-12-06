import 'dart:async';

import 'src/exceptions.dart';
import 'src/generated/api/bitcoin_ffi.dart';
import 'src/generated/utils/error.dart' as error;

class Script extends FfiScript {
  Script._({required super.field0});

  static Future<Script> newInstance(
      {required List<int> rawOutputScript}) async {
    try {
      final res = await FfiScript.newInstance(rawOutputScript: rawOutputScript);
      return Script._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}
