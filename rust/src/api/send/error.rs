use crate::ffi_opaque_wrapper;

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

ffi_opaque_wrapper!(FfiValidationError, payjoin_ffi::send::error::ValidationError);
ffi_opaque_wrapper!(FfiWellKnownError, payjoin_ffi::send::error::WellKnownError);
ffi_opaque_wrapper!(FfiResponseError, payjoin_ffi::send::error::ResponseError);
