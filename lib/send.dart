import 'package:payjoin_flutter/common.dart';
import 'package:payjoin_flutter/uri.dart';

import 'src/generated/api/send.dart';
import 'src/generated/api/uri.dart';

class SenderBuilder extends FfiSenderBuilder {
  SenderBuilder._({required super.field0});
  static Future<SenderBuilder> fromPsbtAndUri(
      {required String psbtBase64, required PjUri pjUri}) async {
    final res = await FfiSenderBuilder.fromPsbtAndUri(
        psbtBase64: psbtBase64, pjUri: pjUri);
    return SenderBuilder._(field0: res.field0);
  }

  @override
  Future<NewSender> buildWithAdditionalFee(
      {required BigInt maxFeeContribution,
      int? changeIndex,
      required BigInt minFeeRate,
      required bool clampFeeContribution}) async {
    final res = await super.buildWithAdditionalFee(
        maxFeeContribution: maxFeeContribution,
        changeIndex: changeIndex,
        minFeeRate: minFeeRate,
        clampFeeContribution: clampFeeContribution);
    return NewSender._(field0: res.field0);
  }

  @override
  Future<NewSender> buildRecommended({required BigInt minFeeRate}) async {
    final res = await super.buildRecommended(minFeeRate: minFeeRate);
    return NewSender._(field0: res.field0);
  }

  @override
  Future<NewSender> buildNonIncentivizing({required BigInt minFeeRate}) async {
    final res = await super.buildNonIncentivizing(minFeeRate: minFeeRate);
    return NewSender._(field0: res.field0);
  }

  @override
  Future<SenderBuilder> alwaysDisableOutputSubstitution() async {
    final res = await super.alwaysDisableOutputSubstitution();
    return SenderBuilder._(field0: res.field0);
  }
}

class NewSender extends FfiNewSender {
  NewSender._({required super.field0});
}

class Sender extends FfiSender {
  Sender._({required super.field0});

  static Future<Sender> load({required String token}) async {
    final res = await FfiSender.load(token: token);
    return Sender._(field0: res.field0);
  }

  @override
  Future<(Request, V1Context)> extractV1() async {
    final res = await super.extractV1();
    final request = Request(
      url: await Url.fromStr((res.$1.url.asString())),
      contentType: res.$1.contentType,
      body: res.$1.body,
    );
    return (request, V1Context._(field0: res.$2.field0));
  }

  @override
  Future<(Request, V2PostContext)> extractV2({
    required FfiUrl ohttpProxyUrl,
  }) async {
    final res = await super.extractV2(
      ohttpProxyUrl: ohttpProxyUrl,
    );
    final request = Request(
      url: await Url.fromStr((res.$1.url.asString())),
      contentType: res.$1.contentType,
      body: res.$1.body,
    );
    return (request, V2PostContext._(field0: res.$2.field0));
  }

  // toJson automatically exposed since class extends FfiSender

  static Sender fromJson(String json) {
    final res = FfiSender.fromJson(json: json);
    return Sender._(field0: res.field0);
  }
}

class V1Context extends FfiV1Context {
  V1Context._({required super.field0});
  @override
  Future<String> processResponse({required List<int> response}) {
    return super.processResponse(response: response);
  }
}

class V2PostContext extends FfiV2PostContext {
  V2PostContext._({required super.field0});
  @override
  Future<V2GetContext> processResponse({required List<int> response}) async {
    final res = await super.processResponse(response: response);
    return V2GetContext._(field0: res.field0);
  }
}

class V2GetContext extends FfiV2GetContext {
  V2GetContext._({required super.field0});

  @override
  Future<(Request, ClientResponse)> extractReq({
    required String ohttpRelay,
  }) async {
    final res = await super.extractReq(ohttpRelay: ohttpRelay);
    return (
      Request(
        url: await Url.fromStr(res.$1.url.asString()),
        contentType: res.$1.contentType,
        body: res.$1.body,
      ),
      ClientResponse(field0: res.$2.field0)
    );
  }

  @override
  Future<String?> processResponse({
    required List<int> response,
    required ClientResponse ohttpCtx,
  }) async {
    return await super.processResponse(response: response, ohttpCtx: ohttpCtx);
  }
}
