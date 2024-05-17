import 'exceptions.dart';
import 'generated/frb_generated.dart';

class PConfig {
  static Future<void> initializeApp() async {
    try {
      if (!PayjoinCore.instance.initialized) {
        await PayjoinCore.init();
      }
    } catch (e) {
      throw PayjoinException(message: "failed to initialize payjoin");
    }
  }
}
