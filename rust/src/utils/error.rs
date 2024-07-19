#[derive(Debug, PartialEq, Eq)]
pub enum PayjoinError {
    InvalidAddress {
        message: String,
    },
    InvalidScript {
        message: String,
    },
    NetworkValidation {
        message: String,
    },
    PsbtParseError {
        message: String,
    },

    ResponseError {
        message: String,
    },

    ///Error that may occur when the request from sender is malformed.
    ///This is currently opaque type because we aren’t sure which variants will stay. You can only display it.
    RequestError {
        message: String,
    },

    ///Error that may occur when the request from sender is malformed.
    TransactionError {
        message: String,
    },
    // To be returned as HTTP 500
    ServerError {
        message: String,
    },

    ///Error that may occur when coin selection fails.
    SelectionError {
        message: String,
    },

    ///Error returned when request could not be created.
    ///This error can currently only happen due to programmer mistake.
    CreateRequestError {
        message: String,
    },
    PjParseError {
        message: String,
    },
    PjNotSupported {
        message: String,
    },
    ValidationError {
        message: String,
    },
    V2Error {
        message: String,
    },
    UnexpectedError {
        message: String,
    },
    OhttpError {
        message: String,
    },
    UrlError {
        message: String,
    },
    IoError {
        message: String,
    },
}

macro_rules! from_payjoin_ffi_error {
    ($($variant:ident),*) => {
        impl From<payjoin_ffi::error::PayjoinError> for PayjoinError {
            fn from(value: payjoin_ffi::error::PayjoinError) -> Self {
                match value {
                    $(
                        payjoin_ffi::error::PayjoinError::$variant { message } => PayjoinError::$variant { message },
                    )*
                }
            }
        }
    };
}

macro_rules! from_payjoin_error {
    ($($variant:ident),*) => {
        impl From<PayjoinError> for payjoin_ffi::error::PayjoinError {
            fn from(value: PayjoinError) -> Self {
                match value {
                    $(
                        PayjoinError::$variant { message } => payjoin_ffi::error::PayjoinError::$variant { message },
                    )*
                }
            }
        }
    };
}
from_payjoin_ffi_error!(
    InvalidAddress,
    InvalidScript,
    NetworkValidation,
    PsbtParseError,
    ResponseError,
    RequestError,
    TransactionError,
    ServerError,
    PjNotSupported,
    SelectionError,
    CreateRequestError,
    PjParseError,
    ValidationError,
    V2Error,
    UnexpectedError,
    OhttpError,
    UrlError,
    IoError
);
from_payjoin_error!(
    InvalidAddress,
    InvalidScript,
    NetworkValidation,
    PsbtParseError,
    ResponseError,
    RequestError,
    TransactionError,
    ServerError,
    SelectionError,
    CreateRequestError,
    PjParseError,
    ValidationError,
    V2Error,
    PjNotSupported,
    UnexpectedError,
    OhttpError,
    UrlError,
    IoError
);
