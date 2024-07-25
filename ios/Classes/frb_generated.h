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

typedef struct wire_cst_ffi_url {
  uintptr_t field0;
} wire_cst_ffi_url;

typedef struct wire_cst_ffi_active_session {
  uintptr_t field0;
} wire_cst_ffi_active_session;

typedef struct wire_cst_list_prim_u_8_loose {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_loose;

typedef struct wire_cst_ffi_client_response {
  uintptr_t field0;
} wire_cst_ffi_client_response;

typedef struct wire_cst_ffi_maybe_inputs_owned {
  uintptr_t field0;
} wire_cst_ffi_maybe_inputs_owned;

typedef struct wire_cst_ffi_maybe_inputs_seen {
  uintptr_t field0;
} wire_cst_ffi_maybe_inputs_seen;

typedef struct wire_cst_ffi_maybe_mixed_input_scripts {
  uintptr_t field0;
} wire_cst_ffi_maybe_mixed_input_scripts;

typedef struct wire_cst_ffi_outputs_unknown {
  uintptr_t field0;
} wire_cst_ffi_outputs_unknown;

typedef struct wire_cst_ffi_payjoin_proposal {
  uintptr_t field0;
} wire_cst_ffi_payjoin_proposal;

typedef struct wire_cst_ffi_provisional_proposal {
  uintptr_t field0;
} wire_cst_ffi_provisional_proposal;

typedef struct wire_cst_list_prim_u_8_strict {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_strict;

typedef struct wire_cst_out_point {
  struct wire_cst_list_prim_u_8_strict *txid;
  uint32_t vout;
} wire_cst_out_point;

typedef struct wire_cst_tx_out {
  uint64_t value;
  struct wire_cst_list_prim_u_8_strict *script_pubkey;
} wire_cst_tx_out;

typedef struct wire_cst_record_u_64_out_point {
  uint64_t field0;
  struct wire_cst_out_point field1;
} wire_cst_record_u_64_out_point;

typedef struct wire_cst_list_record_u_64_out_point {
  struct wire_cst_record_u_64_out_point *ptr;
  int32_t len;
} wire_cst_list_record_u_64_out_point;

typedef struct wire_cst_ffi_session_initializer {
  uintptr_t field0;
} wire_cst_ffi_session_initializer;

typedef struct wire_cst_ffi_ohttp_keys {
  uintptr_t field0;
} wire_cst_ffi_ohttp_keys;

typedef struct wire_cst_ffi_unchecked_proposal {
  uintptr_t field0;
} wire_cst_ffi_unchecked_proposal;

typedef struct wire_cst_record_string_string {
  struct wire_cst_list_prim_u_8_strict *field0;
  struct wire_cst_list_prim_u_8_strict *field1;
} wire_cst_record_string_string;

typedef struct wire_cst_list_record_string_string {
  struct wire_cst_record_string_string *ptr;
  int32_t len;
} wire_cst_list_record_string_string;

typedef struct wire_cst_headers {
  struct wire_cst_list_record_string_string *map;
} wire_cst_headers;

typedef struct wire_cst_ffi_v_2_maybe_inputs_owned {
  uintptr_t field0;
} wire_cst_ffi_v_2_maybe_inputs_owned;

typedef struct wire_cst_ffi_v_2_maybe_inputs_seen {
  uintptr_t field0;
} wire_cst_ffi_v_2_maybe_inputs_seen;

typedef struct wire_cst_ffi_v_2_maybe_mixed_input_scripts {
  uintptr_t field0;
} wire_cst_ffi_v_2_maybe_mixed_input_scripts;

typedef struct wire_cst_ffi_v_2_outputs_unknown {
  uintptr_t field0;
} wire_cst_ffi_v_2_outputs_unknown;

typedef struct wire_cst_ffi_v_2_payjoin_proposal {
  uintptr_t field0;
} wire_cst_ffi_v_2_payjoin_proposal;

typedef struct wire_cst_ffi_v_2_provisional_proposal {
  uintptr_t field0;
} wire_cst_ffi_v_2_provisional_proposal;

typedef struct wire_cst_ffi_v_2_unchecked_proposal {
  uintptr_t field0;
} wire_cst_ffi_v_2_unchecked_proposal;

typedef struct wire_cst_ffi_context_v_1 {
  uintptr_t field0;
} wire_cst_ffi_context_v_1;

typedef struct wire_cst_ffi_context_v_2 {
  uintptr_t field0;
} wire_cst_ffi_context_v_2;

typedef struct wire_cst_ffi_request_builder {
  uintptr_t field0;
} wire_cst_ffi_request_builder;

typedef struct wire_cst_ffi_pj_uri {
  uintptr_t field0;
} wire_cst_ffi_pj_uri;

typedef struct wire_cst_ffi_request_context {
  uintptr_t field0;
} wire_cst_ffi_request_context;

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

typedef struct wire_cst_list_prim_u_64_strict {
  uint64_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_64_strict;

typedef struct wire_cst_ffi_request {
  struct wire_cst_ffi_url ffi_url;
  struct wire_cst_list_prim_u_8_strict *body;
} wire_cst_ffi_request;

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
} PayjoinErrorKind;

typedef struct wire_cst_payjoin_error {
  int32_t tag;
  union PayjoinErrorKind kind;
} wire_cst_payjoin_error;

typedef struct wire_cst_record_ffi_request_ffi_context_v_1 {
  struct wire_cst_ffi_request field0;
  struct wire_cst_ffi_context_v_1 field1;
} wire_cst_record_ffi_request_ffi_context_v_1;

typedef struct wire_cst_record_ffi_request_ffi_context_v_2 {
  struct wire_cst_ffi_request field0;
  struct wire_cst_ffi_context_v_2 field1;
} wire_cst_record_ffi_request_ffi_context_v_2;

typedef struct wire_cst_record_ffi_url_list_prim_u_8_strict {
  struct wire_cst_ffi_url field0;
  struct wire_cst_list_prim_u_8_strict *field1;
} wire_cst_record_ffi_url_list_prim_u_8_strict;

typedef struct wire_cst_record_record_ffi_url_list_prim_u_8_strict_ffi_client_response {
  struct wire_cst_record_ffi_url_list_prim_u_8_strict field0;
  struct wire_cst_ffi_client_response field1;
} wire_cst_record_record_ffi_url_list_prim_u_8_strict_ffi_client_response;

void frbgen_payjoin_flutter_wire__crate__api__io__fetch_ohttp_keys(int64_t port_,
                                                                   struct wire_cst_ffi_url *ohttp_relay,
                                                                   struct wire_cst_ffi_url *payjoin_directory);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_extract_req(int64_t port_,
                                                                                      struct wire_cst_ffi_active_session *ptr);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_pj_uri_builder(struct wire_cst_ffi_active_session *ptr);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_pj_url(struct wire_cst_ffi_active_session *ptr);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_process_res(int64_t port_,
                                                                                      struct wire_cst_ffi_active_session *that,
                                                                                      struct wire_cst_list_prim_u_8_loose *body,
                                                                                      struct wire_cst_ffi_client_response *ctx);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_public_key(struct wire_cst_ffi_active_session *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_owned_check_inputs_not_owned(int64_t port_,
                                                                                                     struct wire_cst_ffi_maybe_inputs_owned *that,
                                                                                                     const void *is_owned);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_seen_check_no_inputs_seen_before(int64_t port_,
                                                                                                         struct wire_cst_ffi_maybe_inputs_seen *that,
                                                                                                         const void *is_known);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_mixed_input_scripts_check_no_mixed_input_scripts(int64_t port_,
                                                                                                                  struct wire_cst_ffi_maybe_mixed_input_scripts *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_outputs_unknown_identify_receiver_outputs(int64_t port_,
                                                                                                     struct wire_cst_ffi_outputs_unknown *that,
                                                                                                     const void *is_receiver_output);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_is_output_substitution_disabled(int64_t port_,
                                                                                                            struct wire_cst_ffi_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_owned_vouts(int64_t port_,
                                                                                        struct wire_cst_ffi_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_psbt(int64_t port_,
                                                                                 struct wire_cst_ffi_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_utxos_to_be_locked(int64_t port_,
                                                                                               struct wire_cst_ffi_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_contribute_non_witness_input(int64_t port_,
                                                                                                             struct wire_cst_ffi_provisional_proposal *that,
                                                                                                             struct wire_cst_list_prim_u_8_loose *tx,
                                                                                                             struct wire_cst_out_point *outpoint);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_contribute_witness_input(int64_t port_,
                                                                                                         struct wire_cst_ffi_provisional_proposal *that,
                                                                                                         struct wire_cst_tx_out *txo,
                                                                                                         struct wire_cst_out_point *outpoint);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_finalize_proposal(int64_t port_,
                                                                                                  struct wire_cst_ffi_provisional_proposal *that,
                                                                                                  const void *process_psbt,
                                                                                                  uint64_t *min_fee_rate_sat_per_vb);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_try_preserving_privacy(int64_t port_,
                                                                                                       struct wire_cst_ffi_provisional_proposal *that,
                                                                                                       struct wire_cst_list_record_u_64_out_point *candidate_inputs);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_try_substitute_receiver_output(int64_t port_,
                                                                                                               struct wire_cst_ffi_provisional_proposal *that,
                                                                                                               const void *generate_script);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_session_initializer_extract_req(int64_t port_,
                                                                                           struct wire_cst_ffi_session_initializer *ptr);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_session_initializer_new(int64_t port_,
                                                                                   struct wire_cst_list_prim_u_8_strict *address,
                                                                                   uint64_t *expire_after,
                                                                                   int32_t network,
                                                                                   struct wire_cst_ffi_url *directory,
                                                                                   struct wire_cst_ffi_ohttp_keys *ohttp_keys,
                                                                                   struct wire_cst_ffi_url *ohttp_relay);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_session_initializer_process_res(int64_t port_,
                                                                                           struct wire_cst_ffi_session_initializer *that,
                                                                                           struct wire_cst_list_prim_u_8_loose *body,
                                                                                           struct wire_cst_ffi_client_response *ctx);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_assume_interactive_receiver(int64_t port_,
                                                                                                          struct wire_cst_ffi_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_check_broadcast_suitability(int64_t port_,
                                                                                                          struct wire_cst_ffi_unchecked_proposal *that,
                                                                                                          uint64_t *min_fee_rate,
                                                                                                          const void *can_broadcast);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_extract_tx_to_schedule_broadcast(int64_t port_,
                                                                                                               struct wire_cst_ffi_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_from_request(int64_t port_,
                                                                                           struct wire_cst_list_prim_u_8_loose *body,
                                                                                           struct wire_cst_list_prim_u_8_strict *query,
                                                                                           struct wire_cst_headers *headers);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_maybe_inputs_owned_check_inputs_not_owned(int64_t port_,
                                                                                                         struct wire_cst_ffi_v_2_maybe_inputs_owned *that,
                                                                                                         const void *is_owned);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_maybe_inputs_seen_check_no_inputs_seen_before(int64_t port_,
                                                                                                             struct wire_cst_ffi_v_2_maybe_inputs_seen *that,
                                                                                                             const void *is_known);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_maybe_mixed_input_scripts_check_no_mixed_input_scripts(int64_t port_,
                                                                                                                      struct wire_cst_ffi_v_2_maybe_mixed_input_scripts *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_outputs_unknown_identify_receiver_outputs(int64_t port_,
                                                                                                         struct wire_cst_ffi_v_2_outputs_unknown *that,
                                                                                                         const void *is_receiver_output);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_extract_v1_req(int64_t port_,
                                                                                               struct wire_cst_ffi_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_extract_v2_req(int64_t port_,
                                                                                               struct wire_cst_ffi_v_2_payjoin_proposal *ptr);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_is_output_substitution_disabled(int64_t port_,
                                                                                                                struct wire_cst_ffi_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_owned_vouts(int64_t port_,
                                                                                            struct wire_cst_ffi_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_process_res(int64_t port_,
                                                                                            struct wire_cst_ffi_v_2_payjoin_proposal *that,
                                                                                            struct wire_cst_list_prim_u_8_loose *res,
                                                                                            struct wire_cst_ffi_client_response *ohttp_context);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_psbt(int64_t port_,
                                                                                     struct wire_cst_ffi_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_utxos_to_be_locked(int64_t port_,
                                                                                                   struct wire_cst_ffi_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_contribute_non_witness_input(int64_t port_,
                                                                                                                 struct wire_cst_ffi_v_2_provisional_proposal *that,
                                                                                                                 struct wire_cst_list_prim_u_8_loose *tx,
                                                                                                                 struct wire_cst_out_point *outpoint);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_contribute_witness_input(int64_t port_,
                                                                                                             struct wire_cst_ffi_v_2_provisional_proposal *that,
                                                                                                             struct wire_cst_tx_out *txo,
                                                                                                             struct wire_cst_out_point *outpoint);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_finalize_proposal(int64_t port_,
                                                                                                      struct wire_cst_ffi_v_2_provisional_proposal *that,
                                                                                                      const void *process_psbt,
                                                                                                      uint64_t *min_feerate_sat_per_vb);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_is_output_substitution_disabled(int64_t port_,
                                                                                                                    struct wire_cst_ffi_v_2_provisional_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_try_preserving_privacy(int64_t port_,
                                                                                                           struct wire_cst_ffi_v_2_provisional_proposal *that,
                                                                                                           struct wire_cst_list_record_u_64_out_point *candidate_inputs);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_try_substitute_receiver_output(int64_t port_,
                                                                                                                   struct wire_cst_ffi_v_2_provisional_proposal *that,
                                                                                                                   const void *generate_script);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_unchecked_proposal_assume_interactive_receiver(int64_t port_,
                                                                                                              struct wire_cst_ffi_v_2_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_unchecked_proposal_check_broadcast_suitability(int64_t port_,
                                                                                                              struct wire_cst_ffi_v_2_unchecked_proposal *that,
                                                                                                              uint64_t *min_fee_rate,
                                                                                                              const void *can_broadcast);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_unchecked_proposal_extract_tx_to_schedule_broadcast(int64_t port_,
                                                                                                                   struct wire_cst_ffi_v_2_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_context_v_1_process_response(int64_t port_,
                                                                                     struct wire_cst_ffi_context_v_1 *that,
                                                                                     struct wire_cst_list_prim_u_8_loose *response);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_context_v_2_process_response(int64_t port_,
                                                                                     struct wire_cst_ffi_context_v_2 *that,
                                                                                     struct wire_cst_list_prim_u_8_loose *response);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_always_disable_output_substitution(int64_t port_,
                                                                                                           struct wire_cst_ffi_request_builder *that,
                                                                                                           bool disable);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_build_non_incentivizing(int64_t port_,
                                                                                                struct wire_cst_ffi_request_builder *that,
                                                                                                uint64_t min_fee_rate);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_build_recommended(int64_t port_,
                                                                                          struct wire_cst_ffi_request_builder *that,
                                                                                          uint64_t min_fee_rate);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_build_with_additional_fee(int64_t port_,
                                                                                                  struct wire_cst_ffi_request_builder *that,
                                                                                                  uint64_t max_fee_contribution,
                                                                                                  uint8_t *change_index,
                                                                                                  uint64_t min_fee_rate,
                                                                                                  bool clamp_fee_contribution);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_from_psbt_and_uri(int64_t port_,
                                                                                          struct wire_cst_list_prim_u_8_strict *psbt_base64,
                                                                                          struct wire_cst_ffi_pj_uri *pj_uri);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_context_extract_v1(int64_t port_,
                                                                                   struct wire_cst_ffi_request_context *that);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_context_extract_v2(int64_t port_,
                                                                                   struct wire_cst_ffi_request_context *that,
                                                                                   struct wire_cst_ffi_url *ohttp_proxy_url);

void frbgen_payjoin_flutter_wire__crate__api__uri__ffi_ohttp_keys_decode(int64_t port_,
                                                                         struct wire_cst_list_prim_u_8_loose *bytes);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_address(struct wire_cst_ffi_pj_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_amount(struct wire_cst_ffi_pj_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_as_string(struct wire_cst_ffi_pj_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_amount(struct wire_cst_ffi_pj_uri_builder *that,
                                                                                             uint64_t amount);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_build(struct wire_cst_ffi_pj_uri_builder *that);

void frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_create(int64_t port_,
                                                                             struct wire_cst_list_prim_u_8_strict *address,
                                                                             struct wire_cst_ffi_url *pj,
                                                                             struct wire_cst_ffi_ohttp_keys *ohttp_keys,
                                                                             uint64_t *expiry);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_label(struct wire_cst_ffi_pj_uri_builder *that,
                                                                                            struct wire_cst_list_prim_u_8_strict *label);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_message(struct wire_cst_ffi_pj_uri_builder *that,
                                                                                              struct wire_cst_list_prim_u_8_strict *message);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_pjos(struct wire_cst_ffi_pj_uri_builder *that,
                                                                                           bool pjos);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_address(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_amount(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_as_string(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_check_pj_supported(struct wire_cst_ffi_uri *that);

void frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_from_str(int64_t port_,
                                                                    struct wire_cst_list_prim_u_8_strict *uri);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_as_string(struct wire_cst_ffi_url *that);

void frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_from_str(int64_t port_,
                                                                    struct wire_cst_list_prim_u_8_strict *url);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_query(struct wire_cst_ffi_url *that);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2PayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2PayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv1ContextV1(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv1ContextV1(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1MaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1MaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1MaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1MaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1MaybeMixedInputScripts(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1MaybeMixedInputScripts(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1OutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1OutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1PayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1PayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1ProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1ProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1UncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1UncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2ActiveSession(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2ActiveSession(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2SessionInitializer(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2SessionInitializer(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeMixedInputScripts(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeMixedInputScripts(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2OutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2OutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2ProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2ProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2UncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2UncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendv1RequestBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendv1RequestBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendv1RequestContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendv1RequestContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffitypesOhttpKeys(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffitypesOhttpKeys(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriPjUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriPjUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriPjUriBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriPjUriBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriUrl(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriUrl(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionohttpClientResponse(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionohttpClientResponse(const void *ptr);

double *frbgen_payjoin_flutter_cst_new_box_autoadd_f_64(double value);

struct wire_cst_ffi_active_session *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_active_session(void);

struct wire_cst_ffi_client_response *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_client_response(void);

struct wire_cst_ffi_context_v_1 *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_context_v_1(void);

struct wire_cst_ffi_context_v_2 *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_context_v_2(void);

struct wire_cst_ffi_maybe_inputs_owned *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_owned(void);

struct wire_cst_ffi_maybe_inputs_seen *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_seen(void);

struct wire_cst_ffi_maybe_mixed_input_scripts *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_mixed_input_scripts(void);

struct wire_cst_ffi_ohttp_keys *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_ohttp_keys(void);

struct wire_cst_ffi_outputs_unknown *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_outputs_unknown(void);

struct wire_cst_ffi_payjoin_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_payjoin_proposal(void);

struct wire_cst_ffi_pj_uri *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_pj_uri(void);

struct wire_cst_ffi_pj_uri_builder *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_pj_uri_builder(void);

struct wire_cst_ffi_provisional_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_provisional_proposal(void);

struct wire_cst_ffi_request_builder *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_request_builder(void);

struct wire_cst_ffi_request_context *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_request_context(void);

struct wire_cst_ffi_session_initializer *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_session_initializer(void);

struct wire_cst_ffi_unchecked_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_unchecked_proposal(void);

struct wire_cst_ffi_uri *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_uri(void);

struct wire_cst_ffi_url *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_url(void);

struct wire_cst_ffi_v_2_maybe_inputs_owned *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_maybe_inputs_owned(void);

struct wire_cst_ffi_v_2_maybe_inputs_seen *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_maybe_inputs_seen(void);

struct wire_cst_ffi_v_2_maybe_mixed_input_scripts *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_maybe_mixed_input_scripts(void);

struct wire_cst_ffi_v_2_outputs_unknown *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_outputs_unknown(void);

struct wire_cst_ffi_v_2_payjoin_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_payjoin_proposal(void);

struct wire_cst_ffi_v_2_provisional_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_provisional_proposal(void);

struct wire_cst_ffi_v_2_unchecked_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_unchecked_proposal(void);

struct wire_cst_headers *frbgen_payjoin_flutter_cst_new_box_autoadd_headers(void);

struct wire_cst_out_point *frbgen_payjoin_flutter_cst_new_box_autoadd_out_point(void);

struct wire_cst_tx_out *frbgen_payjoin_flutter_cst_new_box_autoadd_tx_out(void);

uint64_t *frbgen_payjoin_flutter_cst_new_box_autoadd_u_64(uint64_t value);

uint8_t *frbgen_payjoin_flutter_cst_new_box_autoadd_u_8(uint8_t value);

struct wire_cst_list_out_point *frbgen_payjoin_flutter_cst_new_list_out_point(int32_t len);

struct wire_cst_list_prim_u_64_strict *frbgen_payjoin_flutter_cst_new_list_prim_u_64_strict(int32_t len);

struct wire_cst_list_prim_u_8_loose *frbgen_payjoin_flutter_cst_new_list_prim_u_8_loose(int32_t len);

struct wire_cst_list_prim_u_8_strict *frbgen_payjoin_flutter_cst_new_list_prim_u_8_strict(int32_t len);

struct wire_cst_list_record_string_string *frbgen_payjoin_flutter_cst_new_list_record_string_string(int32_t len);

struct wire_cst_list_record_u_64_out_point *frbgen_payjoin_flutter_cst_new_list_record_u_64_out_point(int32_t len);
static int64_t dummy_method_to_enforce_bundling(void) {
    int64_t dummy_var = 0;
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_f_64);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_active_session);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_client_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_context_v_1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_context_v_2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_seen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_mixed_input_scripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_ohttp_keys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_outputs_unknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_payjoin_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_pj_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_pj_uri_builder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_provisional_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_request_builder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_request_context);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_session_initializer);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_unchecked_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_url);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_maybe_inputs_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_maybe_inputs_seen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_maybe_mixed_input_scripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_outputs_unknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_payjoin_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_provisional_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_v_2_unchecked_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_headers);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_out_point);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_tx_out);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_u_64);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_u_8);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_out_point);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_prim_u_64_strict);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_prim_u_8_loose);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_prim_u_8_strict);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_record_string_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_record_u_64_out_point);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2PayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv1ContextV1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1MaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1MaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1MaybeMixedInputScripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1OutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1PayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1ProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1UncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2ActiveSession);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2SessionInitializer);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeMixedInputScripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2OutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2ProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2UncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendv1RequestBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendv1RequestContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffitypesOhttpKeys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriPjUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriPjUriBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriUrl);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionohttpClientResponse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2PayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv1ContextV1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1MaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1MaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1MaybeMixedInputScripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1OutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1PayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1ProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1UncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2ActiveSession);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2SessionInitializer);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2MaybeMixedInputScripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2OutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2ProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2UncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendv1RequestBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendv1RequestContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffitypesOhttpKeys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriPjUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriPjUriBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriUrl);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionohttpClientResponse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__io__fetch_ohttp_keys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_extract_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_pj_uri_builder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_pj_url);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_process_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_active_session_public_key);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_owned_check_inputs_not_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_seen_check_no_inputs_seen_before);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_mixed_input_scripts_check_no_mixed_input_scripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_outputs_unknown_identify_receiver_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_is_output_substitution_disabled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_owned_vouts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_psbt);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_utxos_to_be_locked);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_contribute_non_witness_input);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_contribute_witness_input);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_finalize_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_try_preserving_privacy);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_try_substitute_receiver_output);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_session_initializer_extract_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_session_initializer_new);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_session_initializer_process_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_assume_interactive_receiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_check_broadcast_suitability);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_extract_tx_to_schedule_broadcast);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_from_request);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_maybe_inputs_owned_check_inputs_not_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_maybe_inputs_seen_check_no_inputs_seen_before);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_maybe_mixed_input_scripts_check_no_mixed_input_scripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_outputs_unknown_identify_receiver_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_extract_v1_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_extract_v2_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_is_output_substitution_disabled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_owned_vouts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_process_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_psbt);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_payjoin_proposal_utxos_to_be_locked);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_contribute_non_witness_input);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_contribute_witness_input);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_finalize_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_is_output_substitution_disabled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_try_preserving_privacy);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_provisional_proposal_try_substitute_receiver_output);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_unchecked_proposal_assume_interactive_receiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_unchecked_proposal_check_broadcast_suitability);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_v_2_unchecked_proposal_extract_tx_to_schedule_broadcast);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_context_v_1_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_context_v_2_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_always_disable_output_substitution);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_build_non_incentivizing);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_build_recommended);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_build_with_additional_fee);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_builder_from_psbt_and_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_context_extract_v1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_request_context_extract_v2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_ohttp_keys_decode);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_address);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_amount);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_as_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_amount);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_build);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_create);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_label);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_message);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_pj_uri_builder_pjos);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_address);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_amount);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_as_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_check_pj_supported);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_from_str);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_as_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_from_str);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_query);
    dummy_var ^= ((int64_t) (void*) store_dart_post_cobject);
    return dummy_var;
}
