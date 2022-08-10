/* Automatically generated nanopb constant definitions */

#include "SetpointProfile.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_SetpointProfile_Point_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_SetpointProfile_Point, time, time, 0),
    PB_ONEOF_FIELD(temperature_oneof,   2, INT32   , ONEOF, STATIC  , OTHER, blox_SetpointProfile_Point, temperature, time, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_SetpointProfile_Block_fields[6] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, blox_SetpointProfile_Block, points, points, &blox_SetpointProfile_Point_fields),
    PB_FIELD(  3, BOOL    , SINGULAR, STATIC  , OTHER, blox_SetpointProfile_Block, enabled, points, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointProfile_Block, targetId, enabled, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_SetpointProfile_Block, start, targetId, 0),
    PB_FIELD( 90, BOOL    , SINGULAR, STATIC  , OTHER, blox_SetpointProfile_Block, drivenTargetId, start, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
