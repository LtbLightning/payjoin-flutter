import 'src/generated/api/io.dart' as io;
import 'src/generated/api/uri.dart';

class Uri extends FfiUri {
  Uri._({required super.field0});

  static Future<Uri> fromStr(String uri) async {
    final res = FfiUri.parse(uri: uri);
    return Uri._(field0: res.field0);
  }

  ///Gets the amount in btc.
  @override
  BigInt? amountSats({hint}) {
    return super.amountSats();
  }

  @override
  String address({hint}) {
    return super.address();
  }

  @override
  PjUri checkPjSupported({hint}) {
    return PjUri._(field0: super.checkPjSupported().field0);
  }
}

class PjUri extends FfiPjUri {
  PjUri._({required super.field0});

  ///Gets the amount in btc.
  @override
  BigInt? amountSats({hint}) {
    return super.amountSats();
  }

  @override
  String address({hint}) {
    return super.address();
  }

  @override
  String pjEndpoint({hint}) {
    return super.pjEndpoint();
  }
}

class Url extends FfiUrl {
  Url._({required super.field0});
  static Future<Url> fromStr(String uri) async {
    final res = FfiUrl.parse(url: uri);
    return Url._(field0: res.field0);
  }

  @override
  String? query({hint}) {
    return super.query();
  }
}

///The key configuration of a server. This can be used by both client and server.
///An important invariant of this structure is that it does not include any combination of KEM, KDF, and AEAD that is not supported.
class OhttpKeys extends FfiOhttpKeys {
  OhttpKeys._({required super.field0});

  ///Construct a configuration from the encoded server configuration.
  static Future<OhttpKeys> decode({required List<int> bytes}) async {
    final res = await FfiOhttpKeys.decode(bytes: bytes);
    return OhttpKeys._(field0: res.field0);
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
  required String ohttpRelay,
  required String payjoinDirectory,
}) async {
  final res = await io.fetchOhttpKeys(
    ohttpRelay: ohttpRelay,
    payjoinDirectory: payjoinDirectory,
  );
  return OhttpKeys._(field0: res.field0);
}
