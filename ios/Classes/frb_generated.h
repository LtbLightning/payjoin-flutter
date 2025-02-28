#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
// EXTRA BEGIN
typedef struct DartCObject *WireSyncRust2DartDco;
typedef struct WireSyncRust2DartSse {
  uint8_t *ptr;
  int32_t len;
} WireSyncRust2DartSse;

typedef int64_t DartPort;
typedef bool (*DartPostCObjectFnType)(DartPort port_id, void *message);
void store_dart_post_cobject(DartPostCObjectFnType ptr);
// EXTRA END
typedef struct _Dart_Handle* Dart_Handle;

typedef struct wire_cst_list_prim_u_8_loose {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_loose;

typedef struct wire_cst_ffi_script {
  uintptr_t field0;
} wire_cst_ffi_script;

typedef struct wire_cst_ffi_url {
  uintptr_t field0;
} wire_cst_ffi_url;

typedef struct wire_cst_list_prim_u_8_strict {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_strict;

typedef struct wire_cst_out_point {
  struct wire_cst_list_prim_u_8_strict *txid;
  uint32_t vout;
} wire_cst_out_point;

typedef struct wire_cst_list_list_prim_u_8_strict {
  struct wire_cst_list_prim_u_8_strict **ptr;
  int32_t len;
} wire_cst_list_list_prim_u_8_strict;

typedef struct wire_cst_tx_in {
  struct wire_cst_out_point previous_output;
  struct wire_cst_ffi_script script_sig;
  uint32_t sequence;
  struct wire_cst_list_list_prim_u_8_strict *witness;
} wire_cst_tx_in;

typedef struct wire_cst_tx_out {
  uint64_t value;
  struct wire_cst_list_prim_u_8_strict *script_pubkey;
} wire_cst_tx_out;

typedef struct wire_cst_psbt_input {
  struct wire_cst_tx_out *witness_utxo;
  struct wire_cst_ffi_script *redeem_script;
  struct wire_cst_ffi_script *witness_script;
} wire_cst_psbt_input;

typedef struct wire_cst_ffi_maybe_inputs_owned {
  uintptr_t field0;
} wire_cst_ffi_maybe_inputs_owned;

typedef struct wire_cst_ffi_maybe_inputs_seen {
  uintptr_t field0;
} wire_cst_ffi_maybe_inputs_seen;

typedef struct wire_cst_ffi_outputs_unknown {
  uintptr_t field0;
} wire_cst_ffi_outputs_unknown;

typedef struct wire_cst_ffi_payjoin_proposal {
  uintptr_t field0;
} wire_cst_ffi_payjoin_proposal;

typedef struct wire_cst_client_response {
  uintptr_t field0;
} wire_cst_client_response;

typedef struct wire_cst_ffi_provisional_proposal {
  uintptr_t field0;
} wire_cst_ffi_provisional_proposal;

typedef struct wire_cst_ffi_ohttp_keys {
  uintptr_t field0;
} wire_cst_ffi_ohttp_keys;

typedef struct wire_cst_ffi_receiver {
  uintptr_t field0;
} wire_cst_ffi_receiver;

typedef struct wire_cst_ffi_unchecked_proposal {
  uintptr_t field0;
} wire_cst_ffi_unchecked_proposal;

typedef struct wire_cst_ffi_wants_inputs {
  uintptr_t field0;
} wire_cst_ffi_wants_inputs;

typedef struct wire_cst_ffi_input_pair {
  uintptr_t field0;
} wire_cst_ffi_input_pair;

typedef struct wire_cst_list_ffi_input_pair {
  struct wire_cst_ffi_input_pair *ptr;
  int32_t len;
} wire_cst_list_ffi_input_pair;

typedef struct wire_cst_ffi_wants_outputs {
  uintptr_t field0;
} wire_cst_ffi_wants_outputs;

typedef struct wire_cst_list_tx_out {
  struct wire_cst_tx_out *ptr;
  int32_t len;
} wire_cst_list_tx_out;

typedef struct wire_cst_ffi_sender_builder {
  uintptr_t field0;
} wire_cst_ffi_sender_builder;

typedef struct wire_cst_ffi_pj_uri {
  uintptr_t field0;
} wire_cst_ffi_pj_uri;

typedef struct wire_cst_ffi_sender {
  uintptr_t field0;
} wire_cst_ffi_sender;

typedef struct wire_cst_ffi_v_1_context {
  uintptr_t field0;
} wire_cst_ffi_v_1_context;

typedef struct wire_cst_ffi_v_2_get_context {
  uintptr_t field0;
} wire_cst_ffi_v_2_get_context;

typedef struct wire_cst_ffi_v_2_post_context {
  uintptr_t field0;
} wire_cst_ffi_v_2_post_context;

typedef struct wire_cst_ffi_pj_uri_builder {
  uintptr_t internal;
} wire_cst_ffi_pj_uri_builder;

typedef struct wire_cst_ffi_uri {
  uintptr_t field0;
} wire_cst_ffi_uri;

typedef struct wire_cst_list_out_point {
  struct wire_cst_out_point *ptr;
  int32_t len;
} wire_cst_list_out_point;

typedef struct wire_cst_PayjoinError_InvalidAddress {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_InvalidAddress;

typedef struct wire_cst_PayjoinError_InvalidScript {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_InvalidScript;

typedef struct wire_cst_PayjoinError_NetworkValidation {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_NetworkValidation;

typedef struct wire_cst_PayjoinError_PsbtParseError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_PsbtParseError;

typedef struct wire_cst_PayjoinError_ResponseError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_ResponseError;

typedef struct wire_cst_PayjoinError_RequestError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_RequestError;

typedef struct wire_cst_PayjoinError_TransactionError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_TransactionError;

typedef struct wire_cst_PayjoinError_ServerError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_ServerError;

typedef struct wire_cst_PayjoinError_SelectionError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_SelectionError;

typedef struct wire_cst_PayjoinError_CreateRequestError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_CreateRequestError;

typedef struct wire_cst_PayjoinError_PjParseError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_PjParseError;

typedef struct wire_cst_PayjoinError_PjNotSupported {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_PjNotSupported;

typedef struct wire_cst_PayjoinError_ValidationError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_ValidationError;

typedef struct wire_cst_PayjoinError_V2Error {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_V2Error;

typedef struct wire_cst_PayjoinError_UnexpectedError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_UnexpectedError;

typedef struct wire_cst_PayjoinError_OhttpError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_OhttpError;

typedef struct wire_cst_PayjoinError_UrlError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_UrlError;

typedef struct wire_cst_PayjoinError_IoError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_IoError;

typedef struct wire_cst_PayjoinError_OutputSubstitutionError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_OutputSubstitutionError;

typedef struct wire_cst_PayjoinError_InputContributionError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_InputContributionError;

typedef struct wire_cst_PayjoinError_InputPairError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_InputPairError;

typedef struct wire_cst_PayjoinError_SerdeJsonError {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_PayjoinError_SerdeJsonError;

typedef union PayjoinErrorKind {
  struct wire_cst_PayjoinError_InvalidAddress InvalidAddress;
  struct wire_cst_PayjoinError_InvalidScript InvalidScript;
  struct wire_cst_PayjoinError_NetworkValidation NetworkValidation;
  struct wire_cst_PayjoinError_PsbtParseError PsbtParseError;
  struct wire_cst_PayjoinError_ResponseError ResponseError;
  struct wire_cst_PayjoinError_RequestError RequestError;
  struct wire_cst_PayjoinError_TransactionError TransactionError;
  struct wire_cst_PayjoinError_ServerError ServerError;
  struct wire_cst_PayjoinError_SelectionError SelectionError;
  struct wire_cst_PayjoinError_CreateRequestError CreateRequestError;
  struct wire_cst_PayjoinError_PjParseError PjParseError;
  struct wire_cst_PayjoinError_PjNotSupported PjNotSupported;
  struct wire_cst_PayjoinError_ValidationError ValidationError;
  struct wire_cst_PayjoinError_V2Error V2Error;
  struct wire_cst_PayjoinError_UnexpectedError UnexpectedError;
  struct wire_cst_PayjoinError_OhttpError OhttpError;
  struct wire_cst_PayjoinError_UrlError UrlError;
  struct wire_cst_PayjoinError_IoError IoError;
  struct wire_cst_PayjoinError_OutputSubstitutionError OutputSubstitutionError;
  struct wire_cst_PayjoinError_InputContributionError InputContributionError;
  struct wire_cst_PayjoinError_InputPairError InputPairError;
  struct wire_cst_PayjoinError_SerdeJsonError SerdeJsonError;
} PayjoinErrorKind;

typedef struct wire_cst_payjoin_error {
  int32_t tag;
  union PayjoinErrorKind kind;
} wire_cst_payjoin_error;

typedef struct wire_cst_request {
  struct wire_cst_ffi_url url;
  struct wire_cst_list_prim_u_8_strict *content_type;
  struct wire_cst_list_prim_u_8_strict *body;
} wire_cst_request;

typedef struct wire_cst_record_request_client_response {
  struct wire_cst_request field0;
  struct wire_cst_client_response field1;
} wire_cst_record_request_client_response;

typedef struct wire_cst_record_request_ffi_v_1_context {
  struct wire_cst_request field0;
  struct wire_cst_ffi_v_1_context field1;
} wire_cst_record_request_ffi_v_1_context;

typedef struct wire_cst_record_request_ffi_v_2_post_context {
  struct wire_cst_request field0;
  struct wire_cst_ffi_v_2_post_context field1;
} wire_cst_record_request_ffi_v_2_post_context;

void frbgen_payjoin_flutter_wire__crate__api__bitcoin_ffi__ffi_script_new(int64_t port_,
                                                                          struct wire_cst_list_prim_u_8_loose *raw_output_script);

void frbgen_payjoin_flutter_wire__crate__api__bitcoin_ffi__ffi_script_to_bytes(int64_t port_,
                                                                               struct wire_cst_ffi_script *that);

void frbgen_payjoin_flutter_wire__crate__api__io__fetch_ohttp_keys(int64_t port_,
                                                                   struct wire_cst_ffi_url *ohttp_relay,
                                                                   struct wire_cst_ffi_url *payjoin_directory);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_input_pair_new(int64_t port_,
                                                                          struct wire_cst_tx_in *txin,
                                                                          struct wire_cst_psbt_input *psbtin);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_owned_check_inputs_not_owned(int64_t port_,
                                                                                                     struct wire_cst_ffi_maybe_inputs_owned *that,
                                                                                                     const void *is_owned);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_seen_check_no_inputs_seen_before(int64_t port_,
                                                                                                         struct wire_cst_ffi_maybe_inputs_seen *that,
                                                                                                         const void *is_known);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_outputs_unknown_identify_receiver_outputs(int64_t port_,
                                                                                                     struct wire_cst_ffi_outputs_unknown *that,
                                                                                                     const void *is_receiver_output);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_extract_v1_req(int64_t port_,
                                                                                           struct wire_cst_ffi_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_extract_v2_req(int64_t port_,
                                                                                           struct wire_cst_ffi_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_is_output_substitution_disabled(int64_t port_,
                                                                                                            struct wire_cst_ffi_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_process_res(int64_t port_,
                                                                                        struct wire_cst_ffi_payjoin_proposal *that,
                                                                                        struct wire_cst_list_prim_u_8_loose *res,
                                                                                        struct wire_cst_client_response *ohttp_context);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_psbt(int64_t port_,
                                                                                 struct wire_cst_ffi_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_utxos_to_be_locked(int64_t port_,
                                                                                               struct wire_cst_ffi_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_finalize_proposal(int64_t port_,
                                                                                                  struct wire_cst_ffi_provisional_proposal *that,
                                                                                                  const void *process_psbt,
                                                                                                  uint64_t *min_fee_rate_sat_per_vb,
                                                                                                  uint64_t max_fee_rate_sat_per_vb);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_create(int64_t port_,
                                                                           struct wire_cst_list_prim_u_8_strict *address,
                                                                           int32_t network,
                                                                           struct wire_cst_ffi_url *directory,
                                                                           struct wire_cst_ffi_ohttp_keys *ohttp_keys,
                                                                           struct wire_cst_ffi_url *ohttp_relay,
                                                                           uint64_t *expire_after);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_extract_req(int64_t port_,
                                                                                struct wire_cst_ffi_receiver *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_from_json(struct wire_cst_list_prim_u_8_strict *json);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_id(struct wire_cst_ffi_receiver *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_pj_uri_builder(struct wire_cst_ffi_receiver *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_pj_url(int64_t port_,
                                                                           struct wire_cst_ffi_receiver *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_process_res(int64_t port_,
                                                                                struct wire_cst_ffi_receiver *that,
                                                                                struct wire_cst_list_prim_u_8_loose *body,
                                                                                struct wire_cst_client_response *ctx);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_to_json(struct wire_cst_ffi_receiver *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_assume_interactive_receiver(int64_t port_,
                                                                                                          struct wire_cst_ffi_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_check_broadcast_suitability(int64_t port_,
                                                                                                          struct wire_cst_ffi_unchecked_proposal *that,
                                                                                                          uint64_t *min_fee_rate,
                                                                                                          const void *can_broadcast);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_extract_tx_to_schedule_broadcast(int64_t port_,
                                                                                                               struct wire_cst_ffi_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_inputs_commit_inputs(int64_t port_,
                                                                                      struct wire_cst_ffi_wants_inputs *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_inputs_contribute_inputs(int64_t port_,
                                                                                          struct wire_cst_ffi_wants_inputs *that,
                                                                                          struct wire_cst_list_ffi_input_pair *replacement_inputs);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_inputs_try_preserving_privacy(int64_t port_,
                                                                                               struct wire_cst_ffi_wants_inputs *that,
                                                                                               struct wire_cst_list_ffi_input_pair *candidate_inputs);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_commit_outputs(int64_t port_,
                                                                                        struct wire_cst_ffi_wants_outputs *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_is_output_substitution_disabled(int64_t port_,
                                                                                                         struct wire_cst_ffi_wants_outputs *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_replace_receiver_outputs(int64_t port_,
                                                                                                  struct wire_cst_ffi_wants_outputs *that,
                                                                                                  struct wire_cst_list_tx_out *replacement_outputs,
                                                                                                  struct wire_cst_ffi_script *drain_script);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_substitute_receiver_script(int64_t port_,
                                                                                                    struct wire_cst_ffi_wants_outputs *that,
                                                                                                    struct wire_cst_ffi_script *output_script);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_always_disable_output_substitution(int64_t port_,
                                                                                                          struct wire_cst_ffi_sender_builder *that,
                                                                                                          bool disable);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_build_non_incentivizing(int64_t port_,
                                                                                               struct wire_cst_ffi_sender_builder *that,
                                                                                               uint64_t min_fee_rate);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_build_recommended(int64_t port_,
                                                                                         struct wire_cst_ffi_sender_builder *that,
                                                                                         uint64_t min_fee_rate);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_build_with_additional_fee(int64_t port_,
                                                                                                 struct wire_cst_ffi_sender_builder *that,
                                                                                                 uint64_t max_fee_contribution,
                                                                                                 uint8_t *change_index,
                                                                                                 uint64_t min_fee_rate,
                                                                                                 bool clamp_fee_contribution);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_from_psbt_and_uri(int64_t port_,
                                                                                         struct wire_cst_list_prim_u_8_strict *psbt_base64,
                                                                                         struct wire_cst_ffi_pj_uri *pj_uri);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_extract_v1(int64_t port_,
                                                                          struct wire_cst_ffi_sender *that);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_extract_v2(int64_t port_,
                                                                          struct wire_cst_ffi_sender *that,
                                                                          struct wire_cst_ffi_url *ohttp_proxy_url);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_from_json(struct wire_cst_list_prim_u_8_strict *json);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_to_json(struct wire_cst_ffi_sender *that);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_1_context_process_response(int64_t port_,
                                                                                     struct wire_cst_ffi_v_1_context *that,
                                                                                     struct wire_cst_list_prim_u_8_loose *response);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_get_context_extract_req(int64_t port_,
                                                                                    struct wire_cst_ffi_v_2_get_context *that,
                                                                                    struct wire_cst_ffi_url *ohttp_relay);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_get_context_process_response(int64_t port_,
                                                                                         struct wire_cst_ffi_v_2_get_context *that,
                                                                                         struct wire_cst_list_prim_u_8_loose *response,
                                                                                         struct wire_cst_client_response *ohttp_ctx);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_post_context_process_response(int64_t port_,
                                                                                          struct wire_cst_ffi_v_2_post_context *that,
                                                                                          struct wire_cst_list_prim_u_8_loose *response);

void frbgen_payjoin_flutter_wire__crate__api__uri__ffi_ohttp_keys_decode(int64_t port_,
                                                                         struct wire_cst_list_prim_u_8_loose *bytes);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_address(struct wire_cst_ffi_pj_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_amount_sats(struct wire_cst_ffi_pj_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_as_string(struct wire_cst_ffi_pj_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_amount_sats(struct wire_cst_ffi_pj_uri_builder *that,
                                                                                                  uint64_t amount);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_build(struct wire_cst_ffi_pj_uri_builder *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_label(struct wire_cst_ffi_pj_uri_builder *that,
                                                                                            struct wire_cst_list_prim_u_8_strict *label);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_message(struct wire_cst_ffi_pj_uri_builder *that,
                                                                                              struct wire_cst_list_prim_u_8_strict *message);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_pjos(struct wire_cst_ffi_pj_uri_builder *that,
                                                                                           bool pjos);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_pj_endpoint(struct wire_cst_ffi_pj_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_address(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_amount_sats(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_as_string(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_check_pj_supported(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_label(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_message(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_parse(struct wire_cst_list_prim_u_8_strict *uri);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_as_string(struct wire_cst_ffi_url *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_parse(struct wire_cst_list_prim_u_8_strict *url);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_query(struct wire_cst_ffi_url *that);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_bitcoin_ffiScript(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_bitcoin_ffiScript(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiOhttpKeys(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiOhttpKeys(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiUrl(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiUrl(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveInputPair(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveInputPair(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveOutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveOutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivePayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivePayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveReceiver(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveReceiver(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveWantsInputs(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveWantsInputs(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveWantsOutputs(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveWantsOutputs(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendSender(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendSender(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendSenderBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendSenderBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV1Context(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV1Context(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV2GetContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV2GetContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV2PostContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV2PostContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriPjUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriPjUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriPjUriBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriPjUriBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionpayjoin_ffiClientResponse(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionpayjoin_ffiClientResponse(const void *ptr);

struct wire_cst_client_response *frbgen_payjoin_flutter_cst_new_box_autoadd_client_response(void);

struct wire_cst_ffi_maybe_inputs_owned *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_owned(void);

struct wire_cst_ffi_maybe_inputs_seen *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_seen(void);

struct wire_cst_ffi_ohttp_keys *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_ohttp_keys(void);

struct wire_cst_ffi_outputs_unknown *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_outputs_unknown(void);

struct wire_cst_ffi_payjoin_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_payjoin_proposal(void);

struct wire_cst_ffi_pj_uri *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_pj_uri(void);

struct wire_cst_ffi_pj_uri_builder *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_pj_uri_builder(void);

struct wire_cst_ffi_provisional_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_provisional_proposal(void);

struct wire_cst_ffi_receiver *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_receiver(void);

struct wire_cst_ffi_script *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_script(void);

struct wire_cst_ffi_sender *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_sender(void);

struct wire_cst_ffi_sender_builder *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_sender_builder(void);

struct wire_cst_ffi_unchecked_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_unchecked_proposal(void);

struct wire_cst_ffi_uri *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_uri(void);

struct wire_cst_ffi_url *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_url(void);

struct wire_cst_ffi_v_1_context *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_1_context(void);

struct wire_cst_ffi_v_2_get_context *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_get_context(void);

struct wire_cst_ffi_v_2_post_context *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_post_context(void);

struct wire_cst_ffi_wants_inputs *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_wants_inputs(void);

struct wire_cst_ffi_wants_outputs *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_wants_outputs(void);

struct wire_cst_psbt_input *frbgen_payjoin_flutter_cst_new_box_autoadd_psbt_input(void);

struct wire_cst_tx_in *frbgen_payjoin_flutter_cst_new_box_autoadd_tx_in(void);

struct wire_cst_tx_out *frbgen_payjoin_flutter_cst_new_box_autoadd_tx_out(void);

uint64_t *frbgen_payjoin_flutter_cst_new_box_autoadd_u_64(uint64_t value);

uint8_t *frbgen_payjoin_flutter_cst_new_box_autoadd_u_8(uint8_t value);

struct wire_cst_list_ffi_input_pair *frbgen_payjoin_flutter_cst_new_list_ffi_input_pair(int32_t len);

struct wire_cst_list_list_prim_u_8_strict *frbgen_payjoin_flutter_cst_new_list_list_prim_u_8_strict(int32_t len);

struct wire_cst_list_out_point *frbgen_payjoin_flutter_cst_new_list_out_point(int32_t len);

struct wire_cst_list_prim_u_8_loose *frbgen_payjoin_flutter_cst_new_list_prim_u_8_loose(int32_t len);

struct wire_cst_list_prim_u_8_strict *frbgen_payjoin_flutter_cst_new_list_prim_u_8_strict(int32_t len);

struct wire_cst_list_tx_out *frbgen_payjoin_flutter_cst_new_list_tx_out(int32_t len);
static int64_t dummy_method_to_enforce_bundling(void) {
    int64_t dummy_var = 0;
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_client_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_seen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_ohttp_keys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_outputs_unknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_payjoin_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_pj_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_pj_uri_builder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_provisional_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_receiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_script);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_sender);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_sender_builder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_unchecked_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_url);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_1_context);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_get_context);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_post_context);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_wants_inputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_wants_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_psbt_input);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_tx_in);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_tx_out);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_u_64);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_u_8);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_ffi_input_pair);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_list_prim_u_8_strict);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_out_point);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_prim_u_8_loose);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_prim_u_8_strict);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_tx_out);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_bitcoin_ffiScript);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiOhttpKeys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiUrl);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveInputPair);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveOutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivePayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveReceiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveWantsInputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveWantsOutputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendSender);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendSenderBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV1Context);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV2GetContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV2PostContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriPjUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriPjUriBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionpayjoin_ffiClientResponse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_bitcoin_ffiScript);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiOhttpKeys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiUrl);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveInputPair);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveOutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivePayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveReceiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveWantsInputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveWantsOutputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendSender);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendSenderBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV1Context);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV2GetContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV2PostContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriPjUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriPjUriBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionpayjoin_ffiClientResponse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__bitcoin_ffi__ffi_script_new);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__bitcoin_ffi__ffi_script_to_bytes);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__io__fetch_ohttp_keys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_input_pair_new);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_owned_check_inputs_not_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_seen_check_no_inputs_seen_before);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_outputs_unknown_identify_receiver_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_extract_v1_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_extract_v2_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_is_output_substitution_disabled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_process_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_psbt);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_utxos_to_be_locked);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_finalize_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_create);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_extract_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_from_json);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_id);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_pj_uri_builder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_pj_url);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_process_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_receiver_to_json);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_assume_interactive_receiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_check_broadcast_suitability);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_extract_tx_to_schedule_broadcast);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_inputs_commit_inputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_inputs_contribute_inputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_inputs_try_preserving_privacy);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_commit_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_is_output_substitution_disabled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_replace_receiver_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_substitute_receiver_script);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_always_disable_output_substitution);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_build_non_incentivizing);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_build_recommended);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_build_with_additional_fee);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_from_psbt_and_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_extract_v1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_extract_v2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_from_json);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_to_json);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_1_context_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_get_context_extract_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_get_context_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_post_context_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_ohttp_keys_decode);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_address);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_amount_sats);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_as_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_amount_sats);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_build);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_label);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_message);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_pjos);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_pj_endpoint);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_address);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_amount_sats);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_as_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_check_pj_supported);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_label);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_message);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_parse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_as_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_parse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_query);
    dummy_var ^= ((int64_t) (void*) store_dart_post_cobject);
    return dummy_var;
}
