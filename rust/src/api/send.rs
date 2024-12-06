use super::receive::PayjoinError;
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
    ) -> anyhow::Result<FfiSenderBuilder, PayjoinError> {
        payjoin_ffi::send::SenderBuilder::from_psbt_and_uri(psbt_base64, pj_uri.into())
            .map(Into::into)
            .map_err(Into::into)
    }
    pub fn always_disable_output_substitution(&self, disable: bool) -> FfiSenderBuilder {
        self.0.always_disable_output_substitution(disable).into()
    }
    pub fn build_recommended(&self, min_fee_rate: u64) -> anyhow::Result<FfiSender, PayjoinError> {
        self.0.build_recommended(min_fee_rate).map(Into::into).map_err(Into::into)
    }
    pub fn build_with_additional_fee(
        &self,
        max_fee_contribution: u64,
        change_index: Option<u8>,
        min_fee_rate: u64,
        clamp_fee_contribution: bool,
    ) -> anyhow::Result<FfiSender, PayjoinError> {
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
    ) -> anyhow::Result<FfiSender, PayjoinError> {
        self.0.build_non_incentivizing(min_fee_rate).map(Into::into).map_err(Into::into)
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
    pub fn extract_v1(&self) -> Result<(Request, FfiV1Context), PayjoinError> {
        self.0.extract_v1().map(|(req, ctx)| (req.into(), ctx.into())).map_err(Into::into)
    }

    pub fn extract_v2(
        &self,
        ohttp_proxy_url: FfiUrl,
    ) -> Result<(Request, FfiV2PostContext), PayjoinError> {
        self.0
            .extract_v2(ohttp_proxy_url.into())
            .map(|(req, ctx)| (req.into(), ctx.into()))
            .map_err(Into::into)
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
    pub fn process_response(&self, response: Vec<u8>) -> anyhow::Result<String, PayjoinError> {
        match self.0.process_response(response) {
            Ok(e) => Ok(e),
            Err(e) => Err(e.into()),
        }
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
    ) -> anyhow::Result<FfiV2GetContext, PayjoinError> {
        self.0.clone().process_response(response).map(Into::into).map_err(Into::into)
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
        ohttp_relay: FfiUrl,
    ) -> Result<(Request, ClientResponse), PayjoinError> {
        self.0
            .extract_req(ohttp_relay.into())
            .map(|(req, ctx)| (req.into(), ctx.into()))
            .map_err(Into::into)
    }

    pub fn process_response(
        &self,
        response: &[u8],
        ohttp_ctx: &ClientResponse,
    ) -> anyhow::Result<Option<String>, PayjoinError> {
        self.0.process_response(response, &ohttp_ctx.into()).map_err(Into::into)
    }
}