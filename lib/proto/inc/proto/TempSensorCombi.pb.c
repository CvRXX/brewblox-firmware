/* Automatically generated nanopb constant definitions */

#include "TempSensorCombi.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_TempSensorCombi_Block_fields[4] = {
    PB_FIELD(  1, SINT32  , SINGULAR, STATIC  , FIRST, blox_TempSensorCombi_Block, value, value, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, blox_TempSensorCombi_Block, combineFunc, value, 0),
    PB_FIELD(  3, UINT32  , REPEATED, STATIC  , OTHER, blox_TempSensorCombi_Block, sensors, combineFunc, 0),
    PB_LAST_FIELD
};



/* @@protoc_insertion_point(eof) */
