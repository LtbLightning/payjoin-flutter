import 'package:flutter/cupertino.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:integration_test/integration_test.dart';
import 'package:payjoin_flutter/uri.dart' as pay_join_uri;
import 'package:payjoin_flutter_example/btc_client.dart';
import 'package:payjoin_flutter_example/payjoin_library.dart';

void main() {
  IntegrationTestWidgetsFlutterBinding.ensureInitialized();

  group('v1_to_v1', () {
    setUp(() async {});
    testWidgets('full_cycle', (WidgetTester tester) async {
      final payJoinLib = PayJoinLibrary();
      final sender = BtcClient("receiver");
      final receiver = BtcClient("sender");
      // Receiver creates the payjoin URI
      final pjReceiverAddress = await receiver.getNewAddress();
      final pjSenderAddress = await sender.getNewAddress();
      //Generate blocks to receiver and sender
      await sender.generateToAddress(11, pjSenderAddress);
      await receiver.generateToAddress(1, pjReceiverAddress);
      final pjUri = await payJoinLib.buildPjUri(0.0083285, pjReceiverAddress);
      // Sender create a funded PSBT (not broadcast) to address with amount given in the pjUri
      debugPrint("Sender Balance: ${(await sender.getBalance()).toString()}");
      final uri = await pay_join_uri.Uri.fromString(pjUri);
      final address = await uri.address();
      final amount = await uri.amount();
      final senderPsbt =
          (await sender.walletCreateFundedPsbt(amount, address, 2000))["psbt"];
      debugPrint(
        "\nOriginal sender psbt: $senderPsbt",
      );
      final receiverPsbt =
          await payJoinLib.handlePjRequest(senderPsbt, pjUri, receiver);
      debugPrint("\n Original receiver psbt: $receiverPsbt");
      final senderProcessedPsbt =
          (await sender.walletProcessPsbt(receiverPsbt))["psbt"];
      final senderFinalizedPsbt =
          (await sender.finalizePsbt(senderProcessedPsbt));
      final res = await sender.sendRawTransaction(senderFinalizedPsbt["hex"]);
      debugPrint("Broadcast success: $res");
    });
  });
}
