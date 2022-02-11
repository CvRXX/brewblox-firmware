/* Automatically generated nanopb header */

#ifndef PB_BLOX_SETPOINTSENSORPAIR_SETPOINTSENSORPAIR_PB_H_INCLUDED
#define PB_BLOX_SETPOINTSENSORPAIR_SETPOINTSENSORPAIR_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _blox_SetpointSensorPair_FilterChoice {
    blox_SetpointSensorPair_FilterChoice_FILTER_NONE = 0,
    blox_SetpointSensorPair_FilterChoice_FILTER_15s = 1,
    blox_SetpointSensorPair_FilterChoice_FILTER_45s = 2,
    blox_SetpointSensorPair_FilterChoice_FILTER_90s = 3,
    blox_SetpointSensorPair_FilterChoice_FILTER_3m = 4,
    blox_SetpointSensorPair_FilterChoice_FILTER_10m = 5,
    blox_SetpointSensorPair_FilterChoice_FILTER_30m = 6
} blox_SetpointSensorPair_FilterChoice;
#define _blox_SetpointSensorPair_FilterChoice_MIN blox_SetpointSensorPair_FilterChoice_FILTER_NONE
#define _blox_SetpointSensorPair_FilterChoice_MAX blox_SetpointSensorPair_FilterChoice_FILTER_30m
#define _blox_SetpointSensorPair_FilterChoice_ARRAYSIZE ((blox_SetpointSensorPair_FilterChoice)(blox_SetpointSensorPair_FilterChoice_FILTER_30m+1))

/* Struct definitions */
typedef struct _blox_SetpointSensorPair_Block {
    uint16_t sensorId;
    int32_t setting;
    int32_t value;
    bool settingEnabled;
    int32_t storedSetting;
    blox_SetpointSensorPair_FilterChoice filter;
    int32_t filterThreshold;
    int32_t valueUnfiltered;
    bool resetFilter;
    pb_size_t strippedFields_count;
    uint16_t strippedFields[3];
/* @@protoc_insertion_point(struct:blox_SetpointSensorPair_Block) */
} blox_SetpointSensorPair_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_SetpointSensorPair_Block_init_default {0, 0, 0, 0, 0, _blox_SetpointSensorPair_FilterChoice_MIN, 0, 0, 0, 0, {0, 0, 0}}
#define blox_SetpointSensorPair_Block_init_zero  {0, 0, 0, 0, 0, _blox_SetpointSensorPair_FilterChoice_MIN, 0, 0, 0, 0, {0, 0, 0}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_SetpointSensorPair_Block_sensorId_tag 2
#define blox_SetpointSensorPair_Block_setting_tag 5
#define blox_SetpointSensorPair_Block_value_tag  6
#define blox_SetpointSensorPair_Block_settingEnabled_tag 7
#define blox_SetpointSensorPair_Block_storedSetting_tag 8
#define blox_SetpointSensorPair_Block_filter_tag 9
#define blox_SetpointSensorPair_Block_filterThreshold_tag 10
#define blox_SetpointSensorPair_Block_valueUnfiltered_tag 11
#define blox_SetpointSensorPair_Block_resetFilter_tag 12
#define blox_SetpointSensorPair_Block_strippedFields_tag 99

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_SetpointSensorPair_Block_fields[11];

/* Maximum encoded size of messages (where known) */
#define blox_SetpointSensorPair_Block_size       63

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SETPOINTSENSORPAIR_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
