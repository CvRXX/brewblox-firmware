/* Automatically generated nanopb constant definitions */

#include "SetpointSensorPair.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_SetpointSensorPair_Block_fields[11] = {
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , FIRST, blox_SetpointSensorPair_Block, sensorId, sensorId, 0),
    PB_FIELD(  5, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair_Block, setting, sensorId, 0),
    PB_FIELD(  6, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair_Block, value, setting, 0),
    PB_FIELD(  7, BOOL    , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair_Block, settingEnabled, value, 0),
    PB_FIELD(  8, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair_Block, storedSetting, settingEnabled, 0),
    PB_FIELD(  9, UENUM   , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair_Block, filter, storedSetting, 0),
    PB_FIELD( 10, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair_Block, filterThreshold, filter, 0),
    PB_FIELD( 11, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair_Block, valueUnfiltered, filterThreshold, 0),
    PB_FIELD( 12, BOOL    , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair_Block, resetFilter, valueUnfiltered, 0),
    PB_FIELD( 99, UINT32  , REPEATED, STATIC  , OTHER, blox_SetpointSensorPair_Block, strippedFields, resetFilter, 0),
    PB_LAST_FIELD
};



/* @@protoc_insertion_point(eof) */
