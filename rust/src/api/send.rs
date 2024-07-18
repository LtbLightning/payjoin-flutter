use crate::api::uri::{FfiPjUri, FfiUrl};
use crate::{ frb_generated::RustOpaque};
use std::sync::Arc;

use super::receive::PayjoinError;

pub struct FfiRequestBuilder(pub RustOpaque<payjoin_ffi::send::v1::RequestBuilder>);
impl From<payjoin_ffi::send::v1::RequestBuilder> for FfiRequestBuilder {
    fn from(value: payjoin_ffi::send::v1::RequestBuilder) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiRequestBuilder {
    pub fn from_psbt_and_uri(
        psbt_base64: String,
        pj_uri: FfiPjUri,
    ) -> anyhow::Result<FfiRequestBuilder, PayjoinError> {
        match payjoin_ffi::send::v1::RequestBuilder::from_psbt_and_uri(
            psbt_base64,
            Arc::new((*pj_uri.0).clone()),
        ) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
    pub fn always_disable_output_substitution(&self, disable: bool) -> FfiRequestBuilder {
        (*self.0
            .clone()
            .always_disable_output_substitution(disable)).clone()
            .into()
    }
    pub fn build_recommended(
        &self,
        min_fee_rate: u64,
    ) -> anyhow::Result<FfiRequestContext, PayjoinError> {
        match self.0.build_recommended(min_fee_rate) {
            Ok(e) => Ok((*e).clone().into()),
            Err(e) => Err(e.into()),
        }
    }
    pub fn build_with_additional_fee(
        &self,
        max_fee_contribution: u64,
        change_index: Option<u8>,
        min_fee_rate: u64,
        clamp_fee_contribution: bool,
    ) -> anyhow::Result<FfiRequestContext, PayjoinError> {
        match self.0.build_with_additional_fee(
            max_fee_contribution,
            change_index,
            min_fee_rate,
            clamp_fee_contribution,
        ) {
            Ok(e) =>Ok((*e).clone().into()),
            Err(e) => Err(e.into()),
        }
    }
    pub fn build_non_incentivizing(&self, min_fee_rate: u64) -> anyhow::Result<FfiRequestContext, PayjoinError> {
        match self.0.clone().build_non_incentivizing(min_fee_rate) {
            Ok(e) => Ok((*e).clone().into()),
            Err(e) => Err(e.into()),
        }
    }
}
pub struct FfiRequestContext(pub RustOpaque<payjoin_ffi::send::v1::RequestContext>);
impl From<payjoin_ffi::send::v1::RequestContext> for FfiRequestContext {
    fn from(value: payjoin_ffi::send::v1::RequestContext) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl From<FfiRequestContext> for payjoin_ffi::send::v1::RequestContext {
    fn from(value: FfiRequestContext) -> Self {
        (*value.0).clone()
    }
}
impl FfiRequestContext {
    pub fn extract_v1(ptr: Self) -> Result<RequestContextV1, PayjoinError> {
        match ptr.0.extract_v1() {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
    pub fn extract_v2(
        ptr: Self,
        ohttp_proxy_url: FfiUrl,
    ) -> Result<RequestContextV2, PayjoinError> {
        match ptr.0.extract_v2(Arc::new((*ohttp_proxy_url.0).clone())) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
}

#[derive(Clone)]
pub struct RequestContextV1 {
    pub request: (FfiUrl, Vec<u8>),
    pub context_v1: FfiContextV1,
}

impl From<Arc<payjoin_ffi::send::v1::RequestContextV1>> for RequestContextV1 {
    fn from(value: Arc<payjoin_ffi::send::v1::RequestContextV1>) -> Self {
        Self {
            request: (
                (*value.request.url).clone().into(),
                value.request.body.clone(),
            ),
            context_v1: (*value.context_v1).clone().into(),
        }
    }
}

impl From<payjoin_ffi::send::v1::RequestContextV1> for RequestContextV1 {
    fn from(value: payjoin_ffi::send::v1::RequestContextV1) -> Self {
        Self {
            request: ((*value.request.url).clone().into(), value.request.body),
            context_v1:(*value.context_v1).clone().into(),
        }
    }
}
pub struct RequestContextV2 {
    pub request: (FfiUrl, Vec<u8>),
    pub context_v2: FfiContextV2,
}

impl From<payjoin_ffi::send::v1::RequestContextV2> for RequestContextV2 {
    fn from(value: payjoin_ffi::send::v1::RequestContextV2) -> Self {
        Self {
            request: ((*value.request.url).clone().into(), value.request.body),
            context_v2: value.context_v2.into(),
        }
    }
}
#[derive(Clone)]
pub struct FfiContextV1(pub RustOpaque<payjoin_ffi::send::v1::ContextV1>);
impl From<payjoin_ffi::send::v1::ContextV1> for FfiContextV1 {
    fn from(value: payjoin_ffi::send::v1::ContextV1) -> Self {
        Self(RustOpaque::new(value))
    }
}


impl FfiContextV1 {
    pub fn process_response(&self, response: Vec<u8>) -> anyhow::Result<String, PayjoinError> {
        match self.0.process_response(response) {
            Ok(e) => Ok(e),
            Err(e) => Err(e.into()),
        }
    }
}

pub struct FfiContextV2(pub RustOpaque<Arc<payjoin_ffi::send::v2::ContextV2>>);
impl From<Arc<payjoin_ffi::send::v2::ContextV2>> for FfiContextV2 {
    fn from(value: Arc<payjoin_ffi::send::v2::ContextV2>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiContextV2 {
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
