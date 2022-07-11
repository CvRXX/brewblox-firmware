/* Automatically generated nanopb header */

#ifndef PB_BLOX_TEMPSENSOREXTERNAL_TEMPSENSOREXTERNAL_PB_H_INCLUDED
#define PB_BLOX_TEMPSENSOREXTERNAL_TEMPSENSOREXTERNAL_PB_H_INCLUDED
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
typedef struct _blox_TempSensorExternal_Block {
    bool enabled;
    uint32_t timeout;
    int32_t setting;
    uint32_t lastUpdated;
    int32_t value;
/* @@protoc_insertion_point(struct:blox_TempSensorExternal_Block) */
} blox_TempSensorExternal_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_TempSensorExternal_Block_init_default {0, 0, 0, 0, 0}
#define blox_TempSensorExternal_Block_init_zero  {0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_TempSensorExternal_Block_enabled_tag 1
#define blox_TempSensorExternal_Block_timeout_tag 2
#define blox_TempSensorExternal_Block_setting_tag 3
#define blox_TempSensorExternal_Block_lastUpdated_tag 4
#define blox_TempSensorExternal_Block_value_tag  5

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_TempSensorExternal_Block_fields[6];

/* Maximum encoded size of messages (where known) */
#define blox_TempSensorExternal_Block_size       26

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TEMPSENSOREXTERNAL_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
