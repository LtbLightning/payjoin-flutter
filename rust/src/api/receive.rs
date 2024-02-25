use crate::api::send::Request;
use crate::frb_generated::RustOpaque;
pub use crate::utils::error::PayjoinError;
use flutter_rust_bridge::DartFnFuture;
use std::collections::HashMap;
pub use std::sync::{Arc, Mutex};

#[derive(Clone)]
pub struct Headers(pub HashMap<String, String>);
/// A reference to a transaction output.
#[derive(Clone, Debug, PartialEq, Eq, Hash)]
pub struct OutPoint {
    /// The referenced transaction's txid.
    pub txid: String,
    /// The index of the referenced output in its transaction's vout.
    pub vout: u32,
}

impl From<OutPoint> for payjoin_ffi::types::OutPoint {
    fn from(value: OutPoint) -> Self {
        payjoin_ffi::types::OutPoint {
            txid: value.txid,
            vout: value.vout,
        }
    }
}
impl From<&payjoin_ffi::types::OutPoint> for OutPoint {
    fn from(value: &payjoin_ffi::types::OutPoint) -> Self {
        OutPoint {
            txid: value.txid.clone(),
            vout: value.vout,
        }
    }
}

#[derive(Debug, Clone)]
pub struct TxOut {
    /// The value of the output, in satoshis.
    pub value: u64,
    /// The address of the output.
    pub script_pubkey: Vec<u8>,
}

impl From<TxOut> for payjoin_ffi::types::TxOut {
    fn from(tx_out: TxOut) -> Self {
        payjoin_ffi::types::TxOut {
            value: tx_out.value,
            script_pubkey: tx_out.script_pubkey,
        }
    }
}

impl From<payjoin_ffi::types::TxOut> for TxOut {
    fn from(tx_out: payjoin_ffi::types::TxOut) -> Self {
        TxOut {
            value: tx_out.value,
            script_pubkey: tx_out.script_pubkey,
        }
    }
}
impl From<Headers> for payjoin_ffi::receive::v1::Headers {
    fn from(value: Headers) -> Self {
        payjoin_ffi::receive::v1::Headers(value.0)
    }
}

impl From<payjoin_ffi::receive::v1::Headers> for Headers {
    fn from(value: payjoin_ffi::receive::v1::Headers) -> Self {
        Headers(value.0)
    }
}

impl Headers {
    pub fn from_vec(body: Vec<u8>) -> Headers {
        payjoin_ffi::receive::v1::Headers::from_vec(body).into()
    }
}

