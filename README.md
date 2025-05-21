# Payjoin Flutter

A Flutter library for the [Payjoin Dev Kit](https://payjoindevkit.org/).

### How to Use

To use the `payjoin_flutter` package in your project, add it as a dependency in your project's pubspec.yaml:

```dart
dependencies:
payjoin_flutter: 0.23.0
```
### Requirements

- Flutter : 3.3 or higher
- Android minSdkVersion. : API 23 or higher.
- Deployment target : iOS 12.0 or greater.


## Running the Example App
Clone the repo, then:

```shell
cd payjoin-flutter
cd example

flutter pub get
flutter run
```

For more advanced usage notes see below

## Flutter and Flutter Rust Bridge Usage Notes
Here are some useful commands when making changes that require rebuilding the generated code or running the example app to test:

```shell
# You often need to run the build_runner to generate freezed files
flutter pub get
flutter pub run build_runner build --delete-conflicting-outputs
flutter run

# Must be run after any updates to the rust code (can be set to watch)
flutter_rust_bridge_codegen generate
# or
flutter_rust_bridge_codegen generate --watch
# Note: generated files can be determined based off what the custom rust code is importing. If you're expecting something to be available from a generated file but your rust isn't compiling then regenerate (ex: frb_generated::RustOpaque type is determined by how it's used)

# Useful if your app build gets messed up (ios for example)
flutter pub cache repair
```

## References

[Payjoin Dev Kit](https://payjoindevkit.org/)

[mozilla/uniffi-rs](https://github.com/mozilla/uniffi-rs)

## Release Status and Disclaimer

This project is in active development and currently in its Alpha stage. **Please proceed with caution**, particularly when using real funds.
We encourage thorough review, testing, and contributions to help improve its stability and security before considering production use.
