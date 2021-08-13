/* Automatically generated nanopb constant definitions */

#include "Spark3Pins.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Spark3IoPin_fields[6] = {
    PB_ONEOF_FIELD(Pin,   1, MESSAGE , ONEOF, STATIC  , FIRST, blox_Spark3IoPin, top1, top1, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   2, MESSAGE , ONEOF, STATIC  , UNION, blox_Spark3IoPin, top2, top2, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   3, MESSAGE , ONEOF, STATIC  , UNION, blox_Spark3IoPin, top3, top3, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   4, MESSAGE , ONEOF, STATIC  , UNION, blox_Spark3IoPin, bottom1, bottom1, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   5, MESSAGE , ONEOF, STATIC  , UNION, blox_Spark3IoPin, bottom2, bottom2, &blox_IoChannel_fields),
    PB_LAST_FIELD
};

const pb_field_t blox_Spark3Pins_fields[7] = {
    PB_FIELD(  1, MESSAGE , REPEATED, STATIC  , FIRST, blox_Spark3Pins, pins, pins, &blox_Spark3IoPin_fields),
    PB_FIELD(  2, BOOL    , SINGULAR, STATIC  , OTHER, blox_Spark3Pins, enableIoSupply5V, pins, 0),
    PB_FIELD(  3, BOOL    , SINGULAR, STATIC  , OTHER, blox_Spark3Pins, enableIoSupply12V, enableIoSupply5V, 0),
    PB_FIELD(  5, BOOL    , SINGULAR, STATIC  , OTHER, blox_Spark3Pins, soundAlarm, enableIoSupply12V, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_Spark3Pins, voltage5, soundAlarm, 0),
    PB_FIELD(  7, UINT32  , SINGULAR, STATIC  , OTHER, blox_Spark3Pins, voltage12, voltage5, 0),
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
PB_STATIC_ASSERT((pb_membersize(blox_Spark3IoPin, Pin.top1) < 65536 && pb_membersize(blox_Spark3IoPin, Pin.top2) < 65536 && pb_membersize(blox_Spark3IoPin, Pin.top3) < 65536 && pb_membersize(blox_Spark3IoPin, Pin.bottom1) < 65536 && pb_membersize(blox_Spark3IoPin, Pin.bottom2) < 65536 && pb_membersize(blox_Spark3Pins, pins[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_Spark3IoPin_blox_Spark3Pins)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_Spark3IoPin, Pin.top1) < 256 && pb_membersize(blox_Spark3IoPin, Pin.top2) < 256 && pb_membersize(blox_Spark3IoPin, Pin.top3) < 256 && pb_membersize(blox_Spark3IoPin, Pin.bottom1) < 256 && pb_membersize(blox_Spark3IoPin, Pin.bottom2) < 256 && pb_membersize(blox_Spark3Pins, pins[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_Spark3IoPin_blox_Spark3Pins)
#endif


/* @@protoc_insertion_point(eof) */
