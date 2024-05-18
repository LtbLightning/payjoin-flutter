use std::collections::HashMap;

// ///Represents data that needs to be transmitted to the receiver.
// ///You need to send this request over HTTP(S) to the receiver.
// #[derive(Clone, Debug)]
// pub struct Request {
//     ///URL to send the request to.
//     ///
//     ///This is full URL with scheme etc - you can pass it right to reqwest or a similar library.
//     pub url: Url,
//     ///Bytes to be sent to the receiver.
//     ///
//     ///This is properly encoded PSBT, already in base64. You only need to make sure Content-Type is text/plain and Content-Length is body.len() (most libraries do the latter automatically).
//     pub body: Vec<u8>,
// }

// impl From<Arc<payjoin_ffi::types::Request>> for Request {
//     fn from(value: Arc<payjoin_ffi::types::Request>) -> Self {
//         Self {
//             url: value.url.clone().into(),
//             body: value.body.clone(),
//         }
//     }
// }
// impl From<payjoin_ffi::types::Request> for Request {
//     fn from(value: payjoin_ffi::types::Request) -> Self {
//         Self {
//             url: value.url.clone().into(),
//             body: value.body.clone(),
//         }
//     }
// }

#[derive(Clone)]
pub struct Headers {
    pub map: HashMap<String, String>,
}
impl From<Headers> for payjoin_ffi::receive::v1::Headers {
    fn from(value: Headers) -> Self {
        payjoin_ffi::receive::v1::Headers(value.map)
    }
}

impl From<payjoin_ffi::receive::v1::Headers> for Headers {
    fn from(value: payjoin_ffi::receive::v1::Headers) -> Self {
        Headers { map: value.0 }
    }
}
impl Headers {
    pub fn from_vec(body: Vec<u8>) -> Headers {
        payjoin_ffi::receive::v1::Headers::from_vec(body).into()
    }
}

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
