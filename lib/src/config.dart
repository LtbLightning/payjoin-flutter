import 'generated/frb_generated.dart';

class PConfig {
  static Future<void> initializeApp() async {
    try {
      if (!core.instance.initialized) {
        await core.init();
      }
    } catch (e) {
      throw "failed to initialize payjoin";
    }
  }
}
