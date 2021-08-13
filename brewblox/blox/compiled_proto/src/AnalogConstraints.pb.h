/* Automatically generated nanopb header */

#ifndef PB_BLOX_ANALOGCONSTRAINTS_PB_H_INCLUDED
#define PB_BLOX_ANALOGCONSTRAINTS_PB_H_INCLUDED
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
typedef struct _blox_Balanced {
    uint16_t balancerId;
    uint32_t granted;
    uint8_t id;
/* @@protoc_insertion_point(struct:blox_Balanced) */
} blox_Balanced;

typedef struct _blox_AnalogConstraint {
    pb_size_t which_constraint;
    union {
        int32_t min;
        int32_t max;
        blox_Balanced balanced;
    } constraint;
    bool limiting;
/* @@protoc_insertion_point(struct:blox_AnalogConstraint) */
} blox_AnalogConstraint;

typedef struct _blox_AnalogConstraints {
    pb_size_t constraints_count;
    blox_AnalogConstraint constraints[8];
/* @@protoc_insertion_point(struct:blox_AnalogConstraints) */
} blox_AnalogConstraints;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Balanced_init_default               {0, 0, 0}
#define blox_AnalogConstraint_init_default       {0, {0}, 0}
#define blox_AnalogConstraints_init_default      {0, {blox_AnalogConstraint_init_default, blox_AnalogConstraint_init_default, blox_AnalogConstraint_init_default, blox_AnalogConstraint_init_default, blox_AnalogConstraint_init_default, blox_AnalogConstraint_init_default, blox_AnalogConstraint_init_default, blox_AnalogConstraint_init_default}}
#define blox_Balanced_init_zero                  {0, 0, 0}
#define blox_AnalogConstraint_init_zero          {0, {0}, 0}
#define blox_AnalogConstraints_init_zero         {0, {blox_AnalogConstraint_init_zero, blox_AnalogConstraint_init_zero, blox_AnalogConstraint_init_zero, blox_AnalogConstraint_init_zero, blox_AnalogConstraint_init_zero, blox_AnalogConstraint_init_zero, blox_AnalogConstraint_init_zero, blox_AnalogConstraint_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Balanced_balancerId_tag             1
#define blox_Balanced_granted_tag                2
#define blox_Balanced_id_tag                     3
#define blox_AnalogConstraint_min_tag            1
#define blox_AnalogConstraint_max_tag            2
#define blox_AnalogConstraint_balanced_tag       3
#define blox_AnalogConstraint_limiting_tag       100
#define blox_AnalogConstraints_constraints_tag   1

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Balanced_fields[4];
extern const pb_field_t blox_AnalogConstraint_fields[5];
extern const pb_field_t blox_AnalogConstraints_fields[2];

/* Maximum encoded size of messages (where known) */
#define blox_Balanced_size                       18
#define blox_AnalogConstraint_size               23
#define blox_AnalogConstraints_size              200

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ANALOGCONSTRAINTS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
