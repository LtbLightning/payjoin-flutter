import 'package:payjoin_flutter/src/config.dart';
import 'package:payjoin_flutter/src/exceptions.dart';

import 'src/generated/api/io.dart' as io;
import 'src/generated/api/uri.dart';
import 'src/generated/utils/error.dart' as error;

class PjUriBuilder extends FfiPjUriBuilder {
  PjUriBuilder({required super.internal});

  @override
  PjUriBuilder amountSats({required BigInt amount}) {
    try {
      final res = super.amountSats(amount: amount);
      return PjUriBuilder(internal: res.internal);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  PjUriBuilder label({required String label}) {
    try {
      final res = super.label(label: label);
      return PjUriBuilder(internal: res.internal);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  PjUriBuilder message({required String message}) {
    try {
      final res = super.message(message: message);
      return PjUriBuilder(internal: res.internal);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  PjUriBuilder pjos({required bool pjos}) {
    try {
      final res = super.pjos(pjos: pjos);
      return PjUriBuilder(internal: res.internal);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  PjUri build() {
    try {
      final res = super.build();
      return PjUri._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class Uri extends FfiUri {
  Uri._({required super.field0});

  static Future<Uri> fromStr(String uri) async {
    try {
      await PConfig.initializeApp();
      final res = FfiUri.parse(uri: uri);
      return Uri._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  ///Gets the amount in btc.
  @override
  BigInt? amountSats({hint}) {
    try {
      return super.amountSats();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  String address({hint}) {
    try {
      return super.address();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  PjUri checkPjSupported({hint}) {
    try {
      return PjUri._(field0: super.checkPjSupported().field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class PjUri extends FfiPjUri {
  PjUri._({required super.field0});

  ///Gets the amount in btc.
  @override
  BigInt? amountSats({hint}) {
    try {
      return super.amountSats();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  String address({hint}) {
    try {
      return super.address();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  String pjEndpoint({hint}) {
    try {
      return super.pjEndpoint();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class Url extends FfiUrl {
  Url._({required super.field0});
  static Future<Url> fromStr(String uri) async {
    try {
      await PConfig.initializeApp();
      final res = FfiUrl.parse(url: uri);
      return Url._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  String? query({hint}) {
    try {
      return super.query();
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

///The key configuration of a server. This can be used by both client and server.
///An important invariant of this structure is that it does not include any combination of KEM, KDF, and AEAD that is not supported.
class OhttpKeys extends FfiOhttpKeys {
  OhttpKeys._({required super.field0});

  ///Construct a configuration from the encoded server configuration.
  static Future<OhttpKeys> decode({required List<int> bytes}) async {
    try {
      final res = await FfiOhttpKeys.decode(bytes: bytes);
      return OhttpKeys._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

/// Fetch the ohttp keys from the specified payjoin directory via proxy.
///
/// * `ohttpRelay`: The http CONNNECT method proxy to request the ohttp keys from a payjoin
/// directory.  Proxying requests for ohttp keys ensures a client IP address is never revealed to
/// the payjoin directory.
///
/// * `payjoinDirectory`: The payjoin directory from which to fetch the ohttp keys.  This
/// directory stores and forwards payjoin client payloads.
///
/// * `certDer` (optional): The DER-encoded certificate to use for local HTTPS connections.  This
/// parameter is only available when the "_danger-local-https" feature is enabled.
Future<OhttpKeys> fetchOhttpKeys({
  required Url ohttpRelay,
  required Url payjoinDirectory,
}) async {
  try {
    final res = await io.fetchOhttpKeys(
      ohttpRelay: ohttpRelay,
      payjoinDirectory: payjoinDirectory,
    );
    return OhttpKeys._(field0: res.field0);
  } on error.PayjoinError catch (e) {
    throw mapPayjoinError(e);
  }
}
