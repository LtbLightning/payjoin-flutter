use std::sync::Arc;

use error::{FfiPjNotSupported, FfiPjParseError, FfiUrlParseError};
use flutter_rust_bridge_macros::frb;

use crate::api::ohttp::error::FfiOhttpError;
use crate::frb_generated::RustOpaque;

pub mod error;

#[derive(Debug, Clone)]
pub struct FfiUrl(pub RustOpaque<payjoin_ffi::Url>);
impl From<payjoin_ffi::Url> for FfiUrl {
    fn from(value: payjoin_ffi::Url) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl From<FfiUrl> for payjoin_ffi::Url {
    fn from(value: FfiUrl) -> Self {
        (*value.0).clone()
    }
}

impl FfiUrl {
    #[frb(sync)]
    pub fn parse(url: String) -> Result<Self, FfiUrlParseError> {
        payjoin_ffi::Url::parse(url).map(Into::into).map_err(Into::into)
    }
    #[frb(sync)]
    pub fn query(&self) -> Option<String> {
        self.0.query()
    }
    #[frb(sync)]
    pub fn as_string(&self) -> String {
        self.0.as_string()
    }
}

#[derive(Clone)]
pub struct FfiPjUri(Arc<payjoin_ffi::uri::PjUri>);

impl From<payjoin_ffi::uri::PjUri> for FfiPjUri {
    fn from(value: payjoin_ffi::uri::PjUri) -> Self {
        Self(Arc::new(value))
    }
}
impl From<FfiPjUri> for payjoin_ffi::uri::PjUri {
    fn from(value: FfiPjUri) -> Self {
        (*value.0).clone()
    }
}

impl FfiPjUri {
    #[frb(sync)]
    pub fn address(&self) -> String {
        self.0.clone().address()
    }
    /// Number of btc  requested as payment
    #[frb(sync)]
    pub fn amount_sats(&self) -> Option<u64> {
        self.0.clone().amount_sats()
    }

    #[frb(sync)]
    /// Sets the amount in sats and returns a new FfiPjUri
    pub fn set_amount_sats(&self, amount: u64) -> Self {
        let uri = (*self.0).clone().set_amount_sats(amount);
        FfiPjUri(Arc::new(uri))
    }

    #[frb(sync)]
    pub fn pj_endpoint(&self) -> String {
        self.0.clone().pj_endpoint()
    }

    #[frb(sync)]
    pub fn as_string(&self) -> String {
        self.0.clone().as_string()
    }
}

#[derive(Clone)]
pub struct FfiUri(pub RustOpaque<payjoin_ffi::uri::Uri>);
impl From<payjoin_ffi::uri::Uri> for FfiUri {
    fn from(value: payjoin_ffi::uri::Uri) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiUri {
    #[frb(sync)]
    pub fn parse(uri: String) -> Result<FfiUri, FfiPjParseError> {
        payjoin_ffi::uri::Uri::parse(uri).map(Into::into).map_err(Into::into)
    }
    #[frb(sync)]
    pub fn address(&self) -> String {
        self.0.address()
    }
    #[frb(sync)]
    /// Gets the amount in sats.
    pub fn amount_sats(&self) -> Option<u64> {
        self.0.amount_sats()
    }
    #[frb(sync)]
    pub fn as_string(&self) -> String {
        self.0.as_string()
    }
    #[frb(sync)]
    pub fn check_pj_supported(&self) -> Result<FfiPjUri, FfiPjNotSupported> {
        self.0.check_pj_supported().map(|e| e.into()).map_err(Into::into)
    }
}

pub struct FfiOhttpKeys(pub RustOpaque<payjoin_ffi::OhttpKeys>);

impl From<FfiOhttpKeys> for payjoin_ffi::OhttpKeys {
    fn from(value: FfiOhttpKeys) -> Self {
        (*value.0).clone()
    }
}
impl From<payjoin_ffi::OhttpKeys> for FfiOhttpKeys {
    fn from(value: payjoin_ffi::OhttpKeys) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiOhttpKeys {
    pub fn decode(bytes: Vec<u8>) -> Result<Self, FfiOhttpError> {
        payjoin_ffi::OhttpKeys::decode(bytes).map(Into::into).map_err(Into::into)
    }
}
