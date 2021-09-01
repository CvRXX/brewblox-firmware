/* Automatically generated nanopb constant definitions */

#include "Spark3Pins.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Spark3Pins_fields[7] = {
    PB_FIELD(  2, BOOL    , SINGULAR, STATIC  , FIRST, blox_Spark3Pins, enableIoSupply5V, enableIoSupply5V, 0),
    PB_FIELD(  3, BOOL    , SINGULAR, STATIC  , OTHER, blox_Spark3Pins, enableIoSupply12V, enableIoSupply5V, 0),
    PB_FIELD(  5, BOOL    , SINGULAR, STATIC  , OTHER, blox_Spark3Pins, soundAlarm, enableIoSupply12V, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_Spark3Pins, voltage5, soundAlarm, 0),
    PB_FIELD(  7, UINT32  , SINGULAR, STATIC  , OTHER, blox_Spark3Pins, voltage12, voltage5, 0),
    PB_FIELD(  8, MESSAGE , REPEATED, STATIC  , OTHER, blox_Spark3Pins, channels, voltage12, &blox_IoChannel_fields),
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
PB_STATIC_ASSERT((pb_membersize(blox_Spark3Pins, channels[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_Spark3Pins)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_Spark3Pins, channels[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_Spark3Pins)
#endif


/* @@protoc_insertion_point(eof) */
