import 'package:flutter_rust_bridge/flutter_rust_bridge_for_generated.dart';
import 'package:payjoin_flutter/uri.dart';

export 'src/exceptions.dart' hide mapPayjoinError, ExceptionBase;
export 'src/generated/utils/types.dart';

class Request {
  final Url url;
  final Uint8List body;
  Request(this.url, this.body);
}
