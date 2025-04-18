use flutter_rust_bridge::frb;
use payjoin_ffi::receive::ImplementationError;
use payjoin_ffi::send::{BuildSenderError, CreateRequestError, EncapsulationError, ResponseError, SerdeJsonError};

use crate::api::uri::{FfiPjUri, FfiUrl};
use crate::frb_generated::RustOpaque;
use crate::utils::types::{ClientResponse, Request};

pub struct FfiSenderBuilder(pub RustOpaque<payjoin_ffi::send::SenderBuilder>);
impl From<payjoin_ffi::send::SenderBuilder> for FfiSenderBuilder {
    fn from(value: payjoin_ffi::send::SenderBuilder) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiSenderBuilder {
    pub fn from_psbt_and_uri(
        psbt_base64: String,
        pj_uri: FfiPjUri,
    ) -> Result<FfiSenderBuilder, BuildSenderError> {
        payjoin_ffi::send::SenderBuilder::new(psbt_base64, pj_uri.into())
            .map(Into::into)
            .map_err(Into::into)
    }
    pub fn always_disable_output_substitution(&self) -> FfiSenderBuilder {
        self.0.always_disable_output_substitution().into()
    }
    pub fn build_recommended(&self, min_fee_rate: u64) -> Result<FfiNewSender, BuildSenderError> {
        self.0.build_recommended(min_fee_rate).map(Into::into)
    }
    pub fn build_with_additional_fee(
        &self,
        max_fee_contribution: u64,
        change_index: Option<u8>,
        min_fee_rate: u64,
        clamp_fee_contribution: bool,
    ) -> Result<FfiNewSender, BuildSenderError> {
        self.0
            .build_with_additional_fee(
                max_fee_contribution,
                change_index,
                min_fee_rate,
                clamp_fee_contribution,
            )
            .map(Into::into)
            .map_err(Into::into)
    }

    pub fn build_non_incentivizing(
        &self,
        min_fee_rate: u64,
    ) -> Result<FfiNewSender, BuildSenderError> {
        self.0.build_non_incentivizing(min_fee_rate).map(Into::into)
    }
}

pub struct FfiNewSender(pub RustOpaque<payjoin_ffi::send::NewSender>);
impl From<payjoin_ffi::send::NewSender> for FfiNewSender {
    fn from(value: payjoin_ffi::send::NewSender) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiNewSender {
    pub fn persist(&self) -> Result<FfiSender, ImplementationError> {
        todo!()
    }
}

pub struct FfiSender(pub RustOpaque<payjoin_ffi::send::Sender>);

impl From<payjoin_ffi::send::Sender> for FfiSender {
    fn from(value: payjoin_ffi::send::Sender) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl From<FfiSender> for payjoin_ffi::send::Sender {
    fn from(value: FfiSender) -> Self {
        (*value.0).clone()
    }
}
impl FfiSender {
    pub fn load(_token: String) -> Result<FfiSender, ImplementationError> {
        todo!()
    }

    pub fn extract_v1(&self) -> (Request, FfiV1Context) {
        let (req, ctx) = self.0.extract_v1();
        (req.into(), ctx.into())
    }

    pub fn extract_v2(
        &self,
        ohttp_proxy_url: FfiUrl,
    ) -> Result<(Request, FfiV2PostContext), CreateRequestError> {
        self.0
            .extract_v2(ohttp_proxy_url.into())
            .map(|(req, ctx)| (req.into(), ctx.into()))
    }

    #[frb(sync)]
    pub fn to_json(&self) -> Result<String, SerdeJsonError> {
        self.0.to_json()
    }

    #[frb(sync)]
    pub fn from_json(json: String) -> Result<Self, SerdeJsonError> {
        payjoin_ffi::send::Sender::from_json(&json).map(Into::into)
    }
}

#[derive(Clone)]
pub struct FfiV1Context(pub RustOpaque<payjoin_ffi::send::V1Context>);
impl From<payjoin_ffi::send::V1Context> for FfiV1Context {
    fn from(value: payjoin_ffi::send::V1Context) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiV1Context {
    pub fn process_response(&self, response: Vec<u8>) -> Result<String, ResponseError> {
        self.0.process_response(response).map(Into::into)
    }
}

pub struct FfiV2PostContext(pub RustOpaque<payjoin_ffi::send::V2PostContext>);
impl From<payjoin_ffi::send::V2PostContext> for FfiV2PostContext {
    fn from(value: payjoin_ffi::send::V2PostContext) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiV2PostContext {
    pub fn process_response(
        &self,
        response: &[u8],
    ) -> Result<FfiV2GetContext, EncapsulationError> {
        self.0.clone().process_response(response).map(Into::into)
    }
}

pub struct FfiV2GetContext(pub RustOpaque<payjoin_ffi::send::V2GetContext>);
impl From<payjoin_ffi::send::V2GetContext> for FfiV2GetContext {
    fn from(value: payjoin_ffi::send::V2GetContext) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiV2GetContext {
    pub fn extract_req(
        &self,
        ohttp_relay: String,
    ) -> Result<(Request, ClientResponse), CreateRequestError> {
        self.0
            .extract_req(ohttp_relay)
            .map(|(req, ctx)| (req.into(), ctx.into()))
    }

    pub fn process_response(
        &self,
        response: &[u8],
        ohttp_ctx: &ClientResponse,
    ) -> Result<Option<String>, ResponseError> {
        self.0.process_response(response, &ohttp_ctx.into())
    }
}