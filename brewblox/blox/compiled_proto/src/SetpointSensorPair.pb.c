/* Automatically generated nanopb constant definitions */

#include "SetpointSensorPair.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_SetpointSensorPair_fields[11] = {
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , FIRST, blox_SetpointSensorPair, sensorId, sensorId, 0),
    PB_FIELD(  5, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair, setting, sensorId, 0),
    PB_FIELD(  6, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair, value, setting, 0),
    PB_FIELD(  7, BOOL    , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair, settingEnabled, value, 0),
    PB_FIELD(  8, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair, storedSetting, settingEnabled, 0),
    PB_FIELD(  9, UENUM   , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair, filter, storedSetting, 0),
    PB_FIELD( 10, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair, filterThreshold, filter, 0),
    PB_FIELD( 11, SINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair, valueUnfiltered, filterThreshold, 0),
    PB_FIELD( 12, BOOL    , SINGULAR, STATIC  , OTHER, blox_SetpointSensorPair, resetFilter, valueUnfiltered, 0),
    PB_FIELD( 99, UINT32  , REPEATED, STATIC  , OTHER, blox_SetpointSensorPair, strippedFields, resetFilter, 0),
    PB_LAST_FIELD
};



/* @@protoc_insertion_point(eof) */
