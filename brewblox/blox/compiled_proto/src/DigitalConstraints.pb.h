/* Automatically generated nanopb header */

#ifndef PB_BLOX_DIGITALCONSTRAINTS_PB_H_INCLUDED
#define PB_BLOX_DIGITALCONSTRAINTS_PB_H_INCLUDED
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
typedef struct _blox_Mutexed {
    uint16_t mutexId;
    uint32_t extraHoldTime;
    bool hasCustomHoldTime;
    bool hasLock;
/* @@protoc_insertion_point(struct:blox_Mutexed) */
} blox_Mutexed;

typedef struct _blox_DigitalConstraint {
    pb_size_t which_constraint;
    union {
        uint32_t minOff;
        uint32_t minOn;
        uint16_t mutex;
        blox_Mutexed mutexed;
        uint32_t delayedOff;
        uint32_t delayedOn;
    } constraint;
    uint32_t remaining;
/* @@protoc_insertion_point(struct:blox_DigitalConstraint) */
} blox_DigitalConstraint;

typedef struct _blox_DigitalConstraints {
    pb_size_t constraints_count;
    blox_DigitalConstraint constraints[8];
/* @@protoc_insertion_point(struct:blox_DigitalConstraints) */
} blox_DigitalConstraints;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Mutexed_init_default                {0, 0, 0, 0}
#define blox_DigitalConstraint_init_default      {0, {0}, 0}
#define blox_DigitalConstraints_init_default     {0, {blox_DigitalConstraint_init_default, blox_DigitalConstraint_init_default, blox_DigitalConstraint_init_default, blox_DigitalConstraint_init_default, blox_DigitalConstraint_init_default, blox_DigitalConstraint_init_default, blox_DigitalConstraint_init_default, blox_DigitalConstraint_init_default}}
#define blox_Mutexed_init_zero                   {0, 0, 0, 0}
#define blox_DigitalConstraint_init_zero         {0, {0}, 0}
#define blox_DigitalConstraints_init_zero        {0, {blox_DigitalConstraint_init_zero, blox_DigitalConstraint_init_zero, blox_DigitalConstraint_init_zero, blox_DigitalConstraint_init_zero, blox_DigitalConstraint_init_zero, blox_DigitalConstraint_init_zero, blox_DigitalConstraint_init_zero, blox_DigitalConstraint_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Mutexed_mutexId_tag                 1
#define blox_Mutexed_extraHoldTime_tag           2
#define blox_Mutexed_hasCustomHoldTime_tag       3
#define blox_Mutexed_hasLock_tag                 4
#define blox_DigitalConstraint_minOff_tag        1
#define blox_DigitalConstraint_minOn_tag         2
#define blox_DigitalConstraint_mutex_tag         3
#define blox_DigitalConstraint_mutexed_tag       4
#define blox_DigitalConstraint_delayedOff_tag    5
#define blox_DigitalConstraint_delayedOn_tag     6
#define blox_DigitalConstraint_remaining_tag     101
#define blox_DigitalConstraints_constraints_tag  1

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Mutexed_fields[5];
extern const pb_field_t blox_DigitalConstraint_fields[8];
extern const pb_field_t blox_DigitalConstraints_fields[2];

/* Maximum encoded size of messages (where known) */
#define blox_Mutexed_size                        16
#define blox_DigitalConstraint_size              25
#define blox_DigitalConstraints_size             216

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DIGITALCONSTRAINTS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
