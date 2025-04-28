// dart format width=80
// coverage:ignore-file
// GENERATED CODE - DO NOT MODIFY BY HAND
// ignore_for_file: type=lint
// ignore_for_file: unused_element, deprecated_member_use, deprecated_member_use_from_same_package, use_function_type_syntax_for_parameters, unnecessary_const, avoid_init_to_null, invalid_override_different_default_values_named, prefer_expression_function_bodies, annotate_overrides, invalid_annotation_target, unnecessary_question_mark

part of 'error.dart';

// **************************************************************************
// FreezedGenerator
// **************************************************************************

// dart format off
T _$identity<T>(T value) => value;

/// @nodoc
mixin _$PayjoinError {
  String get message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinErrorCopyWith<PayjoinError> get copyWith =>
      _$PayjoinErrorCopyWithImpl<PayjoinError>(
          this as PayjoinError, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinErrorCopyWith(
          PayjoinError value, $Res Function(PayjoinError) _then) =
      _$PayjoinErrorCopyWithImpl;
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinErrorCopyWithImpl<$Res> implements $PayjoinErrorCopyWith<$Res> {
  _$PayjoinErrorCopyWithImpl(this._self, this._then);

  final PayjoinError _self;
  final $Res Function(PayjoinError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @pragma('vm:prefer-inline')
  @override
  $Res call({
    Object? message = null,
  }) {
    return _then(_self.copyWith(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_InvalidAddress extends PayjoinError {
  const PayjoinError_InvalidAddress({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_InvalidAddressCopyWith<PayjoinError_InvalidAddress>
      get copyWith => _$PayjoinError_InvalidAddressCopyWithImpl<
          PayjoinError_InvalidAddress>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_InvalidAddress &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.invalidAddress(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_InvalidAddressCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_InvalidAddressCopyWith(
          PayjoinError_InvalidAddress value,
          $Res Function(PayjoinError_InvalidAddress) _then) =
      _$PayjoinError_InvalidAddressCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_InvalidAddressCopyWithImpl<$Res>
    implements $PayjoinError_InvalidAddressCopyWith<$Res> {
  _$PayjoinError_InvalidAddressCopyWithImpl(this._self, this._then);

  final PayjoinError_InvalidAddress _self;
  final $Res Function(PayjoinError_InvalidAddress) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_InvalidAddress(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_InvalidScript extends PayjoinError {
  const PayjoinError_InvalidScript({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_InvalidScriptCopyWith<PayjoinError_InvalidScript>
      get copyWith =>
          _$PayjoinError_InvalidScriptCopyWithImpl<PayjoinError_InvalidScript>(
              this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_InvalidScript &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.invalidScript(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_InvalidScriptCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_InvalidScriptCopyWith(PayjoinError_InvalidScript value,
          $Res Function(PayjoinError_InvalidScript) _then) =
      _$PayjoinError_InvalidScriptCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_InvalidScriptCopyWithImpl<$Res>
    implements $PayjoinError_InvalidScriptCopyWith<$Res> {
  _$PayjoinError_InvalidScriptCopyWithImpl(this._self, this._then);

  final PayjoinError_InvalidScript _self;
  final $Res Function(PayjoinError_InvalidScript) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_InvalidScript(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_NetworkValidation extends PayjoinError {
  const PayjoinError_NetworkValidation({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_NetworkValidationCopyWith<PayjoinError_NetworkValidation>
      get copyWith => _$PayjoinError_NetworkValidationCopyWithImpl<
          PayjoinError_NetworkValidation>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_NetworkValidation &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.networkValidation(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_NetworkValidationCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_NetworkValidationCopyWith(
          PayjoinError_NetworkValidation value,
          $Res Function(PayjoinError_NetworkValidation) _then) =
      _$PayjoinError_NetworkValidationCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_NetworkValidationCopyWithImpl<$Res>
    implements $PayjoinError_NetworkValidationCopyWith<$Res> {
  _$PayjoinError_NetworkValidationCopyWithImpl(this._self, this._then);

  final PayjoinError_NetworkValidation _self;
  final $Res Function(PayjoinError_NetworkValidation) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_NetworkValidation(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_PsbtParseError extends PayjoinError {
  const PayjoinError_PsbtParseError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_PsbtParseErrorCopyWith<PayjoinError_PsbtParseError>
      get copyWith => _$PayjoinError_PsbtParseErrorCopyWithImpl<
          PayjoinError_PsbtParseError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_PsbtParseError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.psbtParseError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_PsbtParseErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_PsbtParseErrorCopyWith(
          PayjoinError_PsbtParseError value,
          $Res Function(PayjoinError_PsbtParseError) _then) =
      _$PayjoinError_PsbtParseErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_PsbtParseErrorCopyWithImpl<$Res>
    implements $PayjoinError_PsbtParseErrorCopyWith<$Res> {
  _$PayjoinError_PsbtParseErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_PsbtParseError _self;
  final $Res Function(PayjoinError_PsbtParseError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_PsbtParseError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_ResponseError extends PayjoinError {
  const PayjoinError_ResponseError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_ResponseErrorCopyWith<PayjoinError_ResponseError>
      get copyWith =>
          _$PayjoinError_ResponseErrorCopyWithImpl<PayjoinError_ResponseError>(
              this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_ResponseError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.responseError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_ResponseErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_ResponseErrorCopyWith(PayjoinError_ResponseError value,
          $Res Function(PayjoinError_ResponseError) _then) =
      _$PayjoinError_ResponseErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_ResponseErrorCopyWithImpl<$Res>
    implements $PayjoinError_ResponseErrorCopyWith<$Res> {
  _$PayjoinError_ResponseErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_ResponseError _self;
  final $Res Function(PayjoinError_ResponseError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_ResponseError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_RequestError extends PayjoinError {
  const PayjoinError_RequestError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_RequestErrorCopyWith<PayjoinError_RequestError> get copyWith =>
      _$PayjoinError_RequestErrorCopyWithImpl<PayjoinError_RequestError>(
          this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_RequestError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.requestError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_RequestErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_RequestErrorCopyWith(PayjoinError_RequestError value,
          $Res Function(PayjoinError_RequestError) _then) =
      _$PayjoinError_RequestErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_RequestErrorCopyWithImpl<$Res>
    implements $PayjoinError_RequestErrorCopyWith<$Res> {
  _$PayjoinError_RequestErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_RequestError _self;
  final $Res Function(PayjoinError_RequestError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_RequestError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_TransactionError extends PayjoinError {
  const PayjoinError_TransactionError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_TransactionErrorCopyWith<PayjoinError_TransactionError>
      get copyWith => _$PayjoinError_TransactionErrorCopyWithImpl<
          PayjoinError_TransactionError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_TransactionError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.transactionError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_TransactionErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_TransactionErrorCopyWith(
          PayjoinError_TransactionError value,
          $Res Function(PayjoinError_TransactionError) _then) =
      _$PayjoinError_TransactionErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_TransactionErrorCopyWithImpl<$Res>
    implements $PayjoinError_TransactionErrorCopyWith<$Res> {
  _$PayjoinError_TransactionErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_TransactionError _self;
  final $Res Function(PayjoinError_TransactionError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_TransactionError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_ServerError extends PayjoinError {
  const PayjoinError_ServerError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_ServerErrorCopyWith<PayjoinError_ServerError> get copyWith =>
      _$PayjoinError_ServerErrorCopyWithImpl<PayjoinError_ServerError>(
          this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_ServerError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.serverError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_ServerErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_ServerErrorCopyWith(PayjoinError_ServerError value,
          $Res Function(PayjoinError_ServerError) _then) =
      _$PayjoinError_ServerErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_ServerErrorCopyWithImpl<$Res>
    implements $PayjoinError_ServerErrorCopyWith<$Res> {
  _$PayjoinError_ServerErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_ServerError _self;
  final $Res Function(PayjoinError_ServerError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_ServerError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_SelectionError extends PayjoinError {
  const PayjoinError_SelectionError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_SelectionErrorCopyWith<PayjoinError_SelectionError>
      get copyWith => _$PayjoinError_SelectionErrorCopyWithImpl<
          PayjoinError_SelectionError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_SelectionError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.selectionError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_SelectionErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_SelectionErrorCopyWith(
          PayjoinError_SelectionError value,
          $Res Function(PayjoinError_SelectionError) _then) =
      _$PayjoinError_SelectionErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_SelectionErrorCopyWithImpl<$Res>
    implements $PayjoinError_SelectionErrorCopyWith<$Res> {
  _$PayjoinError_SelectionErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_SelectionError _self;
  final $Res Function(PayjoinError_SelectionError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_SelectionError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_CreateRequestError extends PayjoinError {
  const PayjoinError_CreateRequestError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_CreateRequestErrorCopyWith<PayjoinError_CreateRequestError>
      get copyWith => _$PayjoinError_CreateRequestErrorCopyWithImpl<
          PayjoinError_CreateRequestError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_CreateRequestError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.createRequestError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_CreateRequestErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_CreateRequestErrorCopyWith(
          PayjoinError_CreateRequestError value,
          $Res Function(PayjoinError_CreateRequestError) _then) =
      _$PayjoinError_CreateRequestErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_CreateRequestErrorCopyWithImpl<$Res>
    implements $PayjoinError_CreateRequestErrorCopyWith<$Res> {
  _$PayjoinError_CreateRequestErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_CreateRequestError _self;
  final $Res Function(PayjoinError_CreateRequestError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_CreateRequestError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_PjParseError extends PayjoinError {
  const PayjoinError_PjParseError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_PjParseErrorCopyWith<PayjoinError_PjParseError> get copyWith =>
      _$PayjoinError_PjParseErrorCopyWithImpl<PayjoinError_PjParseError>(
          this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_PjParseError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.pjParseError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_PjParseErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_PjParseErrorCopyWith(PayjoinError_PjParseError value,
          $Res Function(PayjoinError_PjParseError) _then) =
      _$PayjoinError_PjParseErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_PjParseErrorCopyWithImpl<$Res>
    implements $PayjoinError_PjParseErrorCopyWith<$Res> {
  _$PayjoinError_PjParseErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_PjParseError _self;
  final $Res Function(PayjoinError_PjParseError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_PjParseError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_PjNotSupported extends PayjoinError {
  const PayjoinError_PjNotSupported({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_PjNotSupportedCopyWith<PayjoinError_PjNotSupported>
      get copyWith => _$PayjoinError_PjNotSupportedCopyWithImpl<
          PayjoinError_PjNotSupported>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_PjNotSupported &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.pjNotSupported(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_PjNotSupportedCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_PjNotSupportedCopyWith(
          PayjoinError_PjNotSupported value,
          $Res Function(PayjoinError_PjNotSupported) _then) =
      _$PayjoinError_PjNotSupportedCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_PjNotSupportedCopyWithImpl<$Res>
    implements $PayjoinError_PjNotSupportedCopyWith<$Res> {
  _$PayjoinError_PjNotSupportedCopyWithImpl(this._self, this._then);

  final PayjoinError_PjNotSupported _self;
  final $Res Function(PayjoinError_PjNotSupported) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_PjNotSupported(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_ValidationError extends PayjoinError {
  const PayjoinError_ValidationError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_ValidationErrorCopyWith<PayjoinError_ValidationError>
      get copyWith => _$PayjoinError_ValidationErrorCopyWithImpl<
          PayjoinError_ValidationError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_ValidationError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.validationError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_ValidationErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_ValidationErrorCopyWith(
          PayjoinError_ValidationError value,
          $Res Function(PayjoinError_ValidationError) _then) =
      _$PayjoinError_ValidationErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_ValidationErrorCopyWithImpl<$Res>
    implements $PayjoinError_ValidationErrorCopyWith<$Res> {
  _$PayjoinError_ValidationErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_ValidationError _self;
  final $Res Function(PayjoinError_ValidationError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_ValidationError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_V2Error extends PayjoinError {
  const PayjoinError_V2Error({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_V2ErrorCopyWith<PayjoinError_V2Error> get copyWith =>
      _$PayjoinError_V2ErrorCopyWithImpl<PayjoinError_V2Error>(
          this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_V2Error &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.v2Error(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_V2ErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_V2ErrorCopyWith(PayjoinError_V2Error value,
          $Res Function(PayjoinError_V2Error) _then) =
      _$PayjoinError_V2ErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_V2ErrorCopyWithImpl<$Res>
    implements $PayjoinError_V2ErrorCopyWith<$Res> {
  _$PayjoinError_V2ErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_V2Error _self;
  final $Res Function(PayjoinError_V2Error) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_V2Error(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_UnexpectedError extends PayjoinError {
  const PayjoinError_UnexpectedError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_UnexpectedErrorCopyWith<PayjoinError_UnexpectedError>
      get copyWith => _$PayjoinError_UnexpectedErrorCopyWithImpl<
          PayjoinError_UnexpectedError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_UnexpectedError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.unexpectedError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_UnexpectedErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_UnexpectedErrorCopyWith(
          PayjoinError_UnexpectedError value,
          $Res Function(PayjoinError_UnexpectedError) _then) =
      _$PayjoinError_UnexpectedErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_UnexpectedErrorCopyWithImpl<$Res>
    implements $PayjoinError_UnexpectedErrorCopyWith<$Res> {
  _$PayjoinError_UnexpectedErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_UnexpectedError _self;
  final $Res Function(PayjoinError_UnexpectedError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_UnexpectedError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_OhttpError extends PayjoinError {
  const PayjoinError_OhttpError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_OhttpErrorCopyWith<PayjoinError_OhttpError> get copyWith =>
      _$PayjoinError_OhttpErrorCopyWithImpl<PayjoinError_OhttpError>(
          this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_OhttpError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.ohttpError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_OhttpErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_OhttpErrorCopyWith(PayjoinError_OhttpError value,
          $Res Function(PayjoinError_OhttpError) _then) =
      _$PayjoinError_OhttpErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_OhttpErrorCopyWithImpl<$Res>
    implements $PayjoinError_OhttpErrorCopyWith<$Res> {
  _$PayjoinError_OhttpErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_OhttpError _self;
  final $Res Function(PayjoinError_OhttpError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_OhttpError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_UrlError extends PayjoinError {
  const PayjoinError_UrlError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_UrlErrorCopyWith<PayjoinError_UrlError> get copyWith =>
      _$PayjoinError_UrlErrorCopyWithImpl<PayjoinError_UrlError>(
          this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_UrlError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.urlError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_UrlErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_UrlErrorCopyWith(PayjoinError_UrlError value,
          $Res Function(PayjoinError_UrlError) _then) =
      _$PayjoinError_UrlErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_UrlErrorCopyWithImpl<$Res>
    implements $PayjoinError_UrlErrorCopyWith<$Res> {
  _$PayjoinError_UrlErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_UrlError _self;
  final $Res Function(PayjoinError_UrlError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_UrlError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_IoError extends PayjoinError {
  const PayjoinError_IoError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_IoErrorCopyWith<PayjoinError_IoError> get copyWith =>
      _$PayjoinError_IoErrorCopyWithImpl<PayjoinError_IoError>(
          this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_IoError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.ioError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_IoErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_IoErrorCopyWith(PayjoinError_IoError value,
          $Res Function(PayjoinError_IoError) _then) =
      _$PayjoinError_IoErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_IoErrorCopyWithImpl<$Res>
    implements $PayjoinError_IoErrorCopyWith<$Res> {
  _$PayjoinError_IoErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_IoError _self;
  final $Res Function(PayjoinError_IoError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_IoError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_OutputSubstitutionError extends PayjoinError {
  const PayjoinError_OutputSubstitutionError({required this.message})
      : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_OutputSubstitutionErrorCopyWith<
          PayjoinError_OutputSubstitutionError>
      get copyWith => _$PayjoinError_OutputSubstitutionErrorCopyWithImpl<
          PayjoinError_OutputSubstitutionError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_OutputSubstitutionError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.outputSubstitutionError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_OutputSubstitutionErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_OutputSubstitutionErrorCopyWith(
          PayjoinError_OutputSubstitutionError value,
          $Res Function(PayjoinError_OutputSubstitutionError) _then) =
      _$PayjoinError_OutputSubstitutionErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_OutputSubstitutionErrorCopyWithImpl<$Res>
    implements $PayjoinError_OutputSubstitutionErrorCopyWith<$Res> {
  _$PayjoinError_OutputSubstitutionErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_OutputSubstitutionError _self;
  final $Res Function(PayjoinError_OutputSubstitutionError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_OutputSubstitutionError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_InputContributionError extends PayjoinError {
  const PayjoinError_InputContributionError({required this.message})
      : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_InputContributionErrorCopyWith<
          PayjoinError_InputContributionError>
      get copyWith => _$PayjoinError_InputContributionErrorCopyWithImpl<
          PayjoinError_InputContributionError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_InputContributionError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.inputContributionError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_InputContributionErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_InputContributionErrorCopyWith(
          PayjoinError_InputContributionError value,
          $Res Function(PayjoinError_InputContributionError) _then) =
      _$PayjoinError_InputContributionErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_InputContributionErrorCopyWithImpl<$Res>
    implements $PayjoinError_InputContributionErrorCopyWith<$Res> {
  _$PayjoinError_InputContributionErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_InputContributionError _self;
  final $Res Function(PayjoinError_InputContributionError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_InputContributionError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_InputPairError extends PayjoinError {
  const PayjoinError_InputPairError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_InputPairErrorCopyWith<PayjoinError_InputPairError>
      get copyWith => _$PayjoinError_InputPairErrorCopyWithImpl<
          PayjoinError_InputPairError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_InputPairError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.inputPairError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_InputPairErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_InputPairErrorCopyWith(
          PayjoinError_InputPairError value,
          $Res Function(PayjoinError_InputPairError) _then) =
      _$PayjoinError_InputPairErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_InputPairErrorCopyWithImpl<$Res>
    implements $PayjoinError_InputPairErrorCopyWith<$Res> {
  _$PayjoinError_InputPairErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_InputPairError _self;
  final $Res Function(PayjoinError_InputPairError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_InputPairError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class PayjoinError_SerdeJsonError extends PayjoinError {
  const PayjoinError_SerdeJsonError({required this.message}) : super._();

  @override
  final String message;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @JsonKey(includeFromJson: false, includeToJson: false)
  @pragma('vm:prefer-inline')
  $PayjoinError_SerdeJsonErrorCopyWith<PayjoinError_SerdeJsonError>
      get copyWith => _$PayjoinError_SerdeJsonErrorCopyWithImpl<
          PayjoinError_SerdeJsonError>(this, _$identity);

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is PayjoinError_SerdeJsonError &&
            (identical(other.message, message) || other.message == message));
  }

  @override
  int get hashCode => Object.hash(runtimeType, message);

  @override
  String toString() {
    return 'PayjoinError.serdeJsonError(message: $message)';
  }
}

/// @nodoc
abstract mixin class $PayjoinError_SerdeJsonErrorCopyWith<$Res>
    implements $PayjoinErrorCopyWith<$Res> {
  factory $PayjoinError_SerdeJsonErrorCopyWith(
          PayjoinError_SerdeJsonError value,
          $Res Function(PayjoinError_SerdeJsonError) _then) =
      _$PayjoinError_SerdeJsonErrorCopyWithImpl;
  @override
  @useResult
  $Res call({String message});
}

/// @nodoc
class _$PayjoinError_SerdeJsonErrorCopyWithImpl<$Res>
    implements $PayjoinError_SerdeJsonErrorCopyWith<$Res> {
  _$PayjoinError_SerdeJsonErrorCopyWithImpl(this._self, this._then);

  final PayjoinError_SerdeJsonError _self;
  final $Res Function(PayjoinError_SerdeJsonError) _then;

  /// Create a copy of PayjoinError
  /// with the given fields replaced by the non-null parameter values.
  @override
  @pragma('vm:prefer-inline')
  $Res call({
    Object? message = null,
  }) {
    return _then(PayjoinError_SerdeJsonError(
      message: null == message
          ? _self.message
          : message // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

// dart format on
