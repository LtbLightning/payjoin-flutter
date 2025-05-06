use crate::frb_generated::RustAutoOpaque;

pub struct FfiIntoUrlError(pub(crate) RustAutoOpaque<payjoin_ffi::uri::error::IntoUrlError>);

impl From<payjoin_ffi::uri::error::IntoUrlError> for FfiIntoUrlError {
    fn from(value: payjoin_ffi::uri::error::IntoUrlError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiPjParseError(pub(crate) RustAutoOpaque<payjoin_ffi::uri::PjParseError>);

impl From<payjoin_ffi::uri::PjParseError> for FfiPjParseError {
    fn from(value: payjoin_ffi::uri::PjParseError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiPjNotSupported(pub(crate) RustAutoOpaque<payjoin_ffi::uri::PjNotSupported>);

impl From<payjoin_ffi::uri::PjNotSupported> for FfiPjNotSupported {
    fn from(value: payjoin_ffi::uri::PjNotSupported) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiUrlParseError(pub(crate) RustAutoOpaque<payjoin_ffi::uri::UrlParseError>);

impl From<payjoin_ffi::uri::UrlParseError> for FfiUrlParseError {
    fn from(value: payjoin_ffi::uri::UrlParseError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}
