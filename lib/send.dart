import 'package:payjoin_flutter/src/config.dart';
import 'package:payjoin_flutter/src/exceptions.dart';
import 'package:payjoin_flutter/uri.dart';

import 'common.dart' as common;
import 'src/generated/api/send.dart';
import 'src/generated/utils/error.dart' as error;

class RequestBuilder extends FfiRequestBuilder {
  RequestBuilder._({required super.field0});
  static Future<RequestBuilder> fromPsbtAndUri(
      {required String psbtBase64, required PjUri pjUri}) async {
    try {
      await PConfig.initializeApp();
      final res = await FfiRequestBuilder.fromPsbtAndUri(
          psbtBase64: psbtBase64, pjUri: pjUri);
      return RequestBuilder._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<RequestContext> buildWithAdditionalFee(
      {required BigInt maxFeeContribution,
      int? changeIndex,
      required BigInt minFeeRate,
      required bool clampFeeContribution}) async {
    try {
      final res = await super.buildWithAdditionalFee(
          maxFeeContribution: maxFeeContribution,
          changeIndex: changeIndex,
          minFeeRate: minFeeRate,
          clampFeeContribution: clampFeeContribution);
      return RequestContext._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<RequestContext> buildRecommended(
      {required BigInt minFeeRate, hBigInt}) async {
    try {
      final res = await super.buildRecommended(minFeeRate: minFeeRate);
      return RequestContext._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<RequestContext> buildNonIncentivizing(
      {required BigInt minFeeRate}) async {
    try {
      final res = await super.buildNonIncentivizing(minFeeRate: minFeeRate);
      return RequestContext._(field0: res.field0);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  @override
  Future<FfiRequestBuilder> alwaysDisableOutputSubstitution(
      {required bool disable, hBigInt}) async {
    try {
      return await super.alwaysDisableOutputSubstitution(disable: disable);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class RequestContext extends FfiRequestContext {
  RequestContext._({required super.field0});

  Future<(common.Request, ContextV1)> extractContextV1() async {
    try {
      final res = await FfiRequestContext.extractV1(ptr: this);
      final request = common.Request(
          await Url.fromString((res.request.$1.asString())), res.request.$2);
      return (request, ContextV1._(field0: res.contextV1.field0));
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }

  Future<(common.Request, ContextV2)> extractContextV2(
      Url ohttpProxyUrl) async {
    try {
      final res = await FfiRequestContext.extractV2(
          ohttpProxyUrl: ohttpProxyUrl, ptr: this);
      final request = common.Request(
          await Url.fromString((res.request.$1.asString())), res.request.$2);
      return (request, ContextV2._(field0: res.contextV2.field0));
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class ContextV1 extends FfiContextV1 {
  ContextV1._({required super.field0});
  @override
  Future<String> processResponse({required List<int> response}) {
    try {
      return super.processResponse(response: response);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}

class ContextV2 extends FfiContextV2 {
  ContextV2._({required super.field0});
  @override
  Future<String?> processResponse({required List<int> response}) {
    try {
      return super.processResponse(response: response);
    } on error.PayjoinError catch (e) {
      throw mapPayjoinError(e);
    }
  }
}
