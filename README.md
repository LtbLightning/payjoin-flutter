# Payjoin Flutter

A Flutter library for the [Payjoin Dev Kit](https://payjoindevkit.org/).

### How to Use

To use the `payjoin_flutter` package in your project, add it as a dependency in your project's pubspec.yaml:

```dart
dependencies:
payjoin_flutter: 0.13.0
```
### Requirements

- Flutter : 3.0 or higher
- Android minSdkVersion. : API 23 or higher.
- Deployment target : iOS 12.0 or greater.

### Build and run code
First we need to set up the `bitcoin core` and `esplora` locally in the regtest network. If you don't
have these, please refer to this [page](https://learn.saylor.org/mod/page/view.php?id=36347). Or you can
install `Nigiri Bitcoin`, which is a tool designed to simplify the process of running local instances of Bitcoin and
Liquid networks for development and testing purposes. You can refer to
this [link](https://github.com/vulpemventures/nigiri), to install it on your local machine.

Once the nigiri bitcoin starts running, you need to mine a few blocks. Please refer to the following [link](https://developer.bitcoin.org/reference/rpc/generatetoaddress.html?highlight=generate)
on how to mine blocks.

Before running the integration tests, please replace following snippet in `example/integration_test/bitcoin_core_full_cycle_test.dart` with your
nigiri bitcoin core credentials.

```dart
    // Bitcoin core credentials
    String rpcUser = "admin1";
    String rpcPassword = "123";
    int rpcPort = 18443;
```

## Running the integration tests
Once we have set up the Bitcoin core properly in the `Regtest` network, 

```shell
git clone https://github.com/LtbLightning/payjoin-flutter.git
cd payjoin-flutter

cd example
#Run integration tests with bitcoin_core and bdk_flutter
flutter test integration_test
```

