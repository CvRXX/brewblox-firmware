/* Automatically generated nanopb header */

#ifndef PB_BLOX_CONSTRAINTS_CONSTRAINTS_PB_H_INCLUDED
#define PB_BLOX_CONSTRAINTS_CONSTRAINTS_PB_H_INCLUDED
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
typedef struct _blox_Constraints_Balanced {
    uint16_t balancerId;
    uint32_t granted;
    uint8_t id;
/* @@protoc_insertion_point(struct:blox_Constraints_Balanced) */
} blox_Constraints_Balanced;

typedef struct _blox_Constraints_Mutexed {
    uint16_t mutexId;
    uint32_t extraHoldTime;
    bool hasCustomHoldTime;
    bool hasLock;
/* @@protoc_insertion_point(struct:blox_Constraints_Mutexed) */
} blox_Constraints_Mutexed;

typedef struct _blox_Constraints_AnalogConstraint {
    pb_size_t which_constraint;
    union {
        int32_t min;
        int32_t max;
        blox_Constraints_Balanced balanced;
    } constraint;
    bool limiting;
/* @@protoc_insertion_point(struct:blox_Constraints_AnalogConstraint) */
} blox_Constraints_AnalogConstraint;

typedef struct _blox_Constraints_DigitalConstraint {
    pb_size_t which_constraint;
    union {
        uint32_t minOff;
        uint32_t minOn;
        uint16_t mutex;
        blox_Constraints_Mutexed mutexed;
        uint32_t delayedOff;
        uint32_t delayedOn;
    } constraint;
    uint32_t remaining;
/* @@protoc_insertion_point(struct:blox_Constraints_DigitalConstraint) */
} blox_Constraints_DigitalConstraint;

typedef struct _blox_Constraints_AnalogConstraints {
    pb_size_t constraints_count;
    blox_Constraints_AnalogConstraint constraints[8];
/* @@protoc_insertion_point(struct:blox_Constraints_AnalogConstraints) */
} blox_Constraints_AnalogConstraints;

typedef struct _blox_Constraints_DigitalConstraints {
    pb_size_t constraints_count;
    blox_Constraints_DigitalConstraint constraints[8];
/* @@protoc_insertion_point(struct:blox_Constraints_DigitalConstraints) */
} blox_Constraints_DigitalConstraints;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Constraints_Balanced_init_default   {0, 0, 0}
#define blox_Constraints_Mutexed_init_default    {0, 0, 0, 0}
#define blox_Constraints_AnalogConstraint_init_default {0, {0}, 0}
#define blox_Constraints_AnalogConstraints_init_default {0, {blox_Constraints_AnalogConstraint_init_default, blox_Constraints_AnalogConstraint_init_default, blox_Constraints_AnalogConstraint_init_default, blox_Constraints_AnalogConstraint_init_default, blox_Constraints_AnalogConstraint_init_default, blox_Constraints_AnalogConstraint_init_default, blox_Constraints_AnalogConstraint_init_default, blox_Constraints_AnalogConstraint_init_default}}
#define blox_Constraints_DigitalConstraint_init_default {0, {0}, 0}
#define blox_Constraints_DigitalConstraints_init_default {0, {blox_Constraints_DigitalConstraint_init_default, blox_Constraints_DigitalConstraint_init_default, blox_Constraints_DigitalConstraint_init_default, blox_Constraints_DigitalConstraint_init_default, blox_Constraints_DigitalConstraint_init_default, blox_Constraints_DigitalConstraint_init_default, blox_Constraints_DigitalConstraint_init_default, blox_Constraints_DigitalConstraint_init_default}}
#define blox_Constraints_Balanced_init_zero      {0, 0, 0}
#define blox_Constraints_Mutexed_init_zero       {0, 0, 0, 0}
#define blox_Constraints_AnalogConstraint_init_zero {0, {0}, 0}
#define blox_Constraints_AnalogConstraints_init_zero {0, {blox_Constraints_AnalogConstraint_init_zero, blox_Constraints_AnalogConstraint_init_zero, blox_Constraints_AnalogConstraint_init_zero, blox_Constraints_AnalogConstraint_init_zero, blox_Constraints_AnalogConstraint_init_zero, blox_Constraints_AnalogConstraint_init_zero, blox_Constraints_AnalogConstraint_init_zero, blox_Constraints_AnalogConstraint_init_zero}}
#define blox_Constraints_DigitalConstraint_init_zero {0, {0}, 0}
#define blox_Constraints_DigitalConstraints_init_zero {0, {blox_Constraints_DigitalConstraint_init_zero, blox_Constraints_DigitalConstraint_init_zero, blox_Constraints_DigitalConstraint_init_zero, blox_Constraints_DigitalConstraint_init_zero, blox_Constraints_DigitalConstraint_init_zero, blox_Constraints_DigitalConstraint_init_zero, blox_Constraints_DigitalConstraint_init_zero, blox_Constraints_DigitalConstraint_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Constraints_Balanced_balancerId_tag 1
#define blox_Constraints_Balanced_granted_tag    2
#define blox_Constraints_Balanced_id_tag         3
#define blox_Constraints_Mutexed_mutexId_tag     1
#define blox_Constraints_Mutexed_extraHoldTime_tag 2
#define blox_Constraints_Mutexed_hasCustomHoldTime_tag 3
#define blox_Constraints_Mutexed_hasLock_tag     4
#define blox_Constraints_AnalogConstraint_min_tag 1
#define blox_Constraints_AnalogConstraint_max_tag 2
#define blox_Constraints_AnalogConstraint_balanced_tag 3
#define blox_Constraints_AnalogConstraint_limiting_tag 100
#define blox_Constraints_DigitalConstraint_minOff_tag 1
#define blox_Constraints_DigitalConstraint_minOn_tag 2
#define blox_Constraints_DigitalConstraint_mutex_tag 3
#define blox_Constraints_DigitalConstraint_mutexed_tag 4
#define blox_Constraints_DigitalConstraint_delayedOff_tag 5
#define blox_Constraints_DigitalConstraint_delayedOn_tag 6
#define blox_Constraints_DigitalConstraint_remaining_tag 101
#define blox_Constraints_AnalogConstraints_constraints_tag 1
#define blox_Constraints_DigitalConstraints_constraints_tag 1

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Constraints_Balanced_fields[4];
extern const pb_field_t blox_Constraints_Mutexed_fields[5];
extern const pb_field_t blox_Constraints_AnalogConstraint_fields[5];
extern const pb_field_t blox_Constraints_AnalogConstraints_fields[2];
extern const pb_field_t blox_Constraints_DigitalConstraint_fields[8];
extern const pb_field_t blox_Constraints_DigitalConstraints_fields[2];

/* Maximum encoded size of messages (where known) */
#define blox_Constraints_Balanced_size           18
#define blox_Constraints_Mutexed_size            16
#define blox_Constraints_AnalogConstraint_size   23
#define blox_Constraints_AnalogConstraints_size  200
#define blox_Constraints_DigitalConstraint_size  25
#define blox_Constraints_DigitalConstraints_size 216

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define CONSTRAINTS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
