import 'package:payjoin_flutter/src/config.dart';
import 'package:payjoin_flutter/src/exceptions.dart';

import 'src/generated/api/uri.dart' as generated;
import 'src/generated/utils/error.dart' as error;

class Uri extends generated.Uri {
  Uri._({required super.field0});

  static Future<Uri> fromString(String uri) async {
    try {
      await PConfig.initializeApp();
      final res = await generated.Uri.fromStr(uri: uri);
      return Uri._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  ///Gets the amount in btc.
  @override
  Future<double?> amount({hint}) {
    try {
      return super.amount();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<String> address({hint}) {
    try {
      return super.address();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class Url extends generated.Url {
  Url._({required super.field0});
  static Future<Url> fromString(String uri) async {
    try {
      await PConfig.initializeApp();
      final res = await generated.Url.fromStr(url: uri);
      return Url._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<String?> query({hint}) {
    try {
      return super.query();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<String> asString({hint}) {
    try {
      return super.asString();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

///The key configuration of a server. This can be used by both client and server.
///An important invariant of this structure is that it does not include any combination of KEM, KDF, and AEAD that is not supported.
class OhttpKeys extends generated.OhttpKeys {
  OhttpKeys._({required super.field0});

  ///Construct a configuration from the encoded server configuration.
  static Future<OhttpKeys> decode({required List<int> bytes}) async {
    try {
      final res = await generated.OhttpKeys.decode(bytes: bytes);
      return OhttpKeys._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}
