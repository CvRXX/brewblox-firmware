/* Automatically generated nanopb constant definitions */

#include "OneWireBus.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_OneWireBusCommand_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_OneWireBusCommand, opcode, opcode, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireBusCommand, data, opcode, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_OneWireBus_fields[3] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, blox_OneWireBus, command, command, &blox_OneWireBusCommand_fields),
    PB_FIELD(  2, FIXED64 , REPEATED, CALLBACK, OTHER, blox_OneWireBus, address, command, 0),
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
PB_STATIC_ASSERT((pb_membersize(blox_OneWireBus, command) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_OneWireBusCommand_blox_OneWireBus)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_OneWireBus, command) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_OneWireBusCommand_blox_OneWireBus)
#endif


/* @@protoc_insertion_point(eof) */
