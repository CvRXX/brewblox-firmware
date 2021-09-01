/* Automatically generated nanopb constant definitions */

#include "MockPins.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_MockPins_fields[2] = {
    PB_FIELD(  2, MESSAGE , REPEATED, STATIC  , FIRST, blox_MockPins, channels, channels, &blox_IoChannel_fields),
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
PB_STATIC_ASSERT((pb_membersize(blox_MockPins, channels[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_MockPins)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_MockPins, channels[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_MockPins)
#endif


/* @@protoc_insertion_point(eof) */
