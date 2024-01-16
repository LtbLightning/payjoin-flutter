use crate::frb_generated::RustOpaque;
pub use crate::utils::error::PayjoinError;
use flutter_rust_bridge::DartFnFuture;
use std::collections::HashMap;
use std::sync::Arc;

#[derive(Clone)]
pub struct Headers(pub HashMap<String, String>);

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

        match self
            .0
            .check_broadcast_suitability_with_callback(min_fee_rate, |x| {
                Ok(runtime.block_on(can_broadcast(x.clone())))
            }) {
            Ok(e) => Ok(e.into()),
            Err(e) => Err(e.into()),
        }
    }
}

pub struct MaybeInputsOwned(pub RustOpaque<Arc<payjoin_ffi::receive::v1::MaybeInputsOwned>>);
impl From<Arc<payjoin_ffi::receive::v1::MaybeInputsOwned>> for MaybeInputsOwned {
    fn from(value: Arc<payjoin_ffi::receive::v1::MaybeInputsOwned>) -> Self {
        Self(RustOpaque::new(value))
    }
}
