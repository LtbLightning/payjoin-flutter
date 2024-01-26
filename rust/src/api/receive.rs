use crate::frb_generated::RustOpaque;
pub use crate::utils::error::PayjoinError;
use std::collections::HashMap;
use std::sync::Arc;

#[derive(Clone)]
pub struct Headers(pub HashMap<String, String>);

impl From<Headers> for payjoin_ffi::receive::Headers {
    fn from(value: Headers) -> Self {
        payjoin_ffi::receive::Headers(value.0)
    }
}

impl From<payjoin_ffi::receive::Headers> for Headers {
    fn from(value: payjoin_ffi::receive::Headers) -> Self {
        Headers(value.0)
    }
}

impl Headers {
    pub fn from_vec(body: Vec<u8>) -> Headers {
        payjoin_ffi::receive::Headers::from_vec(body).into()
    }
}

pub struct UncheckedProposal(pub RustOpaque<payjoin_ffi::receive::UncheckedProposal>);
impl From<payjoin_ffi::receive::UncheckedProposal> for UncheckedProposal {
    fn from(value: payjoin_ffi::receive::UncheckedProposal) -> Self {
        Self(RustOpaque::new(value))
    }
}

impl UncheckedProposal {
    pub fn from_request(
        body: Vec<u8>,
        query: String,
        headers: Headers,
    ) -> Result<UncheckedProposal, PayjoinError> {
        match payjoin_ffi::receive::UncheckedProposal::from_request(
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
    pub async fn check_broadcast_suitability(
        &self,
        min_fee_rate: Option<u64>,
        can_broadcast: Box<dyn Fn(Vec<u8>) -> Result<bool, PayjoinError> + Send + Sync>,
    ) -> Result<MaybeInputsOwned, PayjoinError> {
        match self
            .0
            .check_broadcast_suitability(min_fee_rate, Box::new(CanBroadcast(can_broadcast)))
        {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
}

pub struct MaybeInputsOwned(pub RustOpaque<Arc<payjoin_ffi::receive::MaybeInputsOwned>>);
impl From<Arc<payjoin_ffi::receive::MaybeInputsOwned>> for MaybeInputsOwned {
    fn from(value: Arc<payjoin_ffi::receive::MaybeInputsOwned>) -> Self {
        Self(RustOpaque::new(value))
    }
}

pub struct CanBroadcast(Box<dyn Fn(Vec<u8>) -> Result<bool, PayjoinError> + Send + Sync>);
impl payjoin_ffi::receive::CanBroadcast for CanBroadcast {
    fn callback(&self, tx: Vec<u8>) -> Result<bool, payjoin_ffi::error::PayjoinError> {
        self.0(tx).map_err(|e| e.into())
    }
}


