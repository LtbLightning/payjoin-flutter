use std::str::FromStr;
use std::sync::Arc;

use flutter_rust_bridge::frb;
use payjoin_ffi::bitcoin_ffi;

use crate::api::bitcoin_ffi::FfiScript;
use crate::api::uri::FfiUrl;
use crate::frb_generated::RustOpaque;

/// A reference to a transaction output.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct OutPoint {
    /// The referenced transaction's txid.
    pub txid: String,
    /// The index of the referenced output in its transaction's vout.
    pub vout: u32,
}

impl From<OutPoint> for bitcoin_ffi::OutPoint {
    fn from(value: OutPoint) -> Self {
        bitcoin_ffi::OutPoint {
            txid: bitcoin_ffi::Txid::from_str(&value.txid).unwrap(),
            vout: value.vout,
        }
    }
}
impl From<&bitcoin_ffi::OutPoint> for OutPoint {
    fn from(value: &bitcoin_ffi::OutPoint) -> Self {
        OutPoint { txid: value.txid.to_string(), vout: value.vout }
    }
}

#[derive(Debug, Clone)]
pub struct TxOut {
    /// The value of the output, in satoshis.
    pub value: u64,
    /// The address of the output.
    pub script_pubkey: Vec<u8>,
}

impl From<TxOut> for bitcoin_ffi::TxOut {
    fn from(tx_out: TxOut) -> Self {
        bitcoin_ffi::TxOut {
            value: Arc::new(bitcoin_ffi::Amount::from_sat(tx_out.value)),
            script_pubkey: Arc::new(bitcoin_ffi::Script::new(tx_out.script_pubkey)),
        }
    }
}

impl From<bitcoin_ffi::TxOut> for TxOut {
    fn from(tx_out: bitcoin_ffi::TxOut) -> Self {
        TxOut { value: tx_out.value.to_sat(), script_pubkey: tx_out.script_pubkey.to_bytes() }
    }
}

// It works with basic enums too
// Enums with struct variants are not yet supported
#[derive(Default)]
#[frb(mirror(bitcoin_ffi::Network))]
#[non_exhaustive]
pub enum Network {
    #[default]
    ///Classic Bitcoin
    Bitcoin,
    ///Bitcoin’s testnet
    Testnet,
    ///Bitcoin’s testnet4
    Testnet4,
    ///Bitcoin’s signet
    Signet,
    ///Bitcoin’s regtest
    Regtest,
}

impl From<Network> for bitcoin_ffi::Network {
    fn from(value: Network) -> Self {
        match value {
            Network::Bitcoin => bitcoin_ffi::Network::Bitcoin,
            Network::Testnet => bitcoin_ffi::Network::Testnet,
            Network::Testnet4 => bitcoin_ffi::Network::Testnet4,
            Network::Signet => bitcoin_ffi::Network::Signet,
            Network::Regtest => bitcoin_ffi::Network::Regtest,
        }
    }
}

impl From<bitcoin_ffi::Network> for Network {
    fn from(value: bitcoin_ffi::Network) -> Self {
        match value {
            bitcoin_ffi::Network::Bitcoin => Network::Bitcoin,
            bitcoin_ffi::Network::Testnet => Network::Testnet,
            bitcoin_ffi::Network::Testnet4 => Network::Testnet4,
            bitcoin_ffi::Network::Regtest => Network::Regtest,
            bitcoin_ffi::Network::Signet => Network::Signet,
            _ => unimplemented!(),
        }
    }
}

pub struct ClientResponse(
    pub RustOpaque<std::sync::Mutex<core::option::Option<payjoin_ffi::ClientResponse>>>,
);

impl From<&ClientResponse> for payjoin_ffi::ClientResponse {
    fn from(value: &ClientResponse) -> Self {
        let mut data_guard = value.0.lock().unwrap();
        Option::take(&mut *data_guard).expect("ClientResponse moved out of memory")
    }
}
impl From<payjoin_ffi::ClientResponse> for ClientResponse {
    fn from(value: payjoin_ffi::ClientResponse) -> Self {
        Self(RustOpaque::new(std::sync::Mutex::new(Some(value))))
    }
}

