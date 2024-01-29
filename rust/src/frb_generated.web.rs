// This file is automatically generated, so please do not edit it.
// Generated by `flutter_rust_bridge`@ 2.0.0-dev.24.

// Section: imports

use super::*;
use crate::api::receive::*;
use crate::api::send::*;
use flutter_rust_bridge::for_generated::byteorder::{NativeEndian, ReadBytesExt, WriteBytesExt};
use flutter_rust_bridge::for_generated::transform_result_dco;
use flutter_rust_bridge::for_generated::wasm_bindgen;
use flutter_rust_bridge::for_generated::wasm_bindgen::prelude::*;
use flutter_rust_bridge::{Handler, IntoIntoDart};

// Section: boilerplate

flutter_rust_bridge::frb_generated_boilerplate_web!();

#[wasm_bindgen]
pub fn rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceiveMaybeInputsOwned(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::receive::MaybeInputsOwned>>::increment_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceiveMaybeInputsOwned(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::receive::MaybeInputsOwned>>::decrement_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendContextV1(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::send::ContextV1>>::increment_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendContextV1(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::send::ContextV1>>::decrement_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendRequestBuilder(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::send::RequestBuilder>>::increment_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendRequestBuilder(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::send::RequestBuilder>>::decrement_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendRequestContext(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::send::RequestContext>>::increment_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendRequestContext(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::send::RequestContext>>::decrement_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::send::v2::ContextV2>>::increment_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::send::v2::ContextV2>>::decrement_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffiuriUri(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::uri::Uri>>::increment_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffiuriUri(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::uri::Uri>>::decrement_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffiuriUrl(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::uri::Url>>::increment_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffiuriUrl(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<Arc<payjoin_ffi::uri::Url>>::decrement_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedrust_asyncRwLockBoxdynFnVecu8ResultboolPayjoinErrorSendSync(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<
        flutter_rust_bridge::for_generated::rust_async::RwLock<
            Box<dyn Fn(Vec<u8>) -> Result<bool, PayjoinError> + Send + Sync>,
        >,
    >::increment_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedrust_asyncRwLockBoxdynFnVecu8ResultboolPayjoinErrorSendSync(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<
        flutter_rust_bridge::for_generated::rust_async::RwLock<
            Box<dyn Fn(Vec<u8>) -> Result<bool, PayjoinError> + Send + Sync>,
        >,
    >::decrement_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<payjoin_ffi::receive::UncheckedProposal>::increment_strong_count(ptr as _);
}

#[wasm_bindgen]
pub fn rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal(
    ptr: *const std::ffi::c_void,
) {
    MoiArc::<payjoin_ffi::receive::UncheckedProposal>::decrement_strong_count(ptr as _);
}
