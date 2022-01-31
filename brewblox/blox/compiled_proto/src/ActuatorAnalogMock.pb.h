/* Automatically generated nanopb header */

#ifndef PB_BLOX_ACTUATORANALOGMOCK_ACTUATORANALOGMOCK_PB_H_INCLUDED
#define PB_BLOX_ACTUATORANALOGMOCK_ACTUATORANALOGMOCK_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

#include "Constraints.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _blox_ActuatorAnalogMock_Block {
    int32_t setting;
    int32_t value;
    int32_t minSetting;
    int32_t maxSetting;
    int32_t minValue;
    int32_t maxValue;
    blox_Constraints_AnalogConstraints constrainedBy;
    int32_t desiredSetting;
    pb_size_t strippedFields_count;
    uint16_t strippedFields[2];
/* @@protoc_insertion_point(struct:blox_ActuatorAnalogMock_Block) */
} blox_ActuatorAnalogMock_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_ActuatorAnalogMock_Block_init_default {0, 0, 0, 0, 0, 0, blox_Constraints_AnalogConstraints_init_default, 0, 0, {0, 0}}
#define blox_ActuatorAnalogMock_Block_init_zero  {0, 0, 0, 0, 0, 0, blox_Constraints_AnalogConstraints_init_zero, 0, 0, {0, 0}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_ActuatorAnalogMock_Block_setting_tag 1
#define blox_ActuatorAnalogMock_Block_value_tag  2
#define blox_ActuatorAnalogMock_Block_minSetting_tag 4
#define blox_ActuatorAnalogMock_Block_maxSetting_tag 5
#define blox_ActuatorAnalogMock_Block_minValue_tag 6
#define blox_ActuatorAnalogMock_Block_maxValue_tag 7
#define blox_ActuatorAnalogMock_Block_constrainedBy_tag 8
#define blox_ActuatorAnalogMock_Block_desiredSetting_tag 9
#define blox_ActuatorAnalogMock_Block_strippedFields_tag 99

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_ActuatorAnalogMock_Block_fields[10];

/* Maximum encoded size of messages (where known) */
#define blox_ActuatorAnalogMock_Block_size       259

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ACTUATORANALOGMOCK_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
