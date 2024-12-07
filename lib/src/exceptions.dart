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
  return e.map(
    invalidAddress: (e) => PayjoinException(
        message: "Error while parsing the address: ${e.message}"),
    invalidScript: (e) => PayjoinException(
        message: "Error while parsing the script: ${e.message}"),
    networkValidation: (e) => PayjoinException(message: e.message),
    psbtParseError: (e) => PayjoinException(
        message: "Error encountered while decoding PSBT: ${e.message}"),
    responseError: (e) => PayjoinException(message: e.message),
    requestError: (e) => PayjoinException(
        message:
            "Error encountered while processing the sender's request: ${e.message}"),
    transactionError: (e) => PayjoinException(
        message:
            "Error encountered while decoding transaction data: ${e.message}"),
    serverError: (e) => PayjoinException(message: "HTTP 500: ${e.message}"),
    selectionError: (e) => PayjoinException(
        message: "Error occurred during coin selection: ${e.message}"),
    createRequestError: (e) =>
        PayjoinException(message: "Error creating the request: ${e.message}"),
    pjParseError: (e) =>
        PayjoinException(message: "Error parsing the Pj URL: ${e.message}"),
    pjNotSupported: (e) => PayjoinException(message: e.message),
    validationError: (e) => PayjoinException(
        message: "Malformed response from receiver: ${e.message}"),
    v2Error: (e) => PayjoinException(message: e.message),
    unexpectedError: (e) => PayjoinException(message: e.message),
    ohttpError: (e) => PayjoinException(message: e.message),
    urlError: (e) => PayjoinException(message: e.message),
    ioError: (e) => PayjoinException(message: e.message),
    outputSubstitutionError: (e) => PayjoinException(message: e.message),
    inputContributionError: (e) => PayjoinException(message: e.message),
    inputPairError: (e) => PayjoinException(message: e.message),
    serdeJsonError: (e) => PayjoinException(message: e.message),
  );
}
