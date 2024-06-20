use crate::frb_generated::RustOpaque;
use crate::utils::error::PayjoinError;
use std::sync::Arc;

#[derive(Clone, Debug)]
pub struct Url(pub RustOpaque<Arc<payjoin_ffi::uri::Url>>);
impl From<payjoin_ffi::uri::Url> for Url {
    fn from(value: payjoin_ffi::uri::Url) -> Self {
        Self(RustOpaque::new(Arc::new(value)))
    }
}
impl From<Arc<payjoin_ffi::uri::Url>> for Url {
    fn from(value: Arc<payjoin_ffi::uri::Url>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl Url {
    pub fn from_str(url: String) -> anyhow::Result<Url, PayjoinError> {
        match payjoin_ffi::uri::Url::from_str(url) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
    pub fn query(&self) -> Option<String> {
        self.0.query()
    }
    pub fn as_string(&self) -> String {
        self.0.as_string()
    }
}


#[derive(Clone)]
pub struct Uri(pub RustOpaque<Arc<payjoin_ffi::uri::Uri>>);
impl From<payjoin_ffi::uri::Uri> for Uri {
    fn from(value: payjoin_ffi::uri::Uri) -> Self {
        Self(RustOpaque::new(Arc::new(value)))
    }
}
impl From<Arc<payjoin_ffi::uri::Uri>> for Uri {
    fn from(value: Arc<payjoin_ffi::uri::Uri>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl Uri {
    pub fn from_str(uri: String) -> anyhow::Result<Uri, PayjoinError> {
        match payjoin_ffi::uri::Uri::from_str(uri) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(PayjoinError::PjParseError {
                message: e.to_string(),
            }),
        }
    }
    pub fn address(&self) -> String {
        self.0.address()
    }
    ///Gets the amount in btc.
    pub fn amount(&self) -> Option<f64> {
        self.0.amount()
    }
}
pub struct OhttpKeys(pub RustOpaque<payjoin_ffi::types::OhttpKeys>);

impl From<OhttpKeys>  for payjoin_ffi::types::OhttpKeys{
    fn from(value: OhttpKeys) -> Self {
        (*value.0).clone()
    }
}
impl From<payjoin_ffi::types::OhttpKeys>  for OhttpKeys{
    fn from(value:payjoin_ffi::types:: OhttpKeys) -> Self {
       Self(RustOpaque::new(value))
    }
}

impl OhttpKeys {
    pub fn decode(bytes: Vec<u8>) -> Result<Self, PayjoinError> {
         payjoin_ffi::types::OhttpKeys::decode(bytes).map(|e| e.into()).map_err(|e| e.into())
    }
    
}
