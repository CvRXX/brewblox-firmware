/* Automatically generated nanopb constant definitions */

#include "SetpointProfile.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Point_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Point, time, time, 0),
    PB_ONEOF_FIELD(temperature_oneof,   2, INT32   , ONEOF, STATIC  , OTHER, blox_Point, temperature, time, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_SetpointProfile_fields[6] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, blox_SetpointProfile, points, points, &blox_Point_fields),
    PB_FIELD(  3, BOOL    , SINGULAR, STATIC  , OTHER, blox_SetpointProfile, enabled, points, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointProfile, targetId, enabled, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointProfile, drivenTargetId, targetId, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointProfile, start, drivenTargetId, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
