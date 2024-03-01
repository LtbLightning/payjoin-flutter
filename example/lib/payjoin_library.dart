import 'package:flutter/cupertino.dart';
import 'package:payjoin_flutter/payjoin.dart';

class PayjoinLibrary {
  static const PJ_URL = "https://localhost:8088";
  static const OH_RELAY = "https://localhost:8088";
  static const LOCAL_CERT_FILE = "localhost.der";
  Future<Uri> buildPjUri(double amount, String address, String pj) async {
    try {
      final pjUri = "bitcoin:$address?amount=${amount / 100000000.0}&pj=$pj";
      return await Uri.fromStr(uri: pjUri);
    } catch (e) {
      debugPrint(e.toString());
      rethrow;
    }
  }
}
