/* Automatically generated nanopb header */

#ifndef PB_BLOX_ACTUATOROFFSET_ACTUATOROFFSET_PB_H_INCLUDED
#define PB_BLOX_ACTUATOROFFSET_ACTUATOROFFSET_PB_H_INCLUDED
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

/* Enum definitions */
typedef enum _blox_ActuatorOffset_ReferenceKind {
    blox_ActuatorOffset_ReferenceKind_REF_SETTING = 0,
    blox_ActuatorOffset_ReferenceKind_REF_VALUE = 1
} blox_ActuatorOffset_ReferenceKind;
#define _blox_ActuatorOffset_ReferenceKind_MIN blox_ActuatorOffset_ReferenceKind_REF_SETTING
#define _blox_ActuatorOffset_ReferenceKind_MAX blox_ActuatorOffset_ReferenceKind_REF_VALUE
#define _blox_ActuatorOffset_ReferenceKind_ARRAYSIZE ((blox_ActuatorOffset_ReferenceKind)(blox_ActuatorOffset_ReferenceKind_REF_VALUE+1))

/* Struct definitions */
typedef struct _blox_ActuatorOffset_Block {
    uint16_t targetId;
    uint16_t referenceId;
    blox_ActuatorOffset_ReferenceKind referenceSettingOrValue;
    int32_t setting;
    int32_t value;
    blox_Constraints_AnalogConstraints constrainedBy;
    bool enabled;
    int32_t desiredSetting;
    uint16_t claimedBy;
    bool drivenTargetId;
/* @@protoc_insertion_point(struct:blox_ActuatorOffset_Block) */
} blox_ActuatorOffset_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_ActuatorOffset_Block_init_default   {0, 0, _blox_ActuatorOffset_ReferenceKind_MIN, 0, 0, blox_Constraints_AnalogConstraints_init_default, 0, 0, 0, 0}
#define blox_ActuatorOffset_Block_init_zero      {0, 0, _blox_ActuatorOffset_ReferenceKind_MIN, 0, 0, blox_Constraints_AnalogConstraints_init_zero, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_ActuatorOffset_Block_targetId_tag   1
#define blox_ActuatorOffset_Block_referenceId_tag 3
#define blox_ActuatorOffset_Block_referenceSettingOrValue_tag 4
#define blox_ActuatorOffset_Block_setting_tag    6
#define blox_ActuatorOffset_Block_value_tag      7
#define blox_ActuatorOffset_Block_constrainedBy_tag 8
#define blox_ActuatorOffset_Block_enabled_tag    10
#define blox_ActuatorOffset_Block_desiredSetting_tag 11
#define blox_ActuatorOffset_Block_claimedBy_tag  12
#define blox_ActuatorOffset_Block_drivenTargetId_tag 90

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_ActuatorOffset_Block_fields[11];

/* Maximum encoded size of messages (where known) */
#define blox_ActuatorOffset_Block_size           246

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ACTUATOROFFSET_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
