/* Automatically generated nanopb header */

#ifndef PB_BLOX_DIGITALACTUATOR_DIGITALACTUATOR_PB_H_INCLUDED
#define PB_BLOX_DIGITALACTUATOR_DIGITALACTUATOR_PB_H_INCLUDED
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

/* Struct definitions */
typedef struct _blox_DigitalActuator_Block {
    uint16_t hwDevice;
    uint8_t channel;
    blox_IoArray_DigitalState state;
    bool invert;
    blox_Constraints_DigitalConstraints constrainedBy;
    blox_IoArray_DigitalState desiredState;
    blox_IoArray_TransitionDurationPreset transitionDurationPreset;
    uint32_t transitionDurationSetting;
    uint32_t transitionDurationValue;
/* @@protoc_insertion_point(struct:blox_DigitalActuator_Block) */
} blox_DigitalActuator_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_DigitalActuator_Block_init_default  {0, 0, _blox_IoArray_DigitalState_MIN, 0, blox_Constraints_DigitalConstraints_init_default, _blox_IoArray_DigitalState_MIN, _blox_IoArray_TransitionDurationPreset_MIN, 0, 0}
#define blox_DigitalActuator_Block_init_zero     {0, 0, _blox_IoArray_DigitalState_MIN, 0, blox_Constraints_DigitalConstraints_init_zero, _blox_IoArray_DigitalState_MIN, _blox_IoArray_TransitionDurationPreset_MIN, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_DigitalActuator_Block_hwDevice_tag  1
#define blox_DigitalActuator_Block_channel_tag   2
#define blox_DigitalActuator_Block_state_tag     3
#define blox_DigitalActuator_Block_invert_tag    4
#define blox_DigitalActuator_Block_constrainedBy_tag 5
#define blox_DigitalActuator_Block_desiredState_tag 6
#define blox_DigitalActuator_Block_transitionDurationPreset_tag 7
#define blox_DigitalActuator_Block_transitionDurationSetting_tag 8
#define blox_DigitalActuator_Block_transitionDurationValue_tag 9

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_DigitalActuator_Block_fields[10];

/* Maximum encoded size of messages (where known) */
#define blox_DigitalActuator_Block_size          251

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DIGITALACTUATOR_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
