import 'package:flutter_rust_bridge/flutter_rust_bridge_for_generated.dart';
import 'package:payjoin_flutter/uri.dart';
import 'src/generated/api/send.dart';

export 'src/exceptions.dart' hide mapPayjoinError, ExceptionBase;
export 'src/generated/utils/types.dart';

class Request extends FfiRequest {
  final Url url;

  Request(
    this.url,
    Uint8List body,
  ) : super(ffiUrl: url, body: body);
}
