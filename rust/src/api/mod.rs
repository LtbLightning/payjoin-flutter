pub mod bitcoin_ffi;
pub mod io;
pub mod receive;
pub mod send;
pub mod uri;

#[macro_export]
macro_rules! ffi_opaque_wrapper {
    ($wrapper:ident, $inner:path) => {
        pub struct $wrapper(pub(crate) crate::frb_generated::RustAutoOpaque<$inner>);
        impl From<$inner> for $wrapper {
            fn from(value: $inner) -> Self {
                Self(crate::frb_generated::RustAutoOpaque::new(value))
            }
        }
    };
}

ffi_opaque_wrapper!(FfiSerdeJsonError, payjoin_ffi::error::SerdeJsonError);

pub mod ohttp {
    pub mod error {
        ffi_opaque_wrapper!(FfiOhttpError, payjoin_ffi::ohttp::error::OhttpError);
    }
}
