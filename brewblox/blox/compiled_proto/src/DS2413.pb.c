/* Automatically generated nanopb constant definitions */

#include "DS2413.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_DS2413IoPin_fields[3] = {
    PB_ONEOF_FIELD(Pin,   1, MESSAGE , ONEOF, STATIC  , FIRST, blox_DS2413IoPin, A, A, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   2, MESSAGE , ONEOF, STATIC  , UNION, blox_DS2413IoPin, B, B, &blox_IoChannel_fields),
    PB_LAST_FIELD
};

const pb_field_t blox_DS2413_fields[5] = {
    PB_FIELD(  1, FIXED64 , SINGULAR, STATIC  , FIRST, blox_DS2413, address, address, 0),
    PB_FIELD(  6, BOOL    , SINGULAR, STATIC  , OTHER, blox_DS2413, connected, address, 0),
    PB_FIELD(  7, MESSAGE , REPEATED, STATIC  , OTHER, blox_DS2413, pins, connected, &blox_DS2413IoPin_fields),
    PB_FIELD(  8, UINT32  , SINGULAR, STATIC  , OTHER, blox_DS2413, oneWireBusId, pins, 0),
    PB_LAST_FIELD
};


/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_DS2413IoPin, Pin.A) < 65536 && pb_membersize(blox_DS2413IoPin, Pin.B) < 65536 && pb_membersize(blox_DS2413, pins[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_DS2413IoPin_blox_DS2413)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_DS2413IoPin, Pin.A) < 256 && pb_membersize(blox_DS2413IoPin, Pin.B) < 256 && pb_membersize(blox_DS2413, pins[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_DS2413IoPin_blox_DS2413)
#endif


/* @@protoc_insertion_point(eof) */
