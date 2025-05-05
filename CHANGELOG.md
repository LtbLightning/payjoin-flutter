## [0.23.0]

Update to `payjoin-ffi` version ` 0.23.0` ([see
changelog](https://github.com/LtbLightning/payjoin-ffi/blob/main/CHANGELOG.md#0230))
which depends on rust-`payjoin` version `0.23.0` ([see changelog](https://github.com/payjoin/rust-payjoin/blob/master/payjoin/CHANGELOG.md#0230)).

## [0.22.0]

Update to `payjoin` version `0.22.0`, fixing `Sender` persistence.

## [0.21.0]
This release updates the bindings libraries to `payjoin` version `0.21.0`.

#### APIs changed
- Major overhaul to attempt a stable BIP 77 protocol implementation.
- v1 support is now only available through the V2 backwards-compatible APIs.
- see [payjoin-0.21.0 changelog](https://github.com/payjoin/rust-payjoin/blob/master/payjoin/CHANGELOG.md#0210) for more details.

## [0.20.0]
#### APIs added
- Make backwards-compatible `v2` to `v1` sends possible.
#### APIs changed
- Removed `contributeNonWitnessInput`  from `v1` & `v2`.
- Allow receivers to make `payjoins` out of sweep transactions ([#259](https://github.com/payjoin/rust-payjoin/pull/259)).
- Encode &ohttp= and &exp= parameters in the &pj= URL as a fragment instead of as URI params ([#298](https://github.com/payjoin/rust-payjoin/pull/298))

## [0.18.0]
Updated `flutter_rust_bridge` to `2.0.0`.
#### APIs added
- Exposed `PjUriBuilder` and `PjUri`.
- Exposed `pjUrlBuilder()` in `ActiveSession`.
- Exposed `checkPjSupported()` in `PjUri`.
- Exposed `fetchOhttpKeys()` to fetch the `ohttp` keys from the specified `payjoin` directory.
#### APIs changed
- Upgrade `receive/v2` type state machine to resume multiple `payjoins` simultaneously ([#283](https://github.com/payjoin/rust-payjoin/pull/283))
- Refactor output substitution with new fallable `try_substitute_outputs` ([#277](https://github.com/payjoin/rust-payjoin/pull/277))
- `Enroller` became `SessionInitializer`.
- `Enrolled` became `ActiveSession`.
- `fallbackTarget()` became `pjUrl()`.

#### Fixed
- Handle OHTTP encapsulated response status ([#284](https://github.com/payjoin/rust-payjoin/pull/284))

## [0.13.0]
### Features & Modules
#### Send module
- #####  V1
    - `RequestBuilder` exposes `fromPsbtAndUri`, `buildWithAdditionalFee`, `buildRecommended`, `buildNonIncentivizing`, `alwaysDisableOutputSubstitution`.
    - `RequestContext` exposes `extractContextV1` & `extractContextV2`.
    - `ContextV1` exposes `processResponse`.
- ##### V2 
    - `ContextV2` exposes `processResponse`.
#### Receive module
- #####  V1
    - `UncheckedProposal` exposes `fromRequest`, `extractTxToScheduleBroadcast`, `checkBroadcastSuitability`, `buildNonIncentivizing`, 
        `assumeInteractiveReceiver` &`alwaysDisableOutputSubstitution`.
    - `MaybeInputsOwned` exposes `checkInputsNotOwned`.    
    - `MaybeMixedInputScripts` exposes `checkNoMixedInputScripts`.    
    - `MaybeInputsSeen` exposes `checkNoInputsSeenBefore`.   
    - `OutputsUnknown` exposes `identifyReceiverOutputs`.   
    - `ProvisionalProposal` exposes `substituteOutputAddress`, `contributeNonWitnessInput`, `contributeWitnessInput`, `tryPreservingPrivacy` & 
        `finalizeProposal`.
    - `PayjoinProposal` exposes `isOutputSubstitutionDisabled`, `ownedVouts`, `psbt` & `utxosToBeLocked`.   
- ##### V2 
    - `Enroller` exposes `fromDirectoryConfig`, `processResponse` & `extractRequest`.
    - `Enrolled` exposes `extractRequest`, `processResponse` & `fallbackTarget`.
    - `UncheckedProposal` exposes  `extractTxToScheduleBroadcast`, `checkBroadcastSuitability` & `assumeInteractiveReceiver`.
    - `MaybeInputsOwned` exposes `checkInputsNotOwned`.    
    - `MaybeMixedInputScripts` exposes `checkNoMixedInputScripts`.    
    - `MaybeInputsSeen` exposes `checkNoInputsSeenBefore`.   
    - `OutputsUnknown` exposes `identifyReceiverOutputs`.   
    - `ProvisionalProposal` exposes `substituteOutputAddress`, `contributeNonWitnessInput`, `contributeWitnessInput`, `tryPreservingPrivacy` & 
        `finalizeProposal`.
    - `PayjoinProposal` exposes `deserializeRes`, `extractV1Req`, `extractV2Request`, `isOutputSubstitutionDisabled`, `ownedVouts`, `psbt` &
        `utxosToBeLocked`.