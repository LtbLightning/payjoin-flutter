use flutter_rust_bridge_macros::frb;

use crate::frb_generated::RustOpaque;
use crate::utils::error::PayjoinError;

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
    pub fn parse(url: String) -> Result<Self, PayjoinError> {
        match payjoin_ffi::Url::parse(url) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
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
pub struct FfiPjUri(pub RustOpaque<payjoin_ffi::uri::PjUri>);

impl From<payjoin_ffi::uri::PjUri> for FfiPjUri {
    fn from(value: payjoin_ffi::uri::PjUri) -> Self {
        Self(RustOpaque::new(value))
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
    pub fn pj_endpoint(&self) -> String {
        self.0.clone().pj_endpoint()
    }

    #[frb(sync)]
    pub fn as_string(&self) -> String {
        self.0.clone().as_string()
    }
}

#[derive(Clone)]
pub struct FfiPjUriBuilder {
    pub internal: RustOpaque<payjoin_ffi::uri::PjUriBuilder>,
}

impl From<payjoin_ffi::uri::PjUriBuilder> for FfiPjUriBuilder {
    fn from(value: payjoin_ffi::uri::PjUriBuilder) -> Self {
        Self { internal: RustOpaque::new(value) }
    }
}

impl FfiPjUriBuilder {
    /// Accepts the amount you want to receive in sats.
    #[frb(sync)]
    pub fn amount_sats(&self, amount: u64) -> Self {
        self.internal.amount_sats(amount).into()
    }

    #[frb(sync)]
    /// Set the message.
    pub fn message(&self, message: String) -> Self {
        self.internal.message(message).into()
    }
    #[frb(sync)]
    ///Set the label.
    pub fn label(&self, label: String) -> Self {
        self.internal.label(label).into()
    }
    ///Set whether payjoin output substitution is allowed.
    #[frb(sync)]
    pub fn pjos(&self, pjos: bool) -> Self {
        self.internal.pjos(pjos).into()
    }
    #[frb(sync)]
    ///Constructs a Uri with PayjoinParams from the parameters set in the builder.
    pub fn build(&self) -> FfiPjUri {
        self.internal.build().into()
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
    pub fn parse(uri: String) -> anyhow::Result<FfiUri, PayjoinError> {
        match payjoin_ffi::uri::Uri::parse(uri) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(PayjoinError::PjParseError { message: e.to_string() }),
        }
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
    pub fn check_pj_supported(&self) -> Result<FfiPjUri, payjoin_ffi::error::PayjoinError> {
        self.0
            .check_pj_supported()
            .map(|e| e.into())
            .map_err(|e| e.into())
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
    pub fn decode(bytes: Vec<u8>) -> Result<Self, PayjoinError> {
        payjoin_ffi::OhttpKeys
            ::decode(bytes)
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}
