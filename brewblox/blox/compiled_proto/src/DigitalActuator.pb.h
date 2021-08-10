/* Automatically generated nanopb header */

#ifndef PB_BLOX_DIGITALACTUATOR_PB_H_INCLUDED
#define PB_BLOX_DIGITALACTUATOR_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

#include "DigitalConstraints.pb.h"

#include "IoArray.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _blox_DigitalActuator {
    uint16_t hwDevice;
    uint8_t channel;
    blox_DigitalState state;
    bool invert;
    blox_DigitalConstraints constrainedBy;
    blox_DigitalState desiredState;
    pb_size_t strippedFields_count;
    uint16_t strippedFields[1];
/* @@protoc_insertion_point(struct:blox_DigitalActuator) */
} blox_DigitalActuator;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_DigitalActuator_init_default        {0, 0, _blox_DigitalState_MIN, 0, blox_DigitalConstraints_init_default, _blox_DigitalState_MIN, 0, {0}}
#define blox_DigitalActuator_init_zero           {0, 0, _blox_DigitalState_MIN, 0, blox_DigitalConstraints_init_zero, _blox_DigitalState_MIN, 0, {0}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_DigitalActuator_hwDevice_tag        1
#define blox_DigitalActuator_channel_tag         2
#define blox_DigitalActuator_state_tag           3
#define blox_DigitalActuator_invert_tag          4
#define blox_DigitalActuator_constrainedBy_tag   5
#define blox_DigitalActuator_desiredState_tag    6
#define blox_DigitalActuator_strippedFields_tag  99

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_DigitalActuator_fields[8];

/* Maximum encoded size of messages (where known) */
#define blox_DigitalActuator_size                245

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DIGITALACTUATOR_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