pub struct UncheckedProposal(pub RustOpaque<payjoin_ffi::receive::v1::UncheckedProposal>);
impl From<payjoin_ffi::receive::v1::UncheckedProposal> for UncheckedProposal {
    fn from(value: payjoin_ffi::receive::v1::UncheckedProposal) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl UncheckedProposal {
    pub fn from_request(
        body: Vec<u8>,
        query: String,
        headers: Headers,
    ) -> Result<UncheckedProposal, PayjoinError> {
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
    ) -> Result<MaybeInputsOwned, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_broadcast_suitability_with_callback(min_fee_rate, |x| {
                Ok(runtime.block_on(can_broadcast(x.clone())))
            })
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
    /// Call this method if the only way to initiate a Payjoin with this receiver requires manual intervention, as in most consumer wallets.
    ///
    /// So-called “non-interactive” receivers, like payment processors, that allow arbitrary requests are otherwise vulnerable to probing attacks. Those receivers call get_transaction_to_check_broadcast() and attest_tested_and_scheduled_broadcast() after making those checks downstream.
    pub fn assume_interactive_receiver(&self) -> MaybeInputsOwned {
        self.0.clone().assume_interactive_receiver().into()
    }
}

pub struct MaybeInputsOwned(pub RustOpaque<Arc<payjoin_ffi::receive::v1::MaybeInputsOwned>>);
impl From<Arc<payjoin_ffi::receive::v1::MaybeInputsOwned>> for MaybeInputsOwned {
    fn from(value: Arc<payjoin_ffi::receive::v1::MaybeInputsOwned>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl MaybeInputsOwned {
    pub fn check_inputs_not_owned(
        &self,
        is_owned: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<MaybeMixedInputScripts, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_inputs_not_owned_with_callback(|o| Ok(runtime.block_on(is_owned(o.clone()))))
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}
pub struct MaybeMixedInputScripts(
    pub RustOpaque<Arc<payjoin_ffi::receive::v1::MaybeMixedInputScripts>>,
);
impl From<Arc<payjoin_ffi::receive::v1::MaybeMixedInputScripts>> for MaybeMixedInputScripts {
    fn from(value: Arc<payjoin_ffi::receive::v1::MaybeMixedInputScripts>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl MaybeMixedInputScripts {
    /// Verify the original transaction did not have mixed input types Call this after checking downstream.
    ///
    /// Note: mixed spends do not necessarily indicate distinct wallet fingerprints. This check is intended to prevent some types of wallet fingerprinting.
    pub fn check_no_mixed_input_scripts(&self) -> Result<MaybeInputsSeen, PayjoinError> {
        self.0
            .clone()
            .check_no_mixed_input_scripts()
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}
pub struct MaybeInputsSeen(pub RustOpaque<Arc<payjoin_ffi::receive::v1::MaybeInputsSeen>>);
impl From<Arc<payjoin_ffi::receive::v1::MaybeInputsSeen>> for MaybeInputsSeen {
    fn from(value: Arc<payjoin_ffi::receive::v1::MaybeInputsSeen>) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl MaybeInputsSeen {
    pub fn check_no_inputs_seen_before(
        &self,
        is_known: impl Fn(OutPoint) -> DartFnFuture<bool>,
    ) -> Result<OutputsUnknown, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_no_inputs_seen_before_with_callback(|o| Ok(runtime.block_on(is_known(o.into()))))
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}

pub struct OutputsUnknown(pub RustOpaque<Arc<payjoin_ffi::receive::v1::OutputsUnknown>>);
impl From<Arc<payjoin_ffi::receive::v1::OutputsUnknown>> for OutputsUnknown {
    fn from(value: Arc<payjoin_ffi::receive::v1::OutputsUnknown>) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl OutputsUnknown {
    pub fn identify_receiver_outputs(
        &self,
        is_receiver_output: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<ProvisionalProposal, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .identify_receiver_outputs_with_callback(|o| {
                Ok(runtime.block_on(is_receiver_output(o.clone())))
            })
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}

pub struct ProvisionalProposal(pub RustOpaque<Arc<payjoin_ffi::receive::v1::ProvisionalProposal>>);
impl From<Arc<payjoin_ffi::receive::v1::ProvisionalProposal>> for ProvisionalProposal {
    fn from(value: Arc<payjoin_ffi::receive::v1::ProvisionalProposal>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl ProvisionalProposal {
    pub fn substitute_output_address(&self, address: String) -> Result<(), PayjoinError> {
        self.0
            .substitute_output_address(address)
            .map_err(|e| e.into())
    }
    pub fn contribute_witness_input(
        &self,
        txo: TxOut,
        outpoint: OutPoint,
    ) -> Result<(), PayjoinError> {
        self.0
            .contribute_witness_input(txo.into(), outpoint.into())
            .map_err(|e| e.into())
    }
    pub fn contribute_non_witness_input(
        &self,
        tx: Vec<u8>,
        outpoint: OutPoint,
    ) -> Result<(), PayjoinError> {
        self.0
            .contribute_non_witness_input(tx, outpoint.into())
            .map_err(|e| e.into())
    }
    /// Select receiver input such that the payjoin avoids surveillance. Return the input chosen that has been applied to the Proposal.
    ///
    /// Proper coin selection allows payjoin to resemble ordinary transactions. To ensure the resemblance, a number of heuristics must be avoided.
    ///
    /// UIH “Unnecessary input heuristic” is one class of them to avoid. We define UIH1 and UIH2 according to the BlockSci practice BlockSci UIH1 and UIH2:
    pub fn try_preserving_privacy(
        &self,
        candidate_inputs: HashMap<u64, OutPoint>,
    ) -> Result<OutPoint, PayjoinError> {
        let candidate_inputs: HashMap<u64, payjoin_ffi::types::OutPoint> = candidate_inputs
            .into_iter()
            .map(|(key, value)| (key, value.into()))
            .collect();
        self.0
            .try_preserving_privacy(candidate_inputs)
            .map_err(|e| e.into())
            .map(|o| (&o).into())
    }

    pub fn finalize_proposal(
        &self,
        process_psbt: impl Fn(String) -> DartFnFuture<String>,
        min_feerate_sat_per_vb: Option<u64>,
    ) -> Result<PayjoinProposal, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .finalize_proposal_with_callback(
                |o| Ok(runtime.block_on(process_psbt(o.clone()))),
                min_feerate_sat_per_vb,
            )
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}

pub struct PayjoinProposal(pub RustOpaque<Arc<payjoin_ffi::receive::v1::PayjoinProposal>>);
impl From<Arc<payjoin_ffi::receive::v1::PayjoinProposal>> for PayjoinProposal {
    fn from(value: Arc<payjoin_ffi::receive::v1::PayjoinProposal>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl PayjoinProposal {
    pub fn utxos_to_be_locked(&self) -> Vec<OutPoint> {
        self.0
            .utxos_to_be_locked()
            .iter()
            .map(|x| x.into())
            .collect()
    }
    pub fn is_output_substitution_disabled(&self) -> bool {
        self.0.is_output_substitution_disabled()
    }
    pub fn owned_vouts(&self) -> Vec<u64> {
        self.0.owned_vouts().iter().map(|x| (*x).into()).collect()
    }
    pub fn psbt(&self) -> String {
        self.0.psbt()
    }
}
pub struct ClientResponse(pub RustOpaque<Mutex<Option<ohttp::ClientResponse>>>);

impl From<ClientResponse> for ohttp::ClientResponse {
    fn from(value: ClientResponse) -> Self {
        let mut data_guard = value.0.lock().unwrap();
        Option::take(&mut *data_guard).expect("ClientResponse moved out of memory")
    }
}
impl From<ohttp::ClientResponse> for ClientResponse {
    fn from(value: ohttp::ClientResponse) -> Self {
        Self(RustOpaque::new(Mutex::new(Some(value))))
    }
}

#[derive(Clone, Debug)]
pub struct Enroller(pub RustOpaque<payjoin_ffi::receive::v2::Enroller>);
pub struct RequestResponse {
    pub request: Request,
    pub client_response: ClientResponse,
}

impl From<payjoin_ffi::receive::v2::Enroller> for Enroller {
    fn from(value: payjoin_ffi::receive::v2::Enroller) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl Enroller {
    pub fn from_relay_config(
        relay_url: String,
        ohttp_config_base64: String,
        ohttp_proxy_url: String,
    ) -> Enroller {
        payjoin_ffi::receive::v2::Enroller::from_relay_config(
            relay_url,
            ohttp_config_base64,
            ohttp_proxy_url,
        )
        .into()
    }

    pub fn subdirectory(&self) -> String {
        self.0.subdirectory()
    }
    pub fn payjoin_subdir(&self) -> String {
        self.0.payjoin_subdir()
    }
    pub fn extract_req(&self) -> Result<RequestResponse, PayjoinError> {
        self.0
            .extract_req_as_tuple()
            .map(|e| RequestResponse {
                request: e.0.into(),
                client_response: e.1.into(),
            })
            .map_err(|e| e.into())
    }
    pub fn process_res(
        &self,
        body: Vec<u8>,
        ctx: ClientResponse,
    ) -> Result<Enrolled, PayjoinError> {
        self.0
            .process_res_with_ohttp_response(body, ctx.into())
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}
#[derive(Clone, Debug)]
pub struct Enrolled(pub RustOpaque<Arc<payjoin_ffi::receive::v2::Enrolled>>);

impl From<Arc<payjoin_ffi::receive::v2::Enrolled>> for Enrolled {
    fn from(value: Arc<payjoin_ffi::receive::v2::Enrolled>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl Enrolled {
    pub fn subdirectory(&self) -> Vec<u8> {
        self.0.pubkey()
    }
    pub fn fallback_target(&self) -> String {
        self.0.fallback_target()
    }
    pub fn extract_req(&self) -> Result<RequestResponse, PayjoinError> {
        self.0
            .extract_req_as_tuple()
            .map(|e| RequestResponse {
                request: e.0.into(),
                client_response: e.1.into(),
            })
            .map_err(|e| e.into())
    }
    pub fn process_res(
        &self,
        body: Vec<u8>,
        ctx: ClientResponse,
    ) -> Result<Option<V2UncheckedProposal>, PayjoinError> {
        self.0
            .process_res_with_ohttp_response(body, ctx.into())
            .map(|e| e.map(|o| o.into()))
            .map_err(|e| e.into())
    }
}

#[derive(Clone)]
pub struct V2UncheckedProposal(pub RustOpaque<payjoin_ffi::receive::v2::V2UncheckedProposal>);
impl From<payjoin_ffi::receive::v2::V2UncheckedProposal> for V2UncheckedProposal {
    fn from(value: payjoin_ffi::receive::v2::V2UncheckedProposal) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl V2UncheckedProposal {
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
    ) -> Result<V2MaybeInputsOwned, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_broadcast_suitability_with_callback(min_fee_rate, |x| {
                Ok(runtime.block_on(can_broadcast(x.clone())))
            })
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
    /// Call this method if the only way to initiate a Payjoin with this receiver
    /// requires manual intervention, as in most consumer wallets.
    ///
    /// So-called "non-interactive" receivers, like payment processors, that allow arbitrary requests are otherwise vulnerable to probing attacks.
    /// Those receivers call `extract_tx_to_check_broadcast()` and `attest_tested_and_scheduled_broadcast()` after making those checks downstream.
    pub fn assume_interactive_receiver(&self) -> Arc<V2MaybeInputsOwned> {
        Arc::new(self.0.clone().assume_interactive_receiver().into())
    }
}
#[derive(Clone)]
pub struct V2MaybeInputsOwned(pub RustOpaque<Arc<payjoin_ffi::receive::v2::V2MaybeInputsOwned>>);

impl From<Arc<payjoin_ffi::receive::v2::V2MaybeInputsOwned>> for V2MaybeInputsOwned {
    fn from(value: Arc<payjoin_ffi::receive::v2::V2MaybeInputsOwned>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl V2MaybeInputsOwned {
    ///Check that the Original PSBT has no receiver-owned inputs. Return original-psbt-rejected error or otherwise refuse to sign undesirable inputs.
    /// An attacker could try to spend receiver's own inputs. This check prevents that.
    pub fn check_inputs_not_owned(
        &self,
        is_owned: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<V2MaybeMixedInputScripts, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_inputs_not_owned_with_callback(|o| Ok(runtime.block_on(is_owned(o.clone()))))
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}

pub struct V2MaybeMixedInputScripts(
    pub RustOpaque<Arc<payjoin_ffi::receive::v2::V2MaybeMixedInputScripts>>,
);

impl From<Arc<payjoin_ffi::receive::v2::V2MaybeMixedInputScripts>> for V2MaybeMixedInputScripts {
    fn from(value: Arc<payjoin_ffi::receive::v2::V2MaybeMixedInputScripts>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl V2MaybeMixedInputScripts {
    /// Verify the original transaction did not have mixed input types
    /// Call this after checking downstream.
    ///
    /// Note: mixed spends do not necessarily indicate distinct wallet fingerprints.
    /// This check is intended to prevent some types of wallet fingerprinting.
    pub fn check_no_mixed_input_scripts(&self) -> Result<Arc<V2MaybeInputsSeen>, PayjoinError> {
        self.0
            .clone()
            .check_no_mixed_input_scripts()
            .map(|e| Arc::new(e.into()))
            .map_err(|e| e.into())
    }
}
pub struct V2MaybeInputsSeen(pub RustOpaque<Arc<payjoin_ffi::receive::v2::V2MaybeInputsSeen>>);

impl From<Arc<payjoin_ffi::receive::v2::V2MaybeInputsSeen>> for V2MaybeInputsSeen {
    fn from(value: Arc<payjoin_ffi::receive::v2::V2MaybeInputsSeen>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl V2MaybeInputsSeen {
    /// Make sure that the original transaction inputs have never been seen before.
    /// This prevents probing attacks. This prevents reentrant Payjoin, where a sender
    /// proposes a Payjoin PSBT as a new Original PSBT for a new Payjoin.
    pub fn check_no_inputs_seen_before(
        &self,
        is_known: impl Fn(OutPoint) -> DartFnFuture<bool>,
    ) -> Result<V2OutputsUnknown, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .check_no_inputs_seen_before_with_callback(|o| Ok(runtime.block_on(is_known(o.into()))))
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}

pub struct V2OutputsUnknown(pub RustOpaque<Arc<payjoin_ffi::receive::v2::V2OutputsUnknown>>);

impl From<Arc<payjoin_ffi::receive::v2::V2OutputsUnknown>> for V2OutputsUnknown {
    fn from(value: Arc<payjoin_ffi::receive::v2::V2OutputsUnknown>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl V2OutputsUnknown {
    /// Find which outputs belong to the receiver
    pub fn identify_receiver_outputs(
        &self,
        is_receiver_output: impl Fn(Vec<u8>) -> DartFnFuture<bool>,
    ) -> Result<V2ProvisionalProposal, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .identify_receiver_outputs_with_callback(|o| {
                Ok(runtime.block_on(is_receiver_output(o.clone())))
            })
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}
pub struct V2ProvisionalProposal(
    pub RustOpaque<Arc<payjoin_ffi::receive::v2::V2ProvisionalProposal>>,
);
impl From<Arc<payjoin_ffi::receive::v2::V2ProvisionalProposal>> for V2ProvisionalProposal {
    fn from(value: Arc<payjoin_ffi::receive::v2::V2ProvisionalProposal>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl V2ProvisionalProposal {
    pub fn substitute_output_address(&self, address: String) -> Result<(), PayjoinError> {
        self.0
            .substitute_output_address(address)
            .map_err(|e| e.into())
    }
    pub fn contribute_witness_input(
        &self,
        txo: TxOut,
        outpoint: OutPoint,
    ) -> Result<(), PayjoinError> {
        self.0
            .contribute_witness_input(txo.into(), outpoint.into())
            .map_err(|e| e.into())
    }
    pub fn contribute_non_witness_input(
        &self,
        tx: Vec<u8>,
        outpoint: OutPoint,
    ) -> Result<(), PayjoinError> {
        self.0
            .contribute_non_witness_input(tx, outpoint.into())
            .map_err(|e| e.into())
    }
    /// Select receiver input such that the payjoin avoids surveillance. Return the input chosen that has been applied to the Proposal.
    ///
    /// Proper coin selection allows payjoin to resemble ordinary transactions. To ensure the resemblance, a number of heuristics must be avoided.
    ///
    /// UIH “Unnecessary input heuristic” is one class of them to avoid. We define UIH1 and UIH2 according to the BlockSci practice BlockSci UIH1 and UIH2:
    pub fn try_preserving_privacy(
        &self,
        candidate_inputs: HashMap<u64, OutPoint>,
    ) -> Result<OutPoint, PayjoinError> {
        let candidate_inputs: HashMap<u64, payjoin_ffi::types::OutPoint> = candidate_inputs
            .into_iter()
            .map(|(key, value)| (key, value.into()))
            .collect();
        self.0
            .try_preserving_privacy(candidate_inputs)
            .map_err(|e| e.into())
            .map(|o| (&o).into())
    }

    pub fn finalize_proposal(
        &self,
        process_psbt: impl Fn(String) -> DartFnFuture<String>,
        min_feerate_sat_per_vb: Option<u64>,
    ) -> Result<V2PayjoinProposal, PayjoinError> {
        let runtime = tokio::runtime::Runtime::new().unwrap();
        self.0
            .finalize_proposal_with_callback(
                |o| Ok(runtime.block_on(process_psbt(o.clone()))),
                min_feerate_sat_per_vb,
            )
            .map(|e| e.into())
            .map_err(|e| e.into())
    }
}
pub struct V2PayjoinProposal(pub RustOpaque<Arc<payjoin_ffi::receive::v2::V2PayjoinProposal>>);
impl From<Arc<payjoin_ffi::receive::v2::V2PayjoinProposal>> for V2PayjoinProposal {
    fn from(value: Arc<payjoin_ffi::receive::v2::V2PayjoinProposal>) -> Self {
        Self(RustOpaque::new(value))
    }
}
impl V2PayjoinProposal {
    pub fn utxos_to_be_locked(&self) -> Vec<OutPoint> {
        self.0
            .utxos_to_be_locked()
            .iter()
            .map(|x| x.into())
            .collect()
    }
    pub fn is_output_substitution_disabled(&self) -> bool {
        self.0.is_output_substitution_disabled()
    }
    pub fn owned_vouts(&self) -> Vec<u64> {
        self.0.owned_vouts().iter().map(|x| (*x).into()).collect()
    }
    pub fn psbt(&self) -> String {
        self.0.psbt()
    }
    pub fn extract_v1_req(&self) -> String {
        self.0.extract_v1_req()
    }
    pub fn extract_v2_req(&self) -> Result<RequestResponse, PayjoinError> {
        let (req, res) = self.0.clone().extract_v2_req_as_tuple()?;
        Ok(RequestResponse {
            request: req.into(),
            client_response: res.into(),
        })
    }

    pub fn deserialize_res(
        &self,
        res: Vec<u8>,
        ohttp_context: ClientResponse,
    ) -> Result<Vec<u8>, PayjoinError> {
        self.0
            .deserialize_res_with_ohttp_response(res, ohttp_context.into())
            .map(|e| e)
            .map_err(|e| e.into())
    }
}
