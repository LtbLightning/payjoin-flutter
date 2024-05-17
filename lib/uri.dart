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

  ///Gets the amount in satoshis.
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
