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

## Run the example app

Before running the example app, we need to set up the Bitcoin core properly in the regtest network. If you donot
have Bitcoin Core locally, please refer to this [page](https://learn.saylor.org/mod/page/view.php?id=36347). Or you can
install `Nigiri Bitcoin`, which is a tool designed to simplify the process of running local instances of Bitcoin and
Liquid networks for development and testing purposes. You can refer to
this [link](https://github.com/vulpemventures/nigiri), to install it on your local machine.

NB: The default credentials would be the following
```
rpc_user = "admin1"
rpc_password = "123"
rpc_host = "localhost"
rpc_port = "18443"
```

