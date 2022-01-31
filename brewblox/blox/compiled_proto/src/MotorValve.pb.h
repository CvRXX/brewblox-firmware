/* Automatically generated nanopb header */

#ifndef PB_BLOX_MOTORVALVE_MOTORVALVE_PB_H_INCLUDED
#define PB_BLOX_MOTORVALVE_MOTORVALVE_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

#include "Constraints.pb.h"

#include "IoArray.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _blox_MotorValve_ValveState {
    blox_MotorValve_ValveState_VALVE_UNKNOWN = 0,
    blox_MotorValve_ValveState_VALVE_OPEN = 1,
    blox_MotorValve_ValveState_VALVE_CLOSED = 2,
    blox_MotorValve_ValveState_VALVE_OPENING = 3,
    blox_MotorValve_ValveState_VALVE_CLOSING = 4,
    blox_MotorValve_ValveState_VALVE_HALF_OPEN_IDLE = 5,
    blox_MotorValve_ValveState_VALVE_INIT_IDLE = 6
} blox_MotorValve_ValveState;
#define _blox_MotorValve_ValveState_MIN blox_MotorValve_ValveState_VALVE_UNKNOWN
#define _blox_MotorValve_ValveState_MAX blox_MotorValve_ValveState_VALVE_INIT_IDLE
#define _blox_MotorValve_ValveState_ARRAYSIZE ((blox_MotorValve_ValveState)(blox_MotorValve_ValveState_VALVE_INIT_IDLE+1))

/* Struct definitions */
typedef struct _blox_MotorValve_Block {
    uint16_t hwDevice;
    uint8_t startChannel;
    blox_IoArray_DigitalState state;
    blox_Constraints_DigitalConstraints constrainedBy;
    blox_MotorValve_ValveState valveState;
    blox_IoArray_DigitalState desiredState;
    pb_size_t strippedFields_count;
    uint16_t strippedFields[2];
/* @@protoc_insertion_point(struct:blox_MotorValve_Block) */
} blox_MotorValve_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_MotorValve_Block_init_default       {0, 0, _blox_IoArray_DigitalState_MIN, blox_Constraints_DigitalConstraints_init_default, _blox_MotorValve_ValveState_MIN, _blox_IoArray_DigitalState_MIN, 0, {0, 0}}
#define blox_MotorValve_Block_init_zero          {0, 0, _blox_IoArray_DigitalState_MIN, blox_Constraints_DigitalConstraints_init_zero, _blox_MotorValve_ValveState_MIN, _blox_IoArray_DigitalState_MIN, 0, {0, 0}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_MotorValve_Block_hwDevice_tag       1
#define blox_MotorValve_Block_startChannel_tag   2
#define blox_MotorValve_Block_state_tag          3
#define blox_MotorValve_Block_constrainedBy_tag  5
#define blox_MotorValve_Block_valveState_tag     6
#define blox_MotorValve_Block_desiredState_tag   7
#define blox_MotorValve_Block_strippedFields_tag 99

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_MotorValve_Block_fields[8];

/* Maximum encoded size of messages (where known) */
#define blox_MotorValve_Block_size               251

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define MOTORVALVE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
