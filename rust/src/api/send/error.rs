use crate::frb_generated::RustAutoOpaque;

pub struct FfiBuildSenderError {
    pub(crate) msg: String,
}

impl From<payjoin_ffi::send::BuildSenderError> for FfiBuildSenderError {
    fn from(value: payjoin_ffi::send::BuildSenderError) -> Self {
        Self { msg: value.to_string() }
    }
}

pub struct FfiCreateRequestError {
    pub(crate) msg: String,
}

impl From<payjoin_ffi::send::CreateRequestError> for FfiCreateRequestError {
    fn from(value: payjoin_ffi::send::CreateRequestError) -> Self {
        Self { msg: value.to_string() }
    }
}

pub struct FfiEncapsulationError {
    pub(crate) msg: String,
}

impl From<payjoin_ffi::send::EncapsulationError> for FfiEncapsulationError {
    fn from(value: payjoin_ffi::send::EncapsulationError) -> Self {
        Self { msg: value.to_string() }
    }
}

pub struct FfiValidationError(pub(crate) RustAutoOpaque<payjoin_ffi::send::error::ValidationError>);

impl From<payjoin_ffi::send::error::ValidationError> for FfiValidationError {
    fn from(value: payjoin_ffi::send::error::ValidationError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiWellKnownError(pub(crate) RustAutoOpaque<payjoin_ffi::send::error::WellKnownError>);

pub struct FfiResponseError(pub(crate) RustAutoOpaque<payjoin_ffi::send::error::ResponseError>);

impl From<payjoin_ffi::send::error::ResponseError> for FfiResponseError {
    fn from(value: payjoin_ffi::send::error::ResponseError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}
