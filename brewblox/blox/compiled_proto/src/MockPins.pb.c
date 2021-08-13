/* Automatically generated nanopb constant definitions */

#include "MockPins.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_MockPinsIoPin_fields[9] = {
    PB_ONEOF_FIELD(Pin,   1, MESSAGE , ONEOF, STATIC  , FIRST, blox_MockPinsIoPin, mock1, mock1, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   2, MESSAGE , ONEOF, STATIC  , UNION, blox_MockPinsIoPin, mock2, mock2, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   3, MESSAGE , ONEOF, STATIC  , UNION, blox_MockPinsIoPin, mock3, mock3, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   4, MESSAGE , ONEOF, STATIC  , UNION, blox_MockPinsIoPin, mock4, mock4, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   5, MESSAGE , ONEOF, STATIC  , UNION, blox_MockPinsIoPin, mock5, mock5, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   6, MESSAGE , ONEOF, STATIC  , UNION, blox_MockPinsIoPin, mock6, mock6, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   7, MESSAGE , ONEOF, STATIC  , UNION, blox_MockPinsIoPin, mock7, mock7, &blox_IoChannel_fields),
    PB_ONEOF_FIELD(Pin,   8, MESSAGE , ONEOF, STATIC  , UNION, blox_MockPinsIoPin, mock8, mock8, &blox_IoChannel_fields),
    PB_LAST_FIELD
};

const pb_field_t blox_MockPins_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, STATIC  , FIRST, blox_MockPins, pins, pins, &blox_MockPinsIoPin_fields),
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
PB_STATIC_ASSERT((pb_membersize(blox_MockPinsIoPin, Pin.mock1) < 65536 && pb_membersize(blox_MockPinsIoPin, Pin.mock2) < 65536 && pb_membersize(blox_MockPinsIoPin, Pin.mock3) < 65536 && pb_membersize(blox_MockPinsIoPin, Pin.mock4) < 65536 && pb_membersize(blox_MockPinsIoPin, Pin.mock5) < 65536 && pb_membersize(blox_MockPinsIoPin, Pin.mock6) < 65536 && pb_membersize(blox_MockPinsIoPin, Pin.mock7) < 65536 && pb_membersize(blox_MockPinsIoPin, Pin.mock8) < 65536 && pb_membersize(blox_MockPins, pins[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_MockPinsIoPin_blox_MockPins)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_MockPinsIoPin, Pin.mock1) < 256 && pb_membersize(blox_MockPinsIoPin, Pin.mock2) < 256 && pb_membersize(blox_MockPinsIoPin, Pin.mock3) < 256 && pb_membersize(blox_MockPinsIoPin, Pin.mock4) < 256 && pb_membersize(blox_MockPinsIoPin, Pin.mock5) < 256 && pb_membersize(blox_MockPinsIoPin, Pin.mock6) < 256 && pb_membersize(blox_MockPinsIoPin, Pin.mock7) < 256 && pb_membersize(blox_MockPinsIoPin, Pin.mock8) < 256 && pb_membersize(blox_MockPins, pins[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_MockPinsIoPin_blox_MockPins)
#endif


/* @@protoc_insertion_point(eof) */
