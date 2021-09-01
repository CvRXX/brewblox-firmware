/* Automatically generated nanopb constant definitions */

#include "DS2408.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_DS2408_fields[6] = {
    PB_FIELD(  1, FIXED64 , SINGULAR, STATIC  , FIRST, blox_DS2408, address, address, 0),
    PB_FIELD(  6, BOOL    , SINGULAR, STATIC  , OTHER, blox_DS2408, connected, address, 0),
    PB_FIELD(  9, UENUM   , SINGULAR, STATIC  , OTHER, blox_DS2408, connectMode, connected, 0),
    PB_FIELD( 10, UINT32  , SINGULAR, STATIC  , OTHER, blox_DS2408, oneWireBusId, connectMode, 0),
    PB_FIELD( 11, MESSAGE , REPEATED, STATIC  , OTHER, blox_DS2408, channels, oneWireBusId, &blox_IoChannel_fields),
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
PB_STATIC_ASSERT((pb_membersize(blox_DS2408, channels[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_DS2408)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_DS2408, channels[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_DS2408)
#endif


/* @@protoc_insertion_point(eof) */
