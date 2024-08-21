use std::collections::HashMap;
pub use std::sync::Arc;

use flutter_rust_bridge::{frb, DartFnFuture};

use crate::api::uri::{FfiOhttpKeys, FfiPjUriBuilder, FfiUrl};
use crate::frb_generated::RustOpaque;
pub use crate::utils::error::PayjoinError;
use crate::utils::types::{ClientResponse, Headers, OutPoint, Request, TxOut};

pub struct FfiUncheckedProposal(pub RustOpaque<payjoin_ffi::receive::v1::UncheckedProposal>);
impl From<payjoin_ffi::receive::v1::UncheckedProposal> for FfiUncheckedProposal {
    fn from(value: payjoin_ffi::receive::v1::UncheckedProposal) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiUncheckedProposal {
    pub fn from_request(
        body: Vec<u8>,
        query: String,
        headers: Headers,
    ) -> Result<FfiUncheckedProposal, PayjoinError> {
        match payjoin_ffi::receive::v1::UncheckedProposal::from_request(
            body,
            query,
            Arc::new(headers.into()),
        ) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }

    /// The Sender’s Original PSBT
    pub fn extract_tx_to_schedule_broadcast(&self) -> Vec<u8> {
        self.0.extract_tx_to_schedule_broadcast()
    }

    /// Call after checking that the Original PSBT can be broadcast.
    ///
    /// Receiver MUST check that the Original PSBT from the sender can be broadcast, i.e. testmempoolaccept bitcoind rpc returns { “allowed”: true,.. } for get_transaction_to_check_broadcast() before calling this method.
    ///
    /// Do this check if you generate bitcoin uri to receive Payjoin on sender request without manual human approval, like a payment processor. Such so called “non-interactive” receivers are otherwise vulnerable to probing attacks. If a sender can make requests at will, they can learn which bitcoin the receiver owns at no cost. Broadcasting the Original PSBT after some time in the failure case makes incurs sender cost and prevents probing.
    ///
    /// Call this after checking downstream.
    pub fn check_broadcast_suitability(
        &self,
        min_fee_rate: Option<u64>,
        can_broadcast: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<FfiMaybeInputsOwned, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_broadcast_suitability(min_fee_rate, |x| {
                Ok(runtime.block_on(can_broadcast(x.clone())))
            })
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
    /// Call this method if the only way to initiate a Payjoin with this receiver requires manual intervention, as in most consumer wallets.
    ///
    /// So-called “non-interactive” receivers, like payment processors, that allow arbitrary requests are otherwise vulnerable to probing attacks. Those receivers call get_transaction_to_check_broadcast() and attest_tested_and_scheduled_broadcast() after making those checks downstream.
    pub fn assume_interactive_receiver(&self) -> FfiMaybeInputsOwned {
        (*self.0.assume_interactive_receiver()).clone().into()
    }
}

pub struct FfiMaybeInputsOwned(pub RustOpaque<payjoin_ffi::receive::v1::MaybeInputsOwned>);
impl From<payjoin_ffi::receive::v1::MaybeInputsOwned> for FfiMaybeInputsOwned {
    fn from(value: payjoin_ffi::receive::v1::MaybeInputsOwned) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiMaybeInputsOwned {
    pub fn check_inputs_not_owned(
        &self,
        is_owned: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<FfiMaybeMixedInputScripts, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_inputs_not_owned(|o| Ok(runtime.block_on(is_owned(o.clone()))))
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
}
pub struct FfiMaybeMixedInputScripts(
    pub RustOpaque<payjoin_ffi::receive::v1::MaybeMixedInputScripts>,
);
impl From<payjoin_ffi::receive::v1::MaybeMixedInputScripts> for FfiMaybeMixedInputScripts {
    fn from(value: payjoin_ffi::receive::v1::MaybeMixedInputScripts) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiMaybeMixedInputScripts {
    pub fn check_no_mixed_input_scripts(&self) -> Result<FfiMaybeInputsSeen, PayjoinError> {
        self.0
            .clone()
            .check_no_mixed_input_scripts()
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
}
pub struct FfiMaybeInputsSeen(pub RustOpaque<payjoin_ffi::receive::v1::MaybeInputsSeen>);
impl From<payjoin_ffi::receive::v1::MaybeInputsSeen> for FfiMaybeInputsSeen {
    fn from(value: payjoin_ffi::receive::v1::MaybeInputsSeen) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiMaybeInputsSeen {
    pub fn check_no_inputs_seen_before(
        &self,
        is_known: impl Fn(OutPoint) -> DartFnFuture<bool>,
    ) -> Result<FfiOutputsUnknown, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_no_inputs_seen_before(|o| Ok(runtime.block_on(is_known(o.into()))))
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
}

pub struct FfiOutputsUnknown(pub RustOpaque<payjoin_ffi::receive::v1::OutputsUnknown>);
impl From<payjoin_ffi::receive::v1::OutputsUnknown> for FfiOutputsUnknown {
    fn from(value: payjoin_ffi::receive::v1::OutputsUnknown) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl FfiOutputsUnknown {
    pub fn identify_receiver_outputs(
        &self,
        is_receiver_output: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<FfiProvisionalProposal, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .identify_receiver_outputs(|o| Ok(runtime.block_on(is_receiver_output(o.clone()))))
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}

pub struct FfiProvisionalProposal(pub RustOpaque<payjoin_ffi::receive::v1::ProvisionalProposal>);
impl From<payjoin_ffi::receive::v1::ProvisionalProposal> for FfiProvisionalProposal {
    fn from(value: payjoin_ffi::receive::v1::ProvisionalProposal) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiProvisionalProposal {
    pub fn try_substitute_receiver_output(
        &self,
        generate_script: impl Fn() -> DartFnFuture<Vec<u8>>,
    ) -> Result<(), PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .try_substitute_receiver_output(|| Ok(runtime.block_on(generate_script())))
            .map_err(|e| e.into())
    }
    pub fn contribute_witness_input(
        &self,
        txo: TxOut,
        outpoint: OutPoint,
    ) -> Result<(), PayjoinError> {
        self.0.contribute_witness_input(txo.into(), outpoint.into()).map_err(|e| e.into())
    }

    pub fn try_preserving_privacy(
        &self,
        candidate_inputs: HashMap<u64, OutPoint>,
    ) -> Result<OutPoint, PayjoinError> {
        let candidate_inputs: HashMap<u64, payjoin_ffi::types::OutPoint> =
            candidate_inputs.into_iter().map(|(key, value)| (key, value.into())).collect();
        self.0.try_preserving_privacy(candidate_inputs).map_err(|e| e.into()).map(|o| (&o).into())
    }

    pub fn finalize_proposal(
        &self,
        process_psbt: impl Fn(String) -> DartFnFuture<String>,
        min_fee_rate_sat_per_vb: Option<u64>,
    ) -> Result<FfiPayjoinProposal, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .finalize_proposal(
                |o| Ok(runtime.block_on(process_psbt(o.clone()))),
                min_fee_rate_sat_per_vb,
            )
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
    pub(crate) fn _finalize_proposal(
        ptr: Self,
        process_psbt: impl Fn(String) -> Result<String, PayjoinError>,
        min_fee_rate_sat_per_vb: Option<u64>,
    ) -> Result<FfiPayjoinProposal, PayjoinError> {
        ptr.0
            .finalize_proposal(
                |o| process_psbt(o.clone()).map_err(|e| e.into()),
                min_fee_rate_sat_per_vb,
            )
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
}

pub struct FfiPayjoinProposal(pub RustOpaque<payjoin_ffi::receive::v1::PayjoinProposal>);
impl From<payjoin_ffi::receive::v1::PayjoinProposal> for FfiPayjoinProposal {
    fn from(value: payjoin_ffi::receive::v1::PayjoinProposal) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiPayjoinProposal {
    pub fn utxos_to_be_locked(&self) -> Vec<OutPoint> {
        self.0.utxos_to_be_locked().iter().map(|x| x.into()).collect()
    }
    pub fn is_output_substitution_disabled(&self) -> bool {
        self.0.is_output_substitution_disabled()
    }
    pub fn owned_vouts(&self) -> Vec<u64> {
        self.0.owned_vouts().to_vec()
    }
    pub fn psbt(&self) -> String {
        self.0.psbt()
    }
}

#[derive(Clone, Debug)]
pub struct FfiSessionInitializer(pub RustOpaque<payjoin_ffi::receive::v2::SessionInitializer>);

impl From<payjoin_ffi::receive::v2::SessionInitializer> for FfiSessionInitializer {
    fn from(value: payjoin_ffi::receive::v2::SessionInitializer) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiSessionInitializer {
    pub fn new(
        address: String,
        expire_after: Option<u64>,
        network: crate::utils::types::Network,
        directory: FfiUrl,
        ohttp_keys: FfiOhttpKeys,
        ohttp_relay: FfiUrl,
    ) -> Result<Self, PayjoinError> {
        Ok(payjoin_ffi::receive::v2::SessionInitializer::new(
            address,
            expire_after,
            network,
            directory.into(),
            (*ohttp_keys.0).clone().into(),
            ohttp_relay.into(),
        )?
        .into())
    }

    pub fn extract_req(&self) -> Result<(Request, ClientResponse), PayjoinError> {
        self.0.extract_req().map(|e| (e.0.into(), e.1.into())).map_err(|e| e.into())
    }
    pub fn process_res(
        &self,
        body: Vec<u8>,
        ctx: ClientResponse,
    ) -> Result<FfiActiveSession, PayjoinError> {
        self.0.process_res(body, ctx.into()).map(|e| e.into()).map_err(|e| e.into())
    }
}
#[derive(Clone, Debug)]
pub struct FfiActiveSession(pub RustOpaque<payjoin_ffi::receive::v2::ActiveSession>);

impl From<payjoin_ffi::receive::v2::ActiveSession> for FfiActiveSession {
    fn from(value: payjoin_ffi::receive::v2::ActiveSession) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiActiveSession {
    ///The per-session public key to use as an identifier
    #[frb(sync)]
    pub fn public_key(&self) -> String {
        self.0.public_key()
    }

    pub fn pj_url(&self) -> FfiUrl {
        self.0.pj_url().into()
    }
    #[frb(sync)]
    pub fn pj_uri_builder(&self) -> FfiPjUriBuilder {
        self.0.pj_uri_builder().into()
    }
    pub fn extract_req(&self) -> Result<(Request, ClientResponse), PayjoinError> {
        self.0.extract_req().map(|e| (e.0.into(), e.1.into())).map_err(|e| e.into())
    }
    pub fn process_res(
        &self,
        body: Vec<u8>,
        ctx: ClientResponse,
    ) -> Result<Option<FfiV2UncheckedProposal>, PayjoinError> {
        self.0.process_res(body, ctx.into()).map(|e| e.map(|o| o.into())).map_err(|e| e.into())
    }
}

#[derive(Clone)]
pub struct FfiV2UncheckedProposal(pub RustOpaque<payjoin_ffi::receive::v2::V2UncheckedProposal>);
impl From<payjoin_ffi::receive::v2::V2UncheckedProposal> for FfiV2UncheckedProposal {
    fn from(value: payjoin_ffi::receive::v2::V2UncheckedProposal) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiV2UncheckedProposal {
    ///The Sender’s Original PSBT
    pub fn extract_tx_to_schedule_broadcast(&self) -> Vec<u8> {
        self.0.extract_tx_to_schedule_broadcast()
    }
    /// Call after checking that the Original PSBT can be broadcast.
    ///
    /// Receiver MUST check that the Original PSBT from the sender can be broadcast, i.e. testmempoolaccept bitcoind rpc returns { “allowed”: true,.. } for get_transaction_to_check_broadcast() before calling this method.
    ///
    /// Do this check if you generate bitcoin uri to receive Payjoin on sender request without manual human approval, like a payment processor. Such so called “non-interactive” receivers are otherwise vulnerable to probing attacks. If a sender can make requests at will, they can learn which bitcoin the receiver owns at no cost. Broadcasting the Original PSBT after some time in the failure case makes incurs sender cost and prevents probing.
    ///
    /// Call this after checking downstream.
    pub fn check_broadcast_suitability(
        &self,
        min_fee_rate: Option<u64>,
        can_broadcast: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<FfiV2MaybeInputsOwned, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_broadcast_suitability(min_fee_rate, |x| {
                Ok(runtime.block_on(can_broadcast(x.clone())))
            })
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
    /// Call this method if the only way to initiate a Payjoin with this receiver
    /// requires manual intervention, as in most consumer wallets.
    ///
    /// So-called "non-interactive" receivers, like payment processors, that allow arbitrary requests are otherwise vulnerable to probing attacks.
    /// Those receivers call `extract_tx_to_check_broadcast()` and `attest_tested_and_scheduled_broadcast()` after making those checks downstream.
    pub fn assume_interactive_receiver(&self) -> FfiV2MaybeInputsOwned {
        (*self.0.clone().assume_interactive_receiver()).clone().into()
    }
}
#[derive(Clone)]
pub struct FfiV2MaybeInputsOwned(pub RustOpaque<payjoin_ffi::receive::v2::V2MaybeInputsOwned>);

impl From<payjoin_ffi::receive::v2::V2MaybeInputsOwned> for FfiV2MaybeInputsOwned {
    fn from(value: payjoin_ffi::receive::v2::V2MaybeInputsOwned) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiV2MaybeInputsOwned {
    ///Check that the Original PSBT has no receiver-owned inputs. Return original-psbt-rejected error or otherwise refuse to sign undesirable inputs.
    /// An attacker could try to spend receiver's own inputs. This check prevents that.
    pub fn check_inputs_not_owned(
        &self,
        is_owned: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<FfiV2MaybeMixedInputScripts, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_inputs_not_owned(|o| Ok(runtime.block_on(is_owned(o.clone()))))
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
}

pub struct FfiV2MaybeMixedInputScripts(
    pub RustOpaque<payjoin_ffi::receive::v2::V2MaybeMixedInputScripts>,
);

impl From<payjoin_ffi::receive::v2::V2MaybeMixedInputScripts> for FfiV2MaybeMixedInputScripts {
    fn from(value: payjoin_ffi::receive::v2::V2MaybeMixedInputScripts) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiV2MaybeMixedInputScripts {
    /// Verify the original transaction did not have mixed input types
    /// Call this after checking downstream.
    ///
    /// Note: mixed spends do not necessarily indicate distinct wallet fingerprints.
    /// This check is intended to prevent some types of wallet fingerprinting.
    pub fn check_no_mixed_input_scripts(&self) -> Result<FfiV2MaybeInputsSeen, PayjoinError> {
        self.0
            .clone()
            .check_no_mixed_input_scripts()
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
}
pub struct FfiV2MaybeInputsSeen(pub RustOpaque<payjoin_ffi::receive::v2::V2MaybeInputsSeen>);

impl From<payjoin_ffi::receive::v2::V2MaybeInputsSeen> for FfiV2MaybeInputsSeen {
    fn from(value: payjoin_ffi::receive::v2::V2MaybeInputsSeen) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiV2MaybeInputsSeen {
    /// Make sure that the original transaction inputs have never been seen before.
    /// This prevents probing attacks. This prevents reentrant Payjoin, where a sender
    /// proposes a Payjoin PSBT as a new Original PSBT for a new Payjoin.
    pub fn check_no_inputs_seen_before(
        &self,
        is_known: impl Fn(OutPoint) -> DartFnFuture<bool>,
    ) -> Result<FfiV2OutputsUnknown, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_no_inputs_seen_before(|o| Ok(runtime.block_on(is_known(o.into()))))
            .map(|e| (*e).clone().into())
            .map_err(|e| e.into())
    }
}

pub struct FfiV2OutputsUnknown(pub RustOpaque<payjoin_ffi::receive::v2::V2OutputsUnknown>);

impl From<payjoin_ffi::receive::v2::V2OutputsUnknown> for FfiV2OutputsUnknown {
    fn from(value: payjoin_ffi::receive::v2::V2OutputsUnknown) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiV2OutputsUnknown {
    /// Find which outputs belong to the receiver
    pub fn identify_receiver_outputs(
        &self,
        is_receiver_output: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<FfiV2ProvisionalProposal, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .identify_receiver_outputs(|o| Ok(runtime.block_on(is_receiver_output(o.clone()))))
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}
pub struct FfiV2ProvisionalProposal(
    pub RustOpaque<payjoin_ffi::receive::v2::V2ProvisionalProposal>,
);
impl From<payjoin_ffi::receive::v2::V2ProvisionalProposal> for FfiV2ProvisionalProposal {
    fn from(value: payjoin_ffi::receive::v2::V2ProvisionalProposal) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiV2ProvisionalProposal {
    pub fn is_output_substitution_disabled(&self) -> bool {
        self.0.is_output_substitution_disabled()
    }
    pub fn try_substitute_receiver_output(
        &self,
        generate_script: impl Fn() -> DartFnFuture<Vec<u8>>,
    ) -> Result<(), PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .try_substitute_receiver_output(|| Ok(runtime.block_on(generate_script())))
            .map_err(|e| e.into())
    }
    pub fn contribute_witness_input(
        &self,
        txo: TxOut,
        outpoint: OutPoint,
    ) -> Result<(), PayjoinError> {
        self.0.contribute_witness_input(txo.into(), outpoint.into()).map_err(|e| e.into())
    }

    /// Select receiver input such that the common.dart avoids surveillance. Return the input chosen that has been applied to the Proposal.
    ///
    /// Proper coin selection allows common.dart to resemble ordinary transactions. To ensure the resemblance, a number of heuristics must be avoided.
    ///
    /// UIH “Unnecessary input heuristic” is one class of them to avoid. We define UIH1 and UIH2 according to the BlockSci practice BlockSci UIH1 and UIH2:
    pub fn try_preserving_privacy(
        &self,
        candidate_inputs: HashMap<u64, OutPoint>,
    ) -> Result<OutPoint, PayjoinError> {
        let candidate_inputs: HashMap<u64, payjoin_ffi::types::OutPoint> =
            candidate_inputs.into_iter().map(|(key, value)| (key, value.into())).collect();
        self.0.try_preserving_privacy(candidate_inputs).map_err(|e| e.into()).map(|o| (&o).into())
    }

    pub fn finalize_proposal(
        &self,
        process_psbt: impl Fn(String) -> DartFnFuture<String>,
        min_fee_rate_sat_per_vb: Option<u64>,
    ) -> Result<FfiV2PayjoinProposal, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .finalize_proposal(
                |o| Ok(runtime.block_on(process_psbt(o.clone()))),
                min_fee_rate_sat_per_vb,
            )
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}
pub struct FfiV2PayjoinProposal(pub RustOpaque<Arc<payjoin_ffi::receive::v2::V2PayjoinProposal>>);
impl From<Arc<payjoin_ffi::receive::v2::V2PayjoinProposal>> for FfiV2PayjoinProposal {
    fn from(value: Arc<payjoin_ffi::receive::v2::V2PayjoinProposal>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl FfiV2PayjoinProposal {
    pub fn utxos_to_be_locked(&self) -> Vec<OutPoint> {
        self.0.utxos_to_be_locked().iter().map(|x| x.into()).collect()
    }
    pub fn is_output_substitution_disabled(&self) -> bool {
        self.0.is_output_substitution_disabled()
    }
    pub fn owned_vouts(&self) -> Vec<u64> {
        self.0.owned_vouts().to_vec()
    }
    pub fn psbt(&self) -> String {
        self.0.psbt()
    }
    pub fn extract_v1_req(&self) -> String {
        self.0.extract_v1_req()
    }
    pub fn extract_v2_req(&self) -> Result<(Request, ClientResponse), PayjoinError> {
        self.0.clone().extract_v2_req().map(|e| (e.0.into(), e.1.into())).map_err(|e| e.into())
    }

    pub fn process_res(
        &self,
        res: Vec<u8>,
        ohttp_context: ClientResponse,
    ) -> Result<(), PayjoinError> {
        self.0.process_res(res, ohttp_context.into()).map_err(|e| e.into())
    }
}
