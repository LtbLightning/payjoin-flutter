use std::sync::Arc;

use error::{FfiBuildSenderError, FfiCreateRequestError, FfiEncapsulationError, FfiResponseError};
use flutter_rust_bridge::{frb, DartFnFuture};
use payjoin::persist::Persister;
use payjoin::send::v2 as inner;

use super::receive::error::FfiImplementationError;
use super::FfiSerdeJsonError;
use crate::api::uri::{FfiPjUri, FfiUrl};
use crate::frb_generated::RustOpaque;
use crate::utils::types::{ClientResponse, Request};

pub mod error;

pub struct FfiSenderBuilder(pub(crate) RustOpaque<payjoin_ffi::send::SenderBuilder>);
impl From<payjoin_ffi::send::SenderBuilder> for FfiSenderBuilder {
    fn from(value: payjoin_ffi::send::SenderBuilder) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiSenderBuilder {
    pub fn from_psbt_and_uri(
        psbt_base64: String,
        pj_uri: FfiPjUri,
    ) -> Result<FfiSenderBuilder, FfiBuildSenderError> {
        payjoin_ffi::send::SenderBuilder::new(psbt_base64, pj_uri.into())
            .map(Into::into)
            .map_err(Into::into)
    }
    pub fn always_disable_output_substitution(&self) -> FfiSenderBuilder {
        self.0.always_disable_output_substitution().into()
    }
    pub fn build_recommended(
        &self,
        min_fee_rate: u64,
    ) -> Result<FfiNewSender, FfiBuildSenderError> {
        self.0.build_recommended(min_fee_rate).map(Into::into).map_err(Into::into)
    }
    pub fn build_with_additional_fee(
        &self,
        max_fee_contribution: u64,
        change_index: Option<u8>,
        min_fee_rate: u64,
        clamp_fee_contribution: bool,
    ) -> Result<FfiNewSender, FfiBuildSenderError> {
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
    ) -> Result<FfiNewSender, FfiBuildSenderError> {
        self.0.build_non_incentivizing(min_fee_rate).map(Into::into).map_err(Into::into)
    }
}

pub struct FfiNewSender(pub RustOpaque<payjoin_ffi::send::NewSender>);
impl From<payjoin_ffi::send::NewSender> for FfiNewSender {
    fn from(value: payjoin_ffi::send::NewSender) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiNewSender {
    pub fn persist(
        &self,
        persister: &mut DartSenderPersister,
    ) -> Result<SenderToken, FfiImplementationError> {
        self.0.persist(persister).map(Into::into).map_err(Into::into)
    }
}

#[derive(Clone)]
pub struct FfiSender(pub(crate) payjoin_ffi::send::Sender);

impl From<payjoin_ffi::send::Sender> for FfiSender {
    fn from(value: payjoin_ffi::send::Sender) -> Self {
        Self(value)
    }
}

impl From<FfiSender> for payjoin::send::v2::Sender {
    fn from(value: FfiSender) -> Self {
        payjoin::send::v2::Sender::from(value.0)
    }
}

impl From<FfiSender> for payjoin_ffi::send::Sender {
    fn from(value: FfiSender) -> Self {
        value.0
    }
}
impl FfiSender {
    pub fn load(
        token: SenderToken,
        persister: DartSenderPersister,
    ) -> Result<FfiSender, FfiImplementationError> {
        persister
            .load(token.into())
            .map(|sender| FfiSender::from(payjoin_ffi::send::Sender::from(sender)))
            .map_err(Into::into)
    }

    pub fn extract_v1(&self) -> (Request, FfiV1Context) {
        let (req, ctx) = self.0.extract_v1();
        (req.into(), ctx.into())
    }

    pub fn extract_v2(
        &self,
        ohttp_proxy_url: FfiUrl,
    ) -> Result<(Request, FfiV2PostContext), FfiCreateRequestError> {
        self.0
            .extract_v2(ohttp_proxy_url.into())
            .map(|(req, ctx)| (req.into(), ctx.into()))
            .map_err(Into::into)
    }

