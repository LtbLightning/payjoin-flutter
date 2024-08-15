use crate::frb_generated::RustOpaque;
use crate::utils::error::PayjoinError;
use flutter_rust_bridge::frb;

#[derive(Debug, Clone)]
pub struct FfiUrl(pub RustOpaque<payjoin_ffi::uri::Url>);
impl From<payjoin_ffi::uri::Url> for FfiUrl {
    fn from(value: payjoin_ffi::uri::Url) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiUrl {
    #[frb(sync)]
    pub fn from_str(url: String) -> Result<Self, PayjoinError> {
        match payjoin_ffi::uri::Url::from_str(url) {
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

impl FfiPjUri {
    #[frb(sync)]
    pub fn address(&self) -> String {
        self.0.clone().address()
    }
    /// Number of btc  requested as payment
    #[frb(sync)]
    pub fn amount(&self) -> Option<f64> {
        self.0.clone().amount()
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
        Self {
            internal: RustOpaque::new(value),
        }
    }
}

impl FfiPjUriBuilder {
    pub fn create(
        address: String,
        pj: FfiUrl,
        ohttp_keys: Option<FfiOhttpKeys>,
        expiry: Option<u64>,
    ) -> Result<Self, PayjoinError> {
        payjoin_ffi::uri::PjUriBuilder::new(
            address,
            (*pj.0).clone(),
            ohttp_keys.map(|e| (*e.0).clone()),
            expiry,
        )
        .map_err(|e| e.into())
        .map(|e| e.into())
    }
    ///Accepts the amount you want to receive in sats and sets it in btc.
    #[frb(sync)]
    pub fn amount(&self, amount: u64) -> Self {
        self.internal.amount(amount).into()
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
    pub fn from_str(uri: String) -> anyhow::Result<FfiUri, PayjoinError> {
        match payjoin_ffi::uri::Uri::from_str(uri) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(PayjoinError::PjParseError {
                message: e.to_string(),
            }),
        }
    }
    #[frb(sync)]
    pub fn address(&self) -> String {
        self.0.address()
    }
    #[frb(sync)]
    ///Gets the amount in btc.
    pub fn amount(&self) -> Option<f64> {
        self.0.amount()
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
pub struct FfiOhttpKeys(pub RustOpaque<payjoin_ffi::types::OhttpKeys>);

impl From<FfiOhttpKeys> for payjoin_ffi::types::OhttpKeys {
    fn from(value: FfiOhttpKeys) -> Self {
        (*value.0).clone()
    }
}
impl From<payjoin_ffi::types::OhttpKeys> for FfiOhttpKeys {
    fn from(value: payjoin_ffi::types::OhttpKeys) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiOhttpKeys {
    pub fn decode(bytes: Vec<u8>) -> Result<Self, PayjoinError> {
        payjoin_ffi::types::OhttpKeys::decode(bytes)
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}
#[cfg(test)]
mod tests {
    use crate::api::uri::{FfiPjUriBuilder, FfiUrl};

    #[test]
    fn test_ffi_builder() {
        let https = "https://example.com/";
        let onion = "http://vjdpwgybvubne5hda6v4c5iaeeevhge6jvo3w2cl6eocbwwvwxp7b7qd.onion/";
        let base58 = "12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX";
        let bech32_upper = "TB1Q6D3A2W975YNY0ASUVD9A67NER4NKS58FF0Q8G4";
        let bech32_lower = "tb1q6d3a2w975yny0asuvd9a67ner4nks58ff0q8g4";

        for address in [base58, bech32_upper, bech32_lower] {
            for pj in [https, onion] {
                let builder = FfiPjUriBuilder::create(
                    address.to_string(),
                    FfiUrl::from_str(pj.to_string()).unwrap(),
                    None,
                    None,
                )
                .unwrap();
                let uri = builder
                    .amount(1)
                    .message("message".to_string())
                    .pjos(true)
                    .label("label".to_string())
                    .build();
                // assert_eq!(uri.amount(), Some(bitcoin::Amount::ONE_BTC.to_btc()));
                print!("\n {}", uri.as_string());
                let expected_address = if address == base58 {
                    base58
                } else {
                    bech32_lower
                };
                assert_eq!(
                    uri.as_string(),
                    format!(
                        "bitcoin:{}?amount=0.00000001&label=label&message=message&pj={}&pjos=1",
                        expected_address, pj
                    ),
                );
            }
        }
    }
}
