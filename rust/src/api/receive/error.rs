use crate::frb_generated::RustAutoOpaque;


pub struct FfiError(pub(crate) RustAutoOpaque<payjoin_ffi::receive::Error>);

impl From<payjoin_ffi::receive::Error> for FfiError {
    fn from(value: payjoin_ffi::receive::Error) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiImplementationError(pub(crate) RustAutoOpaque<payjoin_ffi::receive::ImplementationError>);

impl From<payjoin_ffi::receive::ImplementationError> for FfiImplementationError {
    fn from(value: payjoin_ffi::receive::ImplementationError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiSessionError(pub(crate) RustAutoOpaque<payjoin_ffi::receive::SessionError>);

impl From<payjoin_ffi::receive::SessionError> for FfiSessionError {
    fn from(value: payjoin_ffi::receive::SessionError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiInputContributionError(pub RustAutoOpaque<payjoin_ffi::receive::InputContributionError>);

impl From<payjoin_ffi::receive::InputContributionError> for FfiInputContributionError {
    fn from(value: payjoin_ffi::receive::InputContributionError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiOutputSubstitutionError(pub(crate) RustAutoOpaque<payjoin_ffi::receive::OutputSubstitutionError>);

impl From<payjoin_ffi::receive::OutputSubstitutionError> for FfiOutputSubstitutionError {
    fn from(value: payjoin_ffi::receive::OutputSubstitutionError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiPsbtInputError(pub(crate) RustAutoOpaque<payjoin_ffi::receive::PsbtInputError>);

impl From<payjoin_ffi::receive::PsbtInputError> for FfiPsbtInputError {
    fn from(value: payjoin_ffi::receive::PsbtInputError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiReplyableError(pub(crate) RustAutoOpaque<payjoin_ffi::receive::ReplyableError>);

impl From<payjoin_ffi::receive::ReplyableError> for FfiReplyableError {
    fn from(value: payjoin_ffi::receive::ReplyableError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub struct FfiSelectionError(pub(crate) RustAutoOpaque<payjoin_ffi::receive::SelectionError>);

impl From<payjoin_ffi::receive::SelectionError> for FfiSelectionError {
    fn from(value: payjoin_ffi::receive::SelectionError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}
pub struct FfiJsonReply(pub(crate) payjoin_ffi::receive::JsonReply);

impl From<payjoin_ffi::receive::JsonReply> for FfiJsonReply {
    fn from(value: payjoin_ffi::receive::JsonReply) -> Self {
        Self(value)
    }
}

impl From<FfiJsonReply> for payjoin_ffi::receive::JsonReply {
    fn from(value: FfiJsonReply) -> Self {
        value.0
    }
}
