use crate::api::uri::{FfiOhttpKeys, FfiUrl};
use crate::utils::error::PayjoinError;

/// Fetch the ohttp keys from the specified payjoin directory via proxy.
///
/// * `ohttp_relay`: The http CONNNECT method proxy to request the ohttp keys from a payjoin
/// directory.  Proxying requests for ohttp keys ensures a client IP address is never revealed to
/// the payjoin directory.
///
/// * `payjoin_directory`: The payjoin directory from which to fetch the ohttp keys.  This
/// directory stores and forwards payjoin client payloads.
///
/// * `cert_der` (optional): The DER-encoded certificate to use for local HTTPS connections.  This
/// parameter is only available when the "danger-local-https" feature is enabled.
pub async fn fetch_ohttp_keys(
    ohttp_relay: FfiUrl,
    payjoin_directory: FfiUrl,
    #[cfg(feature = "_danger-local-https")] cert_der: Vec<u8>,
) -> Result<FfiOhttpKeys, PayjoinError> {
    #[cfg(not(feature = "_danger-local-https"))]
    let res =
        payjoin_ffi::io::fetch_ohttp_keys((*ohttp_relay.0).clone(), (*payjoin_directory.0).clone());
    #[cfg(feature = "_danger-local-https")]
    let res = payjoin_ffi::io::fetch_ohttp_keys(
        (*ohttp_relay.0).clone(),
        (*payjoin_directory.0).clone(),
        cert_der,
    );
    res.await.map(|e| e.into()).map_err(|e| e.into())
}
