/* Automatically generated nanopb constant definitions */

#include "DS2413.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_DS2413_Block_fields[5] = {
    PB_FIELD(  1, FIXED64 , SINGULAR, STATIC  , FIRST, blox_DS2413_Block, address, address, 0),
    PB_FIELD(  6, BOOL    , SINGULAR, STATIC  , OTHER, blox_DS2413_Block, connected, address, 0),
    PB_FIELD(  8, UINT32  , SINGULAR, STATIC  , OTHER, blox_DS2413_Block, oneWireBusId, connected, 0),
    PB_FIELD(  9, MESSAGE , REPEATED, STATIC  , OTHER, blox_DS2413_Block, channels, oneWireBusId, &blox_IoArray_IoChannel_fields),
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
PB_STATIC_ASSERT((pb_membersize(blox_DS2413_Block, channels[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_DS2413_Block)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_DS2413_Block, channels[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_DS2413_Block)
#endif


/* @@protoc_insertion_point(eof) */
