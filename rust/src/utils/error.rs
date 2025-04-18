
#[derive(Debug, PartialEq, Eq)]
pub enum ParseAmountError {
    OutOfRange,

    TooPrecise,

    MissingDigits,

    InputTooLarge,

    InvalidCharacter { error_message: String },

    // Has to handle non-exhaustive
    OtherParseAmountErr,
}

impl From<bitcoin_ffi::error::ParseAmountError> for ParseAmountError {
    fn from(value: bitcoin_ffi::error::ParseAmountError) -> Self {
        use bitcoin_ffi::error::ParseAmountError as FfiParseAmountError;
        match value {
            FfiParseAmountError::OutOfRange => ParseAmountError::OutOfRange,
            FfiParseAmountError::TooPrecise => ParseAmountError::TooPrecise,
            FfiParseAmountError::MissingDigits => ParseAmountError::MissingDigits,
            FfiParseAmountError::InputTooLarge => ParseAmountError::InputTooLarge,
            FfiParseAmountError::InvalidCharacter { error_message } => {
                ParseAmountError::InvalidCharacter { error_message }
            }
            FfiParseAmountError::OtherParseAmountErr => ParseAmountError::OtherParseAmountErr,
        }
    }
}

impl From<ParseAmountError> for bitcoin_ffi::error::ParseAmountError {
    fn from(value: ParseAmountError) -> Self {
        use ParseAmountError as RustParseAmountError;
        match value {
            RustParseAmountError::OutOfRange => bitcoin_ffi::error::ParseAmountError::OutOfRange,
            RustParseAmountError::TooPrecise => bitcoin_ffi::error::ParseAmountError::TooPrecise,
            RustParseAmountError::MissingDigits => {
                bitcoin_ffi::error::ParseAmountError::MissingDigits
            }
            RustParseAmountError::InputTooLarge => {
                bitcoin_ffi::error::ParseAmountError::InputTooLarge
            }
            RustParseAmountError::InvalidCharacter { error_message } => {
                bitcoin_ffi::error::ParseAmountError::InvalidCharacter { error_message }
            }
            RustParseAmountError::OtherParseAmountErr => {
                bitcoin_ffi::error::ParseAmountError::OtherParseAmountErr
            }
        }
    }
}