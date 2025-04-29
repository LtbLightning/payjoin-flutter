pub mod bitcoin_ffi;
pub mod io;
pub mod receive;
pub mod send;
pub mod uri;

use crate::frb_generated::RustAutoOpaque;

pub struct FfiSerdeJsonError(pub(crate) RustAutoOpaque<payjoin_ffi::error::SerdeJsonError>);

impl From<payjoin_ffi::error::SerdeJsonError> for FfiSerdeJsonError {
    fn from(value: payjoin_ffi::error::SerdeJsonError) -> Self {
        Self(RustAutoOpaque::new(value))
    }
}

pub mod ohttp {
    pub mod error {
        use crate::frb_generated::RustAutoOpaque;

        pub struct FfiOhttpError(pub(crate) RustAutoOpaque<payjoin_ffi::ohttp::error::OhttpError>);

        impl From<payjoin_ffi::ohttp::error::OhttpError> for FfiOhttpError {
            fn from(value: payjoin_ffi::ohttp::error::OhttpError) -> Self {
                Self(RustAutoOpaque::new(value))
            }
        }
    }
}
