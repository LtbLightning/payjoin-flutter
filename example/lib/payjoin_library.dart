import 'package:flutter/cupertino.dart';
import 'package:payjoin_flutter/common.dart';
import 'package:payjoin_flutter/receive/v1.dart' as v1;
import 'package:payjoin_flutter/uri.dart' as uri;

class PayjoinLibrary {
  static const pjUrl = "https://localhost:8088";
  static const ohRelay = "https://localhost:8088";
  static const localCertFile = "localhost.der";
  Future<uri.Uri> buildPjUri(double amount, String address, String pj) async {
    try {
      final pjUri = "bitcoin:$address?amount=${amount / 100000000.0}&pj=$pj";
      return await uri.Uri.fromString(pjUri);
    } catch (e) {
      debugPrint(e.toString());
      rethrow;
    }
  }

  handlePjRequest(Request req, Headers headers) async {
    final _ = await v1.UncheckedProposal.fromRequest(
        body: req.body.toList(),
        query: (await req.url.query())!,
        headers: headers);
  }

  handleProposal(v1.UncheckedProposal proposal) async {
    try {
      final _ = await proposal.extractTxToScheduleBroadcast();
    } on Exception catch (e) {
      debugPrint(e.toString());
    }
  }
}
