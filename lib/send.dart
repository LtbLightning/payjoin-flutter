import 'src/generated/api/send.dart';

export 'src/generated/api/send.dart' show SenderToken, DartSenderPersister;

typedef SenderBuilder = FfiSenderBuilder;
typedef NewSender = FfiNewSender;
typedef Sender = FfiSender;
typedef V1Context = FfiV1Context;
typedef V2PostContext = FfiV2PostContext;
typedef V2GetContext = FfiV2GetContext;