#[derive(Clone)]
pub struct Request {
    pub url: FfiUrl,
    pub content_type: String,
    pub body: Vec<u8>,
}

impl From<payjoin_ffi::Request> for Request {
    fn from(value: payjoin_ffi::Request) -> Self {
        Self {
            url: (*value.url).clone().into(),
            content_type: value.content_type,
            body: value.body,
        }
    }
}

#[derive(Debug, Clone)]
pub struct Amount(pub RustOpaque<bitcoin_ffi::Amount>);

impl From<Amount> for bitcoin_ffi::Amount {
    fn from(value: Amount) -> Self {
        (*value.0).clone()
    }
}

impl From<bitcoin_ffi::Amount> for Amount {
    fn from(value: bitcoin_ffi::Amount) -> Self {
        Amount(RustOpaque::new(value))
    }
}

impl Amount {
    pub fn from_sat(sat: u64) -> Self {
        Amount(RustOpaque::new(bitcoin_ffi::Amount::from_sat(sat)))
    }

    pub fn from_btc(btc: f64) -> Result<Self, bitcoin_ffi::error::ParseAmountError> {
        let bitcoin_amount = bitcoin_ffi::Amount::from_btc(btc)
            .map_err(bitcoin_ffi::error::ParseAmountError::from)?;
        Ok(Amount(RustOpaque::new(bitcoin_amount)))
    }

    pub fn to_sat(&self) -> u64 {
        (*self.0).to_sat()
    }

    pub fn to_btc(&self) -> f64 {
        (*self.0).to_btc()
    }
}

#[derive(Debug, Clone)]
pub struct TxIn {
    pub previous_output: OutPoint,
    pub script_sig: FfiScript,
    pub sequence: u32,
    pub witness: Vec<Vec<u8>>,
}

impl From<TxIn> for bitcoin_ffi::TxIn {
    fn from(value: TxIn) -> Self {
        bitcoin_ffi::TxIn {
            previous_output: value.previous_output.into(),
            script_sig: Arc::new((&value.script_sig).into()),
            sequence: value.sequence,
            witness: value.witness,
        }
    }
}

impl From<bitcoin_ffi::TxIn> for TxIn {
    fn from(value: bitcoin_ffi::TxIn) -> Self {
        TxIn {
            previous_output: (&value.previous_output).into(),
            script_sig: FfiScript::new(value.script_sig.to_bytes()),
            sequence: value.sequence,
            witness: value.witness,
        }
    }
}

#[derive(Debug, Clone)]
pub struct PsbtInput {
    pub witness_utxo: Option<TxOut>,
    pub redeem_script: Option<FfiScript>,
    pub witness_script: Option<FfiScript>,
}

impl PsbtInput {
    pub fn new(
        witness_utxo: Option<TxOut>,
        redeem_script: Option<FfiScript>,
        witness_script: Option<FfiScript>,
    ) -> Self {
        Self { witness_utxo, redeem_script, witness_script }
    }
}

impl From<PsbtInput> for bitcoin_ffi::PsbtInput {
    fn from(value: PsbtInput) -> Self {
        bitcoin_ffi::PsbtInput {
            witness_utxo: value.witness_utxo.map(|v| v.into()),
            redeem_script: value.redeem_script.map(|v| Arc::new((&v).into())),
            witness_script: value.witness_script.map(|v| Arc::new((&v).into())),
        }
    }
}

impl From<bitcoin_ffi::PsbtInput> for PsbtInput {
    fn from(value: bitcoin_ffi::PsbtInput) -> Self {
        Self {
            witness_utxo: value.witness_utxo.map(|v| v.into()),
            redeem_script: value.redeem_script.map(|v| FfiScript::new(v.to_bytes())),
            witness_script: value.witness_script.map(|v| FfiScript::new(v.to_bytes())),
        }
    }
}
