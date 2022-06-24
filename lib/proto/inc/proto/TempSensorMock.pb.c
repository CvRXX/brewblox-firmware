/* Automatically generated nanopb constant definitions */

#include "TempSensorMock.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_TempSensorMock_Fluctuation_fields[3] = {
    PB_FIELD(  1, SINT32  , SINGULAR, STATIC  , FIRST, blox_TempSensorMock_Fluctuation, amplitude, amplitude, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_TempSensorMock_Fluctuation, period, amplitude, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_TempSensorMock_Block_fields[5] = {
    PB_FIELD(  1, SINT32  , SINGULAR, STATIC  , FIRST, blox_TempSensorMock_Block, value, value, 0),
    PB_FIELD(  3, BOOL    , SINGULAR, STATIC  , OTHER, blox_TempSensorMock_Block, connected, value, 0),
    PB_FIELD(  4, SINT32  , SINGULAR, STATIC  , OTHER, blox_TempSensorMock_Block, setting, connected, 0),
    PB_FIELD(  5, MESSAGE , REPEATED, CALLBACK, OTHER, blox_TempSensorMock_Block, fluctuations, setting, &blox_TempSensorMock_Fluctuation_fields),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
