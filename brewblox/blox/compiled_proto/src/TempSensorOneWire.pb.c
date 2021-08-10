/* Automatically generated nanopb constant definitions */

#include "TempSensorOneWire.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_TempSensorOneWire_fields[6] = {
    PB_FIELD(  1, SINT32  , SINGULAR, STATIC  , FIRST, blox_TempSensorOneWire, value, value, 0),
    PB_FIELD(  3, SINT32  , SINGULAR, STATIC  , OTHER, blox_TempSensorOneWire, offset, value, 0),
    PB_FIELD(  4, FIXED64 , SINGULAR, STATIC  , OTHER, blox_TempSensorOneWire, address, offset, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, blox_TempSensorOneWire, oneWireBusId, address, 0),
    PB_FIELD( 99, UINT32  , REPEATED, STATIC  , OTHER, blox_TempSensorOneWire, strippedFields, oneWireBusId, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
