use payjoin_ffi::bitcoin_ffi;

use crate::frb_generated::RustOpaque;

#[derive(Clone, Debug)]
pub struct FfiScript(pub RustOpaque<bitcoin_ffi::Script>);

impl FfiScript {
    pub fn new(raw_output_script: Vec<u8>) -> Self {
        Self(RustOpaque::new(bitcoin_ffi::Script::new(raw_output_script)))
    }

    pub fn to_bytes(&self) -> Vec<u8> {
        (*self.0).to_bytes()
    }
}

impl From<bitcoin_ffi::Script> for FfiScript {
    fn from(value: bitcoin_ffi::Script) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl From<&FfiScript> for bitcoin_ffi::Script {
    fn from(value: &FfiScript) -> Self {
        (*value.0).clone()
    }
}