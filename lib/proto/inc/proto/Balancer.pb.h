/* Automatically generated nanopb header */

#ifndef PB_BLOX_BALANCER_BALANCER_PB_H_INCLUDED
#define PB_BLOX_BALANCER_BALANCER_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _blox_Balancer_Block {
    pb_callback_t clients;
/* @@protoc_insertion_point(struct:blox_Balancer_Block) */
} blox_Balancer_Block;

typedef struct _blox_Balancer_BalancedActuator {
    uint8_t id;
    int32_t requested;
    int32_t granted;
/* @@protoc_insertion_point(struct:blox_Balancer_BalancedActuator) */
} blox_Balancer_BalancedActuator;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Balancer_BalancedActuator_init_default {0, 0, 0}
#define blox_Balancer_Block_init_default         {{{NULL}, NULL}}
#define blox_Balancer_BalancedActuator_init_zero {0, 0, 0}
#define blox_Balancer_Block_init_zero            {{{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Balancer_Block_clients_tag          1
#define blox_Balancer_BalancedActuator_id_tag    1
#define blox_Balancer_BalancedActuator_requested_tag 2
#define blox_Balancer_BalancedActuator_granted_tag 3

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Balancer_BalancedActuator_fields[4];
extern const pb_field_t blox_Balancer_Block_fields[2];

/* Maximum encoded size of messages (where known) */
#define blox_Balancer_BalancedActuator_size      18
/* blox_Balancer_Block_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define BALANCER_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
