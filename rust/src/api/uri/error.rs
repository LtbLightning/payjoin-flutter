use crate::ffi_opaque_wrapper;

ffi_opaque_wrapper!(FfiIntoUrlError, payjoin_ffi::uri::error::IntoUrlError);
ffi_opaque_wrapper!(FfiPjParseError, payjoin_ffi::uri::PjParseError);
ffi_opaque_wrapper!(FfiPjNotSupported, payjoin_ffi::uri::PjNotSupported);
ffi_opaque_wrapper!(FfiUrlParseError, payjoin_ffi::uri::UrlParseError);
