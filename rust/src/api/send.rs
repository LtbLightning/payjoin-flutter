use crate::{
    api::uri::{Uri, Url},
    frb_generated::RustOpaque,
};
use std::sync::Arc;

use super::receive::PayjoinError;

pub struct RequestBuilder(pub RustOpaque<Arc<payjoin_ffi::send::RequestBuilder>>);
impl From<Arc<payjoin_ffi::send::RequestBuilder>> for RequestBuilder {
    fn from(value: Arc<payjoin_ffi::send::RequestBuilder>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl From<payjoin_ffi::send::RequestBuilder> for RequestBuilder {
    fn from(value: payjoin_ffi::send::RequestBuilder) -> Self {
        Self(RustOpaque::new(Arc::from(value)))
    }
}
impl RequestBuilder {
    pub fn new() {}
    pub fn from_psbt_and_uri(
        psbt_base64: String,
        uri: Uri,
    ) -> anyhow::Result<RequestBuilder, PayjoinError> {
        match payjoin_ffi::send::RequestBuilder::from_psbt_and_uri(psbt_base64, (*uri.0).clone()) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
    pub fn always_disable_output_substitution(&self, disable: bool) -> RequestBuilder {
        self.0
            .clone()
            .always_disable_output_substitution(disable)
            .into()
    }
    pub fn build_recommended(
        &self,
        min_fee_rate: u64,
    ) -> anyhow::Result<RequestContext, PayjoinError> {
        match self.0.build_recommended(min_fee_rate) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
    pub fn build_with_additional_fee(
        &self,
        max_fee_contribution: u64,
        change_index: Option<u8>,
        min_fee_rate: u64,
        clamp_fee_contribution: bool,
    ) -> anyhow::Result<RequestContext, PayjoinError> {
        match self.0.build_with_additional_fee(
            max_fee_contribution,
            change_index,
            min_fee_rate,
            clamp_fee_contribution,
        ) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
    pub fn build_non_incentivizing(&self) -> anyhow::Result<RequestContext, PayjoinError> {
        match self.0.clone().build_non_incentivizing() {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
}
pub struct RequestContext(pub RustOpaque<Arc<payjoin_ffi::send::RequestContext>>);
impl From<payjoin_ffi::send::RequestContext> for RequestContext {
    fn from(value: payjoin_ffi::send::RequestContext) -> Self {
        Self(RustOpaque::new(Arc::from(value)))
    }
}

impl From<Arc<payjoin_ffi::send::RequestContext>> for RequestContext {
    fn from(value: Arc<payjoin_ffi::send::RequestContext>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl From<RequestContext> for payjoin_ffi::send::RequestContext {
    fn from(value: RequestContext) -> Self {
        (**value.0).clone()
    }
}
impl RequestContext {
    pub fn extract_v1(&self) -> Result<RequestContextV1, PayjoinError> {
        match self.0.extract_v1() {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
    pub fn extract_v2(&self, ohttp_proxy_url: String) -> Result<RequestContextV2, PayjoinError> {
        match self.0.extract_v2(ohttp_proxy_url) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
}

///Represents data that needs to be transmitted to the receiver.
///You need to send this request over HTTP(S) to the receiver.
#[derive(Clone, Debug)]
pub struct Request {
    ///URL to send the request to.
    ///
    ///This is full URL with scheme etc - you can pass it right to reqwest or a similar library.
    pub url: Url,
    ///Bytes to be sent to the receiver.
    ///
    ///This is properly encoded PSBT, already in base64. You only need to make sure Content-Type is text/plain and Content-Length is body.len() (most libraries do the latter automatically).
    pub body: Vec<u8>,
}

impl From<Arc<payjoin_ffi::types::Request>> for Request {
    fn from(value: Arc<payjoin_ffi::types::Request>) -> Self {
        Self {
            url: value.url.clone().into(),
            body: value.body.clone(),
        }
    }
}
impl From<payjoin_ffi::types::Request> for Request {
    fn from(value: payjoin_ffi::types::Request) -> Self {
        Self {
            url: value.url.clone().into(),
            body: value.body.clone(),
        }
    }
}
#[derive(Clone)]
pub struct RequestContextV1 {
    pub request: Request,
    pub context_v1: ContextV1,
}

impl From<Arc<payjoin_ffi::send::RequestContextV1>> for RequestContextV1 {
    fn from(value: Arc<payjoin_ffi::send::RequestContextV1>) -> Self {
        Self {
            request: value.request.clone().into(),
            context_v1: value.context_v1.clone().into(),
        }
    }
}

impl From<payjoin_ffi::send::RequestContextV1> for RequestContextV1 {
    fn from(value: payjoin_ffi::send::RequestContextV1) -> Self {
        Self {
            request: value.request.into(),
            context_v1: value.context_v1.into(),
        }
    }
}
pub struct RequestContextV2 {
    pub request: Request,
    pub context_v2: ContextV2,
}

impl From<payjoin_ffi::send::RequestContextV2> for RequestContextV2 {
    fn from(value: payjoin_ffi::send::RequestContextV2) -> Self {
        Self {
            request: value.request.into(),
            context_v2: value.context_v2.into(),
        }
    }
}
#[derive(Clone)]
pub struct ContextV1(pub RustOpaque<Arc<payjoin_ffi::send::ContextV1>>);
impl From<Arc<payjoin_ffi::send::ContextV1>> for ContextV1 {
    fn from(value: Arc<payjoin_ffi::send::ContextV1>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl From<payjoin_ffi::send::ContextV1> for ContextV1 {
    fn from(value: payjoin_ffi::send::ContextV1) -> Self {
        Self(RustOpaque::new(Arc::new(value)))
    }
}

impl ContextV1 {
    pub fn process_response(&self, response: Vec<u8>) -> anyhow::Result<String, PayjoinError> {
        match self.0.process_response(response) {
            Ok(e) => Ok(e),
            Err(e) => Err(e.into()),
        }
    }
}

pub struct ContextV2(pub RustOpaque<Arc<payjoin_ffi::send::v2::ContextV2>>);
impl From<Arc<payjoin_ffi::send::v2::ContextV2>> for ContextV2 {
    fn from(value: Arc<payjoin_ffi::send::v2::ContextV2>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl ContextV2 {
    pub fn process_response(
        &self,
        response: Vec<u8>,
    ) -> anyhow::Result<Option<String>, PayjoinError> {
        match self.0.clone().process_response(response) {
            Ok(e) => Ok(e),
            Err(e) => Err(e.into()),
        }
    }
}
