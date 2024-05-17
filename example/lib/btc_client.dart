import 'dart:convert';
import 'dart:io';

import 'package:dio/dio.dart';
import 'package:flutter/cupertino.dart';

class BtcClient {
  Dio? _dioClient;
  late Map<String, String> _headers;
  late String _url;
  final String wallet;

  String getConnectionString(String host, int port, String wallet) {
    return 'http://$host:$port/wallet/$wallet';
  }

  BtcClient(this.wallet) {
    _headers = {
      'Content-Type': 'application/json',
      'authorization': 'Basic ${base64.encode(utf8.encode('admin1:123'))}'
    };
    _url = getConnectionString(
        Platform.isAndroid ? "10.0.2.2" : "0.0.0.0", 18443, wallet);
    _dioClient = Dio();
  }

  Future<void> loadWallet() async {
    try {
      var params = [wallet];
      await call("loadwallet", params);
    } on Exception catch (e) {
      if (e.toString().contains("-4")) {
        debugPrint(" $wallet already loaded!");
      } else if (e.toString().contains("-18")) {
        debugPrint("$wallet doesn't exist!");
        var params = [wallet];
        await call("createwallet", params);
      }
    }
  }

  Future<bool> testMemPoolAccept(String rawtx) async {
    var params = [
      [rawtx]
    ];
    final res = await call("testmempoolaccept", params);
    return res;
  }

  Future<String> getNewAddress() async {
    var params = ["", "bech32"];
    final res = await call("getnewaddress", params);
    return res;
  }

  Future<List<dynamic>> generate(int nblocks, String address) async {
    var params = [
      nblocks,
      address,
    ];
    final res = await call("generatetoaddress", params);
    return res;
  }

  Future<double> getBalance() async {
    var params = [];
    final res = await call("getbalance", params);
    return res;
  }

  Future<Map<String, dynamic>> getAddressInfo(String address) async {
    var params = [address];
    final res = await call("getaddressinfo", params);
    return res;
  }

  Future<String> sendRawTransaction(String psbt) async {
    var params = [psbt];
    final res = await call("sendrawtransaction", params);
    return res;
  }

  Future<String> sendToAddress(String address, int amount) async {
    var params = [address, amount];
    final res = await call("sendtoaddress", params);
    return res;
  }

  Future<Map<String, dynamic>> walletProcessPsbt(String psbt) async {
    var params = [psbt, true, "ALL", false];
    final res = await call("walletprocesspsbt", params);
    return res as Map<String, dynamic>;
  }

  Future<Map<String, dynamic>> finalizePsbt(String psbt) async {
    var params = [psbt, true];
    final res = await call("finalizepsbt", params);
    return res as Map<String, dynamic>;
  }

  Future<List<dynamic>> listUnspent(List<String> addresses) async {
    var params = [
      1,
      9999999,
      addresses,
    ];
    final res = await call("listunspent", params);
    if (res == []) {
      return res;
    } else {
      return res;
    }
  }

  Future<Map<String, dynamic>> walletCreateFundedPsbt(
    amount,
    address,
    int feeRate,
  ) async {
    var params = [
      [],
      [
        {address: amount}
      ],
      0,
      {"lockUnspents": false, "fee_rate": feeRate}
    ];
    final res = await call("walletcreatefundedpsbt", params);
    return res as Map<String, dynamic>;
  }

  Future<dynamic> call(var methodName, [var params]) async {
    var body = {
      'jsonrpc': '2.0',
      'method': methodName,
      'params': params ?? [],
      'id': '1'
    };

    try {
      var response = await _dioClient!.post(
        _url,
        data: body,
        options: Options(
          headers: _headers,
        ),
      );
      if (response.statusCode == HttpStatus.ok) {
        var body = response.data as Map<String, dynamic>;
        if (body.containsKey('error') && body["error"] != null) {
          var error = body['error'];

          if (error["message"] is Map<String, dynamic>) {
            error = error['message'];
          }

          throw Exception(
            "errorCode: ${error['code']},errorMsg: ${error['message']}",
          );
        }
        return body['result'];
      }
    } on DioException catch (e) {
      if (e.type == DioExceptionType.badResponse) {
        var errorResponseBody = e.response!.data;

        switch (e.response!.statusCode) {
          case 401:
            throw Exception(
              " code: 401, message: Unauthorized",
            );
          case 403:
            throw Exception(
              "code: 403,message: Forbidden",
            );
          case 404:
            if (errorResponseBody['error'] != null) {
              var error = errorResponseBody['error'];
              throw Exception(
                "errorCode: ${error['code']},errorMsg: ${error['message']}",
              );
            }
            throw Exception(
              "code: 500, message: Internal Server Error",
            );
          default:
            if (errorResponseBody['error'] != null) {
              var error = errorResponseBody['error'];
              throw Exception(
                "errorCode: ${error['code']},errorMsg: ${error['message']}",
              );
            }
            throw Exception(
              "code: 500, message: 'Internal Server Error'",
            );
        }
      } else if (e.type == DioExceptionType.connectionError) {
        throw Exception(
          "code: 500,message: e.message ?? 'Connection Error'",
        );
      }
      throw Exception(
        "code: 500, message: e.message ?? 'Unknown Error'",
      );
    }
  }
}
