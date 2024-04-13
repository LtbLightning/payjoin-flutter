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

typedef struct wire_cst_enrolled {
  uintptr_t field0;
} wire_cst_enrolled;

typedef struct wire_cst_list_prim_u_8_loose {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_loose;

typedef struct wire_cst_client_response {
  uintptr_t field0;
} wire_cst_client_response;

typedef struct wire_cst_enroller {
  uintptr_t field0;
} wire_cst_enroller;

typedef struct wire_cst_list_prim_u_8_strict {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_strict;

typedef struct wire_cst_maybe_inputs_owned {
  uintptr_t field0;
} wire_cst_maybe_inputs_owned;

typedef struct wire_cst_maybe_inputs_seen {
  uintptr_t field0;
} wire_cst_maybe_inputs_seen;

typedef struct wire_cst_maybe_mixed_input_scripts {
  uintptr_t field0;
} wire_cst_maybe_mixed_input_scripts;

typedef struct wire_cst_outputs_unknown {
  uintptr_t field0;
} wire_cst_outputs_unknown;

typedef struct wire_cst_payjoin_proposal {
  uintptr_t field0;
} wire_cst_payjoin_proposal;

typedef struct wire_cst_provisional_proposal {
  uintptr_t field0;
} wire_cst_provisional_proposal;

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

typedef struct wire_cst_unchecked_proposal {
  uintptr_t field0;
} wire_cst_unchecked_proposal;

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

typedef struct wire_cst_v_2_maybe_inputs_owned {
  uintptr_t field0;
} wire_cst_v_2_maybe_inputs_owned;

typedef struct wire_cst_v_2_maybe_inputs_seen {
  uintptr_t field0;
} wire_cst_v_2_maybe_inputs_seen;

typedef struct wire_cst_v_2_maybe_mixed_input_scripts {
  uintptr_t field0;
} wire_cst_v_2_maybe_mixed_input_scripts;

typedef struct wire_cst_v_2_outputs_unknown {
  uintptr_t field0;
} wire_cst_v_2_outputs_unknown;

typedef struct wire_cst_v_2_payjoin_proposal {
  uintptr_t field0;
} wire_cst_v_2_payjoin_proposal;

typedef struct wire_cst_v_2_provisional_proposal {
  uintptr_t field0;
} wire_cst_v_2_provisional_proposal;

typedef struct wire_cst_v_2_unchecked_proposal {
  uintptr_t field0;
} wire_cst_v_2_unchecked_proposal;

typedef struct wire_cst_context_v_1 {
  uintptr_t field0;
} wire_cst_context_v_1;

typedef struct wire_cst_context_v_2 {
  uintptr_t field0;
} wire_cst_context_v_2;

typedef struct wire_cst_request_builder {
  uintptr_t field0;
} wire_cst_request_builder;

typedef struct wire_cst_uri {
  uintptr_t field0;
} wire_cst_uri;

typedef struct wire_cst_request_context {
  uintptr_t field0;
} wire_cst_request_context;

typedef struct wire_cst_url {
  uintptr_t field0;
} wire_cst_url;

typedef struct wire_cst_list_out_point {
  struct wire_cst_out_point *ptr;
  int32_t len;
} wire_cst_list_out_point;

typedef struct wire_cst_list_prim_u_64_strict {
  uint64_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_64_strict;

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
} PayjoinErrorKind;

typedef struct wire_cst_payjoin_error {
  int32_t tag;
  union PayjoinErrorKind kind;
} wire_cst_payjoin_error;

typedef struct wire_cst_record_url_list_prim_u_8_strict {
  struct wire_cst_url field0;
  struct wire_cst_list_prim_u_8_strict *field1;
} wire_cst_record_url_list_prim_u_8_strict;

typedef struct wire_cst_record_record_url_list_prim_u_8_strict_client_response {
  struct wire_cst_record_url_list_prim_u_8_strict field0;
  struct wire_cst_client_response field1;
} wire_cst_record_record_url_list_prim_u_8_strict_client_response;

typedef struct wire_cst_request_context_v_1 {
  struct wire_cst_record_url_list_prim_u_8_strict request;
  struct wire_cst_context_v_1 context_v1;
} wire_cst_request_context_v_1;

typedef struct wire_cst_request_context_v_2 {
  struct wire_cst_record_url_list_prim_u_8_strict request;
  struct wire_cst_context_v_2 context_v2;
} wire_cst_request_context_v_2;

void frbgen_payjoin_flutter_wire_enrolled_extract_req(int64_t port_,
                                                      struct wire_cst_enrolled *that);

void frbgen_payjoin_flutter_wire_enrolled_fallback_target(int64_t port_,
                                                          struct wire_cst_enrolled *that);

void frbgen_payjoin_flutter_wire_enrolled_process_res(int64_t port_,
                                                      struct wire_cst_enrolled *that,
                                                      struct wire_cst_list_prim_u_8_loose *body,
                                                      struct wire_cst_client_response *ctx);

void frbgen_payjoin_flutter_wire_enrolled_subdirectory(int64_t port_,
                                                       struct wire_cst_enrolled *that);

void frbgen_payjoin_flutter_wire_enroller_extract_req(int64_t port_,
                                                      struct wire_cst_enroller *that);

void frbgen_payjoin_flutter_wire_enroller_from_relay_config(int64_t port_,
                                                            struct wire_cst_list_prim_u_8_strict *relay_url,
                                                            struct wire_cst_list_prim_u_8_strict *ohttp_config_base64,
                                                            struct wire_cst_list_prim_u_8_strict *ohttp_proxy_url);

void frbgen_payjoin_flutter_wire_enroller_payjoin_subdir(int64_t port_,
                                                         struct wire_cst_enroller *that);

void frbgen_payjoin_flutter_wire_enroller_process_res(int64_t port_,
                                                      struct wire_cst_enroller *that,
                                                      struct wire_cst_list_prim_u_8_loose *body,
                                                      struct wire_cst_client_response *ctx);

void frbgen_payjoin_flutter_wire_enroller_subdirectory(int64_t port_,
                                                       struct wire_cst_enroller *that);

void frbgen_payjoin_flutter_wire_maybe_inputs_owned_check_inputs_not_owned(int64_t port_,
                                                                           struct wire_cst_maybe_inputs_owned *ptr,
                                                                           const void *is_owned);

void frbgen_payjoin_flutter_wire_maybe_inputs_seen_check_no_inputs_seen_before(int64_t port_,
                                                                               struct wire_cst_maybe_inputs_seen *ptr,
                                                                               const void *is_known);

void frbgen_payjoin_flutter_wire_maybe_mixed_input_scripts_check_no_mixed_input_scripts(int64_t port_,
                                                                                        struct wire_cst_maybe_mixed_input_scripts *ptr);

void frbgen_payjoin_flutter_wire_outputs_unknown_identify_receiver_outputs(int64_t port_,
                                                                           struct wire_cst_outputs_unknown *ptr,
                                                                           const void *is_receiver_output);

void frbgen_payjoin_flutter_wire_payjoin_proposal_is_output_substitution_disabled(int64_t port_,
                                                                                  struct wire_cst_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_payjoin_proposal_owned_vouts(int64_t port_,
                                                              struct wire_cst_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_payjoin_proposal_psbt(int64_t port_,
                                                       struct wire_cst_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_payjoin_proposal_utxos_to_be_locked(int64_t port_,
                                                                     struct wire_cst_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_provisional_proposal_contribute_non_witness_input(int64_t port_,
                                                                                   struct wire_cst_provisional_proposal *that,
                                                                                   struct wire_cst_list_prim_u_8_loose *tx,
                                                                                   struct wire_cst_out_point *outpoint);

void frbgen_payjoin_flutter_wire_provisional_proposal_contribute_witness_input(int64_t port_,
                                                                               struct wire_cst_provisional_proposal *that,
                                                                               struct wire_cst_tx_out *txo,
                                                                               struct wire_cst_out_point *outpoint);

void frbgen_payjoin_flutter_wire_provisional_proposal_finalize_proposal(int64_t port_,
                                                                        struct wire_cst_provisional_proposal *ptr,
                                                                        const void *process_psbt,
                                                                        uint64_t *min_feerate_sat_per_vb);

void frbgen_payjoin_flutter_wire_provisional_proposal_substitute_output_address(int64_t port_,
                                                                                struct wire_cst_provisional_proposal *that,
                                                                                struct wire_cst_list_prim_u_8_strict *address);

void frbgen_payjoin_flutter_wire_provisional_proposal_try_preserving_privacy(int64_t port_,
                                                                             struct wire_cst_provisional_proposal *that,
                                                                             struct wire_cst_list_record_u_64_out_point *candidate_inputs);

void frbgen_payjoin_flutter_wire_unchecked_proposal_assume_interactive_receiver(int64_t port_,
                                                                                struct wire_cst_unchecked_proposal *ptr);

void frbgen_payjoin_flutter_wire_unchecked_proposal_check_broadcast_suitability(int64_t port_,
                                                                                struct wire_cst_unchecked_proposal *ptr,
                                                                                uint64_t *min_fee_rate,
                                                                                const void *can_broadcast);

void frbgen_payjoin_flutter_wire_unchecked_proposal_extract_tx_to_schedule_broadcast(int64_t port_,
                                                                                     struct wire_cst_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire_unchecked_proposal_from_request(int64_t port_,
                                                                 struct wire_cst_list_prim_u_8_loose *body,
                                                                 struct wire_cst_list_prim_u_8_strict *query,
                                                                 struct wire_cst_headers *headers);

void frbgen_payjoin_flutter_wire_v_2_maybe_inputs_owned_check_inputs_not_owned(int64_t port_,
                                                                               struct wire_cst_v_2_maybe_inputs_owned *that,
                                                                               const void *is_owned);

void frbgen_payjoin_flutter_wire_v_2_maybe_inputs_seen_check_no_inputs_seen_before(int64_t port_,
                                                                                   struct wire_cst_v_2_maybe_inputs_seen *that,
                                                                                   const void *is_known);

void frbgen_payjoin_flutter_wire_v_2_maybe_mixed_input_scripts_check_no_mixed_input_scripts(int64_t port_,
                                                                                            struct wire_cst_v_2_maybe_mixed_input_scripts *that);

void frbgen_payjoin_flutter_wire_v_2_outputs_unknown_identify_receiver_outputs(int64_t port_,
                                                                               struct wire_cst_v_2_outputs_unknown *that,
                                                                               const void *is_receiver_output);

void frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_deserialize_res(int64_t port_,
                                                                      struct wire_cst_v_2_payjoin_proposal *that,
                                                                      struct wire_cst_list_prim_u_8_loose *res,
                                                                      struct wire_cst_client_response *ohttp_context);

void frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_extract_v1_req(int64_t port_,
                                                                     struct wire_cst_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_extract_v2_req(int64_t port_,
                                                                     struct wire_cst_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_is_output_substitution_disabled(int64_t port_,
                                                                                      struct wire_cst_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_owned_vouts(int64_t port_,
                                                                  struct wire_cst_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_psbt(int64_t port_,
                                                           struct wire_cst_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_utxos_to_be_locked(int64_t port_,
                                                                         struct wire_cst_v_2_payjoin_proposal *that);

void frbgen_payjoin_flutter_wire_v_2_provisional_proposal_contribute_non_witness_input(int64_t port_,
                                                                                       struct wire_cst_v_2_provisional_proposal *that,
                                                                                       struct wire_cst_list_prim_u_8_loose *tx,
                                                                                       struct wire_cst_out_point *outpoint);

void frbgen_payjoin_flutter_wire_v_2_provisional_proposal_contribute_witness_input(int64_t port_,
                                                                                   struct wire_cst_v_2_provisional_proposal *that,
                                                                                   struct wire_cst_tx_out *txo,
                                                                                   struct wire_cst_out_point *outpoint);

void frbgen_payjoin_flutter_wire_v_2_provisional_proposal_finalize_proposal(int64_t port_,
                                                                            struct wire_cst_v_2_provisional_proposal *that,
                                                                            const void *process_psbt,
                                                                            uint64_t *min_feerate_sat_per_vb);

void frbgen_payjoin_flutter_wire_v_2_provisional_proposal_substitute_output_address(int64_t port_,
                                                                                    struct wire_cst_v_2_provisional_proposal *that,
                                                                                    struct wire_cst_list_prim_u_8_strict *address);

void frbgen_payjoin_flutter_wire_v_2_provisional_proposal_try_preserving_privacy(int64_t port_,
                                                                                 struct wire_cst_v_2_provisional_proposal *that,
                                                                                 struct wire_cst_list_record_u_64_out_point *candidate_inputs);

void frbgen_payjoin_flutter_wire_v_2_unchecked_proposal_assume_interactive_receiver(int64_t port_,
                                                                                    struct wire_cst_v_2_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire_v_2_unchecked_proposal_check_broadcast_suitability(int64_t port_,
                                                                                    struct wire_cst_v_2_unchecked_proposal *that,
                                                                                    uint64_t *min_fee_rate,
                                                                                    const void *can_broadcast);

void frbgen_payjoin_flutter_wire_v_2_unchecked_proposal_extract_tx_to_schedule_broadcast(int64_t port_,
                                                                                         struct wire_cst_v_2_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire_context_v_1_process_response(int64_t port_,
                                                              struct wire_cst_context_v_1 *that,
                                                              struct wire_cst_list_prim_u_8_loose *response);

void frbgen_payjoin_flutter_wire_context_v_2_process_response(int64_t port_,
                                                              struct wire_cst_context_v_2 *that,
                                                              struct wire_cst_list_prim_u_8_loose *response);

void frbgen_payjoin_flutter_wire_request_builder_always_disable_output_substitution(int64_t port_,
                                                                                    struct wire_cst_request_builder *that,
                                                                                    bool disable);

void frbgen_payjoin_flutter_wire_request_builder_build_non_incentivizing(int64_t port_,
                                                                         struct wire_cst_request_builder *that);

void frbgen_payjoin_flutter_wire_request_builder_build_recommended(int64_t port_,
                                                                   struct wire_cst_request_builder *that,
                                                                   uint64_t min_fee_rate);

void frbgen_payjoin_flutter_wire_request_builder_build_with_additional_fee(int64_t port_,
                                                                           struct wire_cst_request_builder *that,
                                                                           uint64_t max_fee_contribution,
                                                                           uint8_t *change_index,
                                                                           uint64_t min_fee_rate,
                                                                           bool clamp_fee_contribution);

void frbgen_payjoin_flutter_wire_request_builder_from_psbt_and_uri(int64_t port_,
                                                                   struct wire_cst_list_prim_u_8_strict *psbt_base64,
                                                                   struct wire_cst_uri *uri);

void frbgen_payjoin_flutter_wire_request_context_extract_v1(int64_t port_,
                                                            struct wire_cst_request_context *that);

void frbgen_payjoin_flutter_wire_request_context_extract_v2(int64_t port_,
                                                            struct wire_cst_request_context *that,
                                                            struct wire_cst_list_prim_u_8_strict *ohttp_proxy_url);

void frbgen_payjoin_flutter_wire_uri_address(int64_t port_, struct wire_cst_uri *that);

void frbgen_payjoin_flutter_wire_uri_amount(int64_t port_, struct wire_cst_uri *that);

void frbgen_payjoin_flutter_wire_uri_from_str(int64_t port_,
                                              struct wire_cst_list_prim_u_8_strict *uri);

void frbgen_payjoin_flutter_wire_url_from_str(int64_t port_,
                                              struct wire_cst_list_prim_u_8_strict *url);

void frbgen_payjoin_flutter_wire_url_query(int64_t port_, struct wire_cst_url *that);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeMixedInputScripts(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeMixedInputScripts(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1OutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1OutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1PayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1PayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1ProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1ProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2Enrolled(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2Enrolled(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeInputsOwned(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeInputsSeen(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeMixedInputScripts(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeMixedInputScripts(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2OutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2OutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2PayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2PayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2ProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2ProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv1ContextV1(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv1ContextV1(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv1RequestBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv1RequestBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv1RequestContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv1RequestContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffiuriUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffiuriUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffiuriUrl(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffiuriUrl(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_MutexOptionohttpClientResponse(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_MutexOptionohttpClientResponse(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1UncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1UncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2Enroller(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2Enroller(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2UncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2UncheckedProposal(const void *ptr);

struct wire_cst_client_response *frbgen_payjoin_flutter_cst_new_box_autoadd_client_response(void);

struct wire_cst_context_v_1 *frbgen_payjoin_flutter_cst_new_box_autoadd_context_v_1(void);

struct wire_cst_context_v_2 *frbgen_payjoin_flutter_cst_new_box_autoadd_context_v_2(void);

struct wire_cst_enrolled *frbgen_payjoin_flutter_cst_new_box_autoadd_enrolled(void);

struct wire_cst_enroller *frbgen_payjoin_flutter_cst_new_box_autoadd_enroller(void);

struct wire_cst_headers *frbgen_payjoin_flutter_cst_new_box_autoadd_headers(void);

struct wire_cst_maybe_inputs_owned *frbgen_payjoin_flutter_cst_new_box_autoadd_maybe_inputs_owned(void);

struct wire_cst_maybe_inputs_seen *frbgen_payjoin_flutter_cst_new_box_autoadd_maybe_inputs_seen(void);

struct wire_cst_maybe_mixed_input_scripts *frbgen_payjoin_flutter_cst_new_box_autoadd_maybe_mixed_input_scripts(void);

struct wire_cst_out_point *frbgen_payjoin_flutter_cst_new_box_autoadd_out_point(void);

struct wire_cst_outputs_unknown *frbgen_payjoin_flutter_cst_new_box_autoadd_outputs_unknown(void);

struct wire_cst_payjoin_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_payjoin_proposal(void);

struct wire_cst_provisional_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_provisional_proposal(void);

struct wire_cst_request_builder *frbgen_payjoin_flutter_cst_new_box_autoadd_request_builder(void);

struct wire_cst_request_context *frbgen_payjoin_flutter_cst_new_box_autoadd_request_context(void);

struct wire_cst_tx_out *frbgen_payjoin_flutter_cst_new_box_autoadd_tx_out(void);

uint64_t *frbgen_payjoin_flutter_cst_new_box_autoadd_u_64(uint64_t value);

uint8_t *frbgen_payjoin_flutter_cst_new_box_autoadd_u_8(uint8_t value);

struct wire_cst_unchecked_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_unchecked_proposal(void);

struct wire_cst_uri *frbgen_payjoin_flutter_cst_new_box_autoadd_uri(void);

struct wire_cst_url *frbgen_payjoin_flutter_cst_new_box_autoadd_url(void);

struct wire_cst_v_2_maybe_inputs_owned *frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_maybe_inputs_owned(void);

struct wire_cst_v_2_maybe_inputs_seen *frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_maybe_inputs_seen(void);

struct wire_cst_v_2_maybe_mixed_input_scripts *frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_maybe_mixed_input_scripts(void);

struct wire_cst_v_2_outputs_unknown *frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_outputs_unknown(void);

struct wire_cst_v_2_payjoin_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_payjoin_proposal(void);

struct wire_cst_v_2_provisional_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_provisional_proposal(void);

struct wire_cst_v_2_unchecked_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_unchecked_proposal(void);

struct wire_cst_list_out_point *frbgen_payjoin_flutter_cst_new_list_out_point(int32_t len);

struct wire_cst_list_prim_u_64_strict *frbgen_payjoin_flutter_cst_new_list_prim_u_64_strict(int32_t len);

struct wire_cst_list_prim_u_8_loose *frbgen_payjoin_flutter_cst_new_list_prim_u_8_loose(int32_t len);

struct wire_cst_list_prim_u_8_strict *frbgen_payjoin_flutter_cst_new_list_prim_u_8_strict(int32_t len);

struct wire_cst_list_record_string_string *frbgen_payjoin_flutter_cst_new_list_record_string_string(int32_t len);

struct wire_cst_list_record_u_64_out_point *frbgen_payjoin_flutter_cst_new_list_record_u_64_out_point(int32_t len);
static int64_t dummy_method_to_enforce_bundling(void) {
    int64_t dummy_var = 0;
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_client_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_context_v_1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_context_v_2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_enrolled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_enroller);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_headers);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_maybe_inputs_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_maybe_inputs_seen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_maybe_mixed_input_scripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_out_point);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_outputs_unknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_payjoin_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_provisional_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_request_builder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_request_context);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_tx_out);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_u_64);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_u_8);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_unchecked_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_url);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_maybe_inputs_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_maybe_inputs_seen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_maybe_mixed_input_scripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_outputs_unknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_payjoin_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_provisional_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_v_2_unchecked_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_out_point);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_prim_u_64_strict);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_prim_u_8_loose);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_prim_u_8_strict);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_record_string_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_list_record_u_64_out_point);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeMixedInputScripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1OutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1PayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev1ProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2Enrolled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeMixedInputScripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2OutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2PayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2ProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv1ContextV1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv1RequestBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv1RequestContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffiuriUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_Arcpayjoin_ffiuriUrl);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_MutexOptionohttpClientResponse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev1UncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2Enroller);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivev2V2UncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1MaybeMixedInputScripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1OutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1PayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev1ProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2Enrolled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2MaybeMixedInputScripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2OutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2PayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffireceivev2V2ProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv1ContextV1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv1RequestBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv1RequestContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffisendv2ContextV2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffiuriUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_Arcpayjoin_ffiuriUrl);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_MutexOptionohttpClientResponse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev1UncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2Enroller);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivev2V2UncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_context_v_1_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_context_v_2_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_enrolled_extract_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_enrolled_fallback_target);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_enrolled_process_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_enrolled_subdirectory);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_enroller_extract_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_enroller_from_relay_config);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_enroller_payjoin_subdir);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_enroller_process_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_enroller_subdirectory);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_maybe_inputs_owned_check_inputs_not_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_maybe_inputs_seen_check_no_inputs_seen_before);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_maybe_mixed_input_scripts_check_no_mixed_input_scripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_outputs_unknown_identify_receiver_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_payjoin_proposal_is_output_substitution_disabled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_payjoin_proposal_owned_vouts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_payjoin_proposal_psbt);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_payjoin_proposal_utxos_to_be_locked);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_provisional_proposal_contribute_non_witness_input);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_provisional_proposal_contribute_witness_input);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_provisional_proposal_finalize_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_provisional_proposal_substitute_output_address);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_provisional_proposal_try_preserving_privacy);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_request_builder_always_disable_output_substitution);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_request_builder_build_non_incentivizing);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_request_builder_build_recommended);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_request_builder_build_with_additional_fee);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_request_builder_from_psbt_and_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_request_context_extract_v1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_request_context_extract_v2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_unchecked_proposal_assume_interactive_receiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_unchecked_proposal_check_broadcast_suitability);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_unchecked_proposal_extract_tx_to_schedule_broadcast);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_unchecked_proposal_from_request);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_uri_address);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_uri_amount);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_uri_from_str);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_url_from_str);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_url_query);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_maybe_inputs_owned_check_inputs_not_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_maybe_inputs_seen_check_no_inputs_seen_before);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_maybe_mixed_input_scripts_check_no_mixed_input_scripts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_outputs_unknown_identify_receiver_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_deserialize_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_extract_v1_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_extract_v2_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_is_output_substitution_disabled);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_owned_vouts);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_psbt);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_payjoin_proposal_utxos_to_be_locked);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_provisional_proposal_contribute_non_witness_input);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_provisional_proposal_contribute_witness_input);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_provisional_proposal_finalize_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_provisional_proposal_substitute_output_address);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_provisional_proposal_try_preserving_privacy);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_unchecked_proposal_assume_interactive_receiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_unchecked_proposal_check_broadcast_suitability);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire_v_2_unchecked_proposal_extract_tx_to_schedule_broadcast);
    dummy_var ^= ((int64_t) (void*) store_dart_post_cobject);
    return dummy_var;
}
