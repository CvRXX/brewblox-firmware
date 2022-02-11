/* Automatically generated nanopb header */

#ifndef PB_BLOX_TEMPSENSORCOMBI_TEMPSENSORCOMBI_PB_H_INCLUDED
#define PB_BLOX_TEMPSENSORCOMBI_TEMPSENSORCOMBI_PB_H_INCLUDED
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
typedef enum _blox_TempSensorCombi_SensorCombiFunc {
    blox_TempSensorCombi_SensorCombiFunc_SENSOR_COMBI_FUNC_AVG = 0,
    blox_TempSensorCombi_SensorCombiFunc_SENSOR_COMBI_FUNC_MIN = 1,
    blox_TempSensorCombi_SensorCombiFunc_SENSOR_COMBI_FUNC_MAX = 2
} blox_TempSensorCombi_SensorCombiFunc;
#define _blox_TempSensorCombi_SensorCombiFunc_MIN blox_TempSensorCombi_SensorCombiFunc_SENSOR_COMBI_FUNC_AVG
#define _blox_TempSensorCombi_SensorCombiFunc_MAX blox_TempSensorCombi_SensorCombiFunc_SENSOR_COMBI_FUNC_MAX
#define _blox_TempSensorCombi_SensorCombiFunc_ARRAYSIZE ((blox_TempSensorCombi_SensorCombiFunc)(blox_TempSensorCombi_SensorCombiFunc_SENSOR_COMBI_FUNC_MAX+1))

/* Struct definitions */
typedef struct _blox_TempSensorCombi_Block {
    int32_t value;
    blox_TempSensorCombi_SensorCombiFunc combineFunc;
    pb_size_t sensors_count;
    uint16_t sensors[8];
    pb_size_t strippedFields_count;
    uint16_t strippedFields[1];
/* @@protoc_insertion_point(struct:blox_TempSensorCombi_Block) */
} blox_TempSensorCombi_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_TempSensorCombi_Block_init_default  {0, _blox_TempSensorCombi_SensorCombiFunc_MIN, 0, {0, 0, 0, 0, 0, 0, 0, 0}, 0, {0}}
#define blox_TempSensorCombi_Block_init_zero     {0, _blox_TempSensorCombi_SensorCombiFunc_MIN, 0, {0, 0, 0, 0, 0, 0, 0, 0}, 0, {0}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_TempSensorCombi_Block_value_tag     1
#define blox_TempSensorCombi_Block_combineFunc_tag 2
#define blox_TempSensorCombi_Block_sensors_tag   3
#define blox_TempSensorCombi_Block_strippedFields_tag 99

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_TempSensorCombi_Block_fields[5];

/* Maximum encoded size of messages (where known) */
#define blox_TempSensorCombi_Block_size          64

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TEMPSENSORCOMBI_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
