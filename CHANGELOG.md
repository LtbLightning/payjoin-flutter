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
