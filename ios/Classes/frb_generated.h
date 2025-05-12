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

typedef struct wire_cst_list_prim_u_8_strict {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_strict;

typedef struct wire_cst_list_prim_u_8_loose {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_loose;

typedef struct wire_cst_client_response {
  uintptr_t field0;
} wire_cst_client_response;

typedef struct wire_cst_ffi_url {
  uintptr_t field0;
} wire_cst_ffi_url;

typedef struct wire_cst_out_point {
  struct wire_cst_list_prim_u_8_strict *txid;
  uint32_t vout;
} wire_cst_out_point;

typedef struct wire_cst_ffi_script {
  uintptr_t field0;
} wire_cst_ffi_script;

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

typedef struct wire_cst_ffi_ohttp_keys {
  uintptr_t field0;
} wire_cst_ffi_ohttp_keys;

typedef struct wire_cst_ffi_new_receiver {
  uintptr_t field0;
} wire_cst_ffi_new_receiver;

typedef struct wire_cst_ffi_new_sender {
  uintptr_t field0;
} wire_cst_ffi_new_sender;

typedef struct wire_cst_ffi_outputs_unknown {
  uintptr_t field0;
} wire_cst_ffi_outputs_unknown;

typedef struct wire_cst_ffi_payjoin_proposal {
  uintptr_t field0;
} wire_cst_ffi_payjoin_proposal;

typedef struct wire_cst_ffi_provisional_proposal {
  uintptr_t field0;
} wire_cst_ffi_provisional_proposal;

typedef struct wire_cst_ffi_sender_builder {
  uintptr_t field0;
} wire_cst_ffi_sender_builder;

typedef struct wire_cst_ffi_unchecked_proposal {
  uintptr_t field0;
} wire_cst_ffi_unchecked_proposal;

typedef struct wire_cst_ffi_uri {
  uintptr_t field0;
} wire_cst_ffi_uri;

typedef struct wire_cst_ffi_v_1_context {
  uintptr_t field0;
} wire_cst_ffi_v_1_context;

typedef struct wire_cst_ffi_v_2_get_context {
  uintptr_t field0;
} wire_cst_ffi_v_2_get_context;

typedef struct wire_cst_ffi_v_2_post_context {
  uintptr_t field0;
} wire_cst_ffi_v_2_post_context;

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

typedef struct wire_cst_list_out_point {
  struct wire_cst_out_point *ptr;
  int32_t len;
} wire_cst_list_out_point;

typedef struct wire_cst_ffi_build_sender_error {
  struct wire_cst_list_prim_u_8_strict *msg;
} wire_cst_ffi_build_sender_error;

typedef struct wire_cst_ffi_create_request_error {
  struct wire_cst_list_prim_u_8_strict *msg;
} wire_cst_ffi_create_request_error;

typedef struct wire_cst_ffi_encapsulation_error {
  struct wire_cst_list_prim_u_8_strict *msg;
} wire_cst_ffi_encapsulation_error;

typedef struct wire_cst_ffi_error {
  uintptr_t field0;
} wire_cst_ffi_error;

typedef struct wire_cst_ffi_implementation_error {
  uintptr_t field0;
} wire_cst_ffi_implementation_error;

typedef struct wire_cst_ffi_input_contribution_error {
  uintptr_t field0;
} wire_cst_ffi_input_contribution_error;

typedef struct wire_cst_ffi_into_url_error {
  uintptr_t field0;
} wire_cst_ffi_into_url_error;

typedef struct wire_cst_ffi_io_error {
  uintptr_t field0;
} wire_cst_ffi_io_error;

typedef struct wire_cst_ffi_ohttp_error {
  uintptr_t field0;
} wire_cst_ffi_ohttp_error;

typedef struct wire_cst_ffi_output_substitution_error {
  uintptr_t field0;
} wire_cst_ffi_output_substitution_error;

typedef struct wire_cst_ffi_pj_not_supported {
  uintptr_t field0;
} wire_cst_ffi_pj_not_supported;

typedef struct wire_cst_ffi_pj_parse_error {
  uintptr_t field0;
} wire_cst_ffi_pj_parse_error;

typedef struct wire_cst_ffi_psbt_input_error {
  uintptr_t field0;
} wire_cst_ffi_psbt_input_error;

typedef struct wire_cst_ffi_replyable_error {
  uintptr_t field0;
} wire_cst_ffi_replyable_error;

typedef struct wire_cst_ffi_response_error {
  uintptr_t field0;
} wire_cst_ffi_response_error;

typedef struct wire_cst_ffi_selection_error {
  uintptr_t field0;
} wire_cst_ffi_selection_error;

typedef struct wire_cst_ffi_serde_json_error {
  uintptr_t field0;
} wire_cst_ffi_serde_json_error;

typedef struct wire_cst_ffi_session_error {
  uintptr_t field0;
} wire_cst_ffi_session_error;

typedef struct wire_cst_ffi_url_parse_error {
  uintptr_t field0;
} wire_cst_ffi_url_parse_error;

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

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__DartReceiverPersister_new(const void *save,
                                                                                                 const void *load);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__send__DartSenderPersister_new(const void *save,
                                                                                            const void *load);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_address(uintptr_t that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_amount_sats(uintptr_t that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_as_string(uintptr_t that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_pj_endpoint(uintptr_t that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_set_amount_sats(uintptr_t that,
                                                                                            uint64_t amount);

void frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_extract_req(int64_t port_,
                                                                               uintptr_t that,
                                                                               struct wire_cst_list_prim_u_8_strict *ohttp_relay);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_from_json(struct wire_cst_list_prim_u_8_strict *json);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_id(uintptr_t that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_key(uintptr_t that);

void frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_load(int64_t port_,
                                                                        uintptr_t token,
                                                                        uintptr_t persister);

void frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_pj_uri(int64_t port_,
                                                                          uintptr_t that);

void frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_process_res(int64_t port_,
                                                                               uintptr_t that,
                                                                               struct wire_cst_list_prim_u_8_loose *body,
                                                                               struct wire_cst_client_response *ctx);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_to_json(uintptr_t that);

void frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_extract_v1(int64_t port_,
                                                                         uintptr_t that);

void frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_extract_v2(int64_t port_,
                                                                         uintptr_t that,
                                                                         struct wire_cst_ffi_url *ohttp_proxy_url);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_from_json(struct wire_cst_list_prim_u_8_strict *json);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_key(uintptr_t that);

void frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_load(int64_t port_,
                                                                   uintptr_t token,
                                                                   uintptr_t persister);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_to_json(uintptr_t that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__ReceiverToken_to_bytes(uintptr_t that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__send__SenderToken_to_bytes(uintptr_t that);

void frbgen_payjoin_flutter_wire__crate__api__io__fetch_ohttp_keys(int64_t port_,
                                                                   struct wire_cst_list_prim_u_8_strict *ohttp_relay,
                                                                   struct wire_cst_list_prim_u_8_strict *payjoin_directory);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_input_pair_new(int64_t port_,
                                                                          struct wire_cst_tx_in *txin,
                                                                          struct wire_cst_psbt_input *psbtin);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_owned_check_inputs_not_owned(int64_t port_,
                                                                                                     struct wire_cst_ffi_maybe_inputs_owned *that,
                                                                                                     const void *is_owned);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_seen_check_no_inputs_seen_before(int64_t port_,
                                                                                                         struct wire_cst_ffi_maybe_inputs_seen *that,
                                                                                                         const void *is_known);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__receive__ffi_new_receiver_create(struct wire_cst_list_prim_u_8_strict *address,
                                                                                               int32_t network,
                                                                                               struct wire_cst_list_prim_u_8_strict *directory,
                                                                                               struct wire_cst_ffi_ohttp_keys *ohttp_keys,
                                                                                               uint64_t *expire_after);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_new_receiver_persist(int64_t port_,
                                                                                struct wire_cst_ffi_new_receiver *that,
                                                                                uintptr_t persister);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_new_sender_persist(int64_t port_,
                                                                           struct wire_cst_ffi_new_sender *that,
                                                                           uintptr_t persister);

void frbgen_payjoin_flutter_wire__crate__api__uri__ffi_ohttp_keys_decode(int64_t port_,
                                                                         struct wire_cst_list_prim_u_8_loose *bytes);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_outputs_unknown_identify_receiver_outputs(int64_t port_,
                                                                                                     struct wire_cst_ffi_outputs_unknown *that,
                                                                                                     const void *is_receiver_output);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_extract_req(int64_t port_,
                                                                                        struct wire_cst_ffi_payjoin_proposal *that,
                                                                                        struct wire_cst_list_prim_u_8_strict *ohttp_relay);

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
                                                                                                  uint64_t *max_fee_rate_sat_per_vb);

void frbgen_payjoin_flutter_wire__crate__api__bitcoin_ffi__ffi_script_new(int64_t port_,
                                                                          struct wire_cst_list_prim_u_8_loose *raw_output_script);

void frbgen_payjoin_flutter_wire__crate__api__bitcoin_ffi__ffi_script_to_bytes(int64_t port_,
                                                                               struct wire_cst_ffi_script *that);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_always_disable_output_substitution(int64_t port_,
                                                                                                          struct wire_cst_ffi_sender_builder *that);

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
                                                                                         uintptr_t pj_uri);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_assume_interactive_receiver(int64_t port_,
                                                                                                          struct wire_cst_ffi_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_check_broadcast_suitability(int64_t port_,
                                                                                                          struct wire_cst_ffi_unchecked_proposal *that,
                                                                                                          uint64_t *min_fee_rate,
                                                                                                          const void *can_broadcast);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_extract_err_req(int64_t port_,
                                                                                              struct wire_cst_ffi_unchecked_proposal *that,
                                                                                              uintptr_t err,
                                                                                              struct wire_cst_list_prim_u_8_strict *ohttp_relay);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_extract_tx_to_schedule_broadcast(int64_t port_,
                                                                                                               struct wire_cst_ffi_unchecked_proposal *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_process_err_res(int64_t port_,
                                                                                              struct wire_cst_ffi_unchecked_proposal *that,
                                                                                              struct wire_cst_list_prim_u_8_loose *body,
                                                                                              struct wire_cst_client_response *context);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_address(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_amount_sats(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_as_string(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_check_pj_supported(struct wire_cst_ffi_uri *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_parse(struct wire_cst_list_prim_u_8_strict *uri);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_as_string(struct wire_cst_ffi_url *that);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_parse(struct wire_cst_list_prim_u_8_strict *url);

WireSyncRust2DartDco frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_query(struct wire_cst_ffi_url *that);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_1_context_process_response(int64_t port_,
                                                                                     struct wire_cst_ffi_v_1_context *that,
                                                                                     struct wire_cst_list_prim_u_8_loose *response);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_get_context_extract_req(int64_t port_,
                                                                                    struct wire_cst_ffi_v_2_get_context *that,
                                                                                    struct wire_cst_list_prim_u_8_strict *ohttp_relay);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_get_context_process_response(int64_t port_,
                                                                                         struct wire_cst_ffi_v_2_get_context *that,
                                                                                         struct wire_cst_list_prim_u_8_loose *response,
                                                                                         struct wire_cst_client_response *ohttp_ctx);

void frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_post_context_process_response(int64_t port_,
                                                                                          struct wire_cst_ffi_v_2_post_context *that,
                                                                                          struct wire_cst_list_prim_u_8_loose *response);

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

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_output_substitution(int64_t port_,
                                                                                             struct wire_cst_ffi_wants_outputs *that);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_replace_receiver_outputs(int64_t port_,
                                                                                                  struct wire_cst_ffi_wants_outputs *that,
                                                                                                  struct wire_cst_list_tx_out *replacement_outputs,
                                                                                                  struct wire_cst_ffi_script *drain_script);

void frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_substitute_receiver_script(int64_t port_,
                                                                                                    struct wire_cst_ffi_wants_outputs *that,
                                                                                                    struct wire_cst_ffi_script *output_script);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_bitcoin_ffiScript(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_bitcoin_ffiScript(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerDartReceiverPersister(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerDartReceiverPersister(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerDartSenderPersister(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerDartSenderPersister(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiJsonReply(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiJsonReply(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiPjUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiPjUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiReceiver(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiReceiver(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiSender(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiSender(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerImplementationError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerImplementationError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerInputContributionError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerInputContributionError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerIntoUrlError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerIntoUrlError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerIoError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerIoError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOhttpError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOhttpError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOutputSubstitution(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOutputSubstitution(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOutputSubstitutionError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOutputSubstitutionError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPjNotSupported(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPjNotSupported(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPjParseError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPjParseError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPsbtInputError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPsbtInputError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerReceiverToken(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerReceiverToken(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerReplyableError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerReplyableError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerResponseError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerResponseError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSelectionError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSelectionError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSenderToken(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSenderToken(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSerdeJsonError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSerdeJsonError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSessionError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSessionError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerUrlParseError(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerUrlParseError(const void *ptr);

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

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveNewReceiver(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveNewReceiver(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveOutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveOutputsUnknown(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivePayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivePayjoinProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveProvisionalProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveWantsInputs(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveWantsInputs(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveWantsOutputs(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveWantsOutputs(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendNewSender(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendNewSender(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendSenderBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendSenderBuilder(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV1Context(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV1Context(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV2GetContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV2GetContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV2PostContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV2PostContext(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriUri(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionpayjoin_ffiClientResponse(const void *ptr);

void frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionpayjoin_ffiClientResponse(const void *ptr);

struct wire_cst_client_response *frbgen_payjoin_flutter_cst_new_box_autoadd_client_response(void);

struct wire_cst_ffi_maybe_inputs_owned *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_owned(void);

struct wire_cst_ffi_maybe_inputs_seen *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_maybe_inputs_seen(void);

struct wire_cst_ffi_new_receiver *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_new_receiver(void);

struct wire_cst_ffi_new_sender *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_new_sender(void);

struct wire_cst_ffi_ohttp_keys *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_ohttp_keys(void);

struct wire_cst_ffi_outputs_unknown *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_outputs_unknown(void);

struct wire_cst_ffi_payjoin_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_payjoin_proposal(void);

struct wire_cst_ffi_provisional_proposal *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_provisional_proposal(void);

struct wire_cst_ffi_script *frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_script(void);

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
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_new_receiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_new_sender);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_ohttp_keys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_outputs_unknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_payjoin_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_provisional_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_cst_new_box_autoadd_ffi_script);
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
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerDartReceiverPersister);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerDartSenderPersister);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiJsonReply);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiPjUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiReceiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiSender);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerImplementationError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerInputContributionError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerIntoUrlError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerIoError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOhttpError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOutputSubstitution);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOutputSubstitutionError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPjNotSupported);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPjParseError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPsbtInputError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerReceiverToken);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerReplyableError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerResponseError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSelectionError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSenderToken);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSerdeJsonError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSessionError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerUrlParseError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiOhttpKeys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiUrl);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveInputPair);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveNewReceiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveOutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceivePayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveWantsInputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffireceiveWantsOutputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendNewSender);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendSenderBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV1Context);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV2GetContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffisendV2PostContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_payjoin_ffiuriUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_decrement_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionpayjoin_ffiClientResponse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_bitcoin_ffiScript);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerDartReceiverPersister);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerDartSenderPersister);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiJsonReply);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiPjUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiReceiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerFfiSender);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerImplementationError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerInputContributionError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerIntoUrlError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerIoError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOhttpError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOutputSubstitution);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerOutputSubstitutionError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPjNotSupported);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPjParseError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerPsbtInputError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerReceiverToken);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerReplyableError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerResponseError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSelectionError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSenderToken);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSerdeJsonError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSessionError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerUrlParseError);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiOhttpKeys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiUrl);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveInputPair);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsOwned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveMaybeInputsSeen);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveNewReceiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveOutputsUnknown);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceivePayjoinProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveProvisionalProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveUncheckedProposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveWantsInputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffireceiveWantsOutputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendNewSender);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendSenderBuilder);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV1Context);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV2GetContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffisendV2PostContext);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_payjoin_ffiuriUri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_rust_arc_increment_strong_count_RustOpaque_stdsyncMutexcoreoptionOptionpayjoin_ffiClientResponse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__bitcoin_ffi__ffi_script_new);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__bitcoin_ffi__ffi_script_to_bytes);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__io__fetch_ohttp_keys);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__DartReceiverPersister_new);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_extract_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_from_json);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_id);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_key);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_load);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_pj_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_process_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__FfiReceiver_to_json);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ReceiverToken_to_bytes);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_input_pair_new);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_owned_check_inputs_not_owned);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_maybe_inputs_seen_check_no_inputs_seen_before);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_new_receiver_create);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_new_receiver_persist);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_outputs_unknown_identify_receiver_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_extract_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_process_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_psbt);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_payjoin_proposal_utxos_to_be_locked);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_provisional_proposal_finalize_proposal);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_assume_interactive_receiver);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_check_broadcast_suitability);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_extract_err_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_extract_tx_to_schedule_broadcast);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_unchecked_proposal_process_err_res);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_inputs_commit_inputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_inputs_contribute_inputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_inputs_try_preserving_privacy);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_commit_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_output_substitution);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_replace_receiver_outputs);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__receive__ffi_wants_outputs_substitute_receiver_script);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__DartSenderPersister_new);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_extract_v1);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_extract_v2);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_from_json);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_key);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_load);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__FfiSender_to_json);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__SenderToken_to_bytes);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_new_sender_persist);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_always_disable_output_substitution);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_build_non_incentivizing);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_build_recommended);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_build_with_additional_fee);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_sender_builder_from_psbt_and_uri);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_1_context_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_get_context_extract_req);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_get_context_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__send__ffi_v_2_post_context_process_response);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_address);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_amount_sats);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_as_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_pj_endpoint);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__FfiPjUri_set_amount_sats);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_ohttp_keys_decode);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_address);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_amount_sats);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_as_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_check_pj_supported);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_uri_parse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_as_string);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_parse);
    dummy_var ^= ((int64_t) (void*) frbgen_payjoin_flutter_wire__crate__api__uri__ffi_url_query);
    dummy_var ^= ((int64_t) (void*) store_dart_post_cobject);
    return dummy_var;
}