    #[frb(sync)]
    pub fn to_json(&self) -> Result<String, FfiSerdeJsonError> {
        self.0.to_json().map_err(Into::into)
    }

    #[frb(sync)]
    pub fn from_json(json: String) -> Result<Self, FfiSerdeJsonError> {
        payjoin_ffi::send::Sender::from_json(&json).map(Into::into).map_err(Into::into)
    }

    #[frb(sync)]
    pub fn key(&self) -> SenderToken {
        self.0.key().into()
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
    pub fn process_response(&self, response: Vec<u8>) -> Result<String, FfiResponseError> {
        self.0.process_response(response).map(Into::into).map_err(Into::into)
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
    ) -> Result<FfiV2GetContext, FfiEncapsulationError> {
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
        ohttp_relay: String,
    ) -> Result<(Request, ClientResponse), FfiCreateRequestError> {
        self.0
            .extract_req(ohttp_relay)
            .map(|(req, ctx)| (req.into(), ctx.into()))
            .map_err(Into::into)
    }

    pub fn process_response(
        &self,
        response: &[u8],
        ohttp_ctx: &ClientResponse,
    ) -> Result<Option<String>, FfiResponseError> {
        self.0.process_response(response, &ohttp_ctx.into()).map_err(Into::into)
    }
}

pub struct SenderToken(pub(crate) Arc<inner::SenderToken>);

impl From<inner::SenderToken> for SenderToken {
    fn from(value: inner::SenderToken) -> Self {
        Self(Arc::new(value))
    }
}

impl From<SenderToken> for inner::SenderToken {
    fn from(value: SenderToken) -> Self {
        (*value.0).clone()
    }
}

impl SenderToken {
    /// Convert the sender token to a byte array
    /// This is most useful when storing the token as a key in a map
    #[frb(sync)]
    pub fn to_bytes(&self) -> Vec<u8> {
        (*self.0).as_ref().to_vec()
    }
}

#[frb(opaque)]
pub struct DartSenderPersister {
    save_cb:
        Box<dyn Fn(FfiSender) -> DartFnFuture<Result<SenderToken, anyhow::Error>> + Send + Sync>,
    load_cb:
        Box<dyn Fn(SenderToken) -> DartFnFuture<Result<FfiSender, anyhow::Error>> + Send + Sync>,
}

impl DartSenderPersister {
    #[frb(sync)]
    pub fn new(
        save: impl Fn(FfiSender) -> DartFnFuture<Result<SenderToken, anyhow::Error>>
            + Send
            + Sync
            + 'static,
        load: impl Fn(SenderToken) -> DartFnFuture<Result<FfiSender, anyhow::Error>>
            + Send
            + Sync
            + 'static,
    ) -> Self {
        Self { save_cb: Box::new(save), load_cb: Box::new(load) }
    }
}

impl payjoin::persist::Persister<payjoin::send::v2::Sender> for DartSenderPersister {
    type Token = inner::SenderToken;
    type Error = payjoin_ffi::receive::ImplementationError;

    fn save(&mut self, sender: payjoin::send::v2::Sender) -> Result<Self::Token, Self::Error> {
        let sender = FfiSender::from(payjoin_ffi::send::Sender::from(sender));
        tokio::runtime::Runtime::new().expect("Failed to create Tokio runtime").block_on(async {
            (self.save_cb)(sender)
                .await
                .map(Into::into)
                .map_err(|e| payjoin_ffi::receive::ImplementationError::from(e.to_string()))
        })
    }

    fn load(&self, token: Self::Token) -> Result<payjoin::send::v2::Sender, Self::Error> {
        tokio::runtime::Runtime::new().expect("Failed to create Tokio runtime").block_on(async {
            (self.load_cb)(token.into())
                .await
                .map(|sender| {
                    let ffi_sender = sender.0;
                    payjoin::send::v2::Sender::from(ffi_sender)
                })
                .map_err(|e| payjoin_ffi::receive::ImplementationError::from(e.to_string()))
        })
    }
}
