import 'src/generated/api/receive.dart';

export 'src/generated/api/receive.dart'
    show ReceiverToken, DartReceiverPersister;

typedef NewReceiver = FfiNewReceiver;
typedef Receiver = FfiReceiver;
typedef UncheckedProposal = FfiUncheckedProposal;
typedef MaybeInputsOwned = FfiMaybeInputsOwned;
typedef MaybeInputsSeen = FfiMaybeInputsSeen;
typedef OutputsUnknown = FfiOutputsUnknown;
typedef WantsOutputs = FfiWantsOutputs;
typedef WantsInputs = FfiWantsInputs;
typedef InputPair = FfiInputPair;
typedef ProvisionalProposal = FfiProvisionalProposal;
typedef PayjoinProposal = FfiPayjoinProposal;
typedef FfiDartReceiverPersister = DartReceiverPersister;
typedef FfiReceiverToken = ReceiverToken;
