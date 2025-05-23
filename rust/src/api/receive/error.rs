use crate::ffi_opaque_wrapper;

ffi_opaque_wrapper!(FfiError, payjoin_ffi::receive::Error);
ffi_opaque_wrapper!(FfiImplementationError, payjoin_ffi::receive::ImplementationError);
ffi_opaque_wrapper!(FfiSessionError, payjoin_ffi::receive::SessionError);
ffi_opaque_wrapper!(FfiInputContributionError, payjoin_ffi::receive::InputContributionError);
ffi_opaque_wrapper!(FfiOutputSubstitutionError, payjoin_ffi::receive::OutputSubstitutionError);
ffi_opaque_wrapper!(FfiPsbtInputError, payjoin_ffi::receive::PsbtInputError);
ffi_opaque_wrapper!(FfiReplyableError, payjoin_ffi::receive::ReplyableError);
ffi_opaque_wrapper!(FfiSelectionError, payjoin_ffi::receive::SelectionError);

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
