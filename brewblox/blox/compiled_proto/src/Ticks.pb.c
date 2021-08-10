/* Automatically generated nanopb constant definitions */

#include "Ticks.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Ticks_fields[7] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Ticks, millisSinceBoot, millisSinceBoot, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_Ticks, secondsSinceEpoch, millisSinceBoot, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_Ticks, avgCommunicationTask, secondsSinceEpoch, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_Ticks, avgBlocksUpdateTask, avgCommunicationTask, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, blox_Ticks, avgDisplayTask, avgBlocksUpdateTask, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_Ticks, avgSystemTask, avgDisplayTask, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
