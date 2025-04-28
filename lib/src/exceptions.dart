import 'generated/utils/error.dart' as error;

abstract class ExceptionBase implements Exception {
  String? message;

  ExceptionBase({this.message});

  @override
  String toString() =>
      (message != null) ? '$runtimeType( $message )' : runtimeType.toString();
}

/// Returned when trying to start [Node] while it is already running.
class PayjoinException extends ExceptionBase {
  PayjoinException({super.message});
}

PayjoinException mapPayjoinError(error.PayjoinError e) {
  if (e is error.PayjoinError_InvalidAddress) {
    return PayjoinException(
        message: "Error while parsing the address: ${e.message}");
  } else if (e is error.PayjoinError_InvalidScript) {
    return PayjoinException(
        message: "Error while parsing the script: ${e.message}");
  } else if (e is error.PayjoinError_NetworkValidation) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_PsbtParseError) {
    return PayjoinException(
        message: "Error encountered while decoding PSBT: ${e.message}");
  } else if (e is error.PayjoinError_ResponseError) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_RequestError) {
    return PayjoinException(
        message:
            "Error encountered while processing the sender's request: ${e.message}");
  } else if (e is error.PayjoinError_TransactionError) {
    return PayjoinException(
        message:
            "Error encountered while decoding transaction data: ${e.message}");
  } else if (e is error.PayjoinError_ServerError) {
    return PayjoinException(message: "HTTP 500: ${e.message}");
  } else if (e is error.PayjoinError_SelectionError) {
    return PayjoinException(
        message: "Error occurred during coin selection: ${e.message}");
  } else if (e is error.PayjoinError_CreateRequestError) {
    return PayjoinException(
        message: "Error creating the request: ${e.message}");
  } else if (e is error.PayjoinError_PjParseError) {
    return PayjoinException(message: "Error parsing the Pj URL: ${e.message}");
  } else if (e is error.PayjoinError_PjNotSupported) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_ValidationError) {
    return PayjoinException(
        message: "Malformed response from receiver: ${e.message}");
  } else if (e is error.PayjoinError_V2Error) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_UnexpectedError) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_OhttpError) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_UrlError) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_IoError) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_OutputSubstitutionError) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_InputContributionError) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_InputPairError) {
    return PayjoinException(message: e.message);
  } else if (e is error.PayjoinError_SerdeJsonError) {
    return PayjoinException(message: e.message);
  } else {
    return PayjoinException(message: "Unknown error: ${e.message}");
  }
}
