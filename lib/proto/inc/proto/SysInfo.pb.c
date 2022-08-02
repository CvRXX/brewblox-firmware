/* Automatically generated nanopb constant definitions */

#include "SysInfo.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_SysInfo_Trace_fields[4] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, blox_SysInfo_Trace, action, action, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Trace, id, action, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Trace, type, id, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_SysInfo_Block_fields[10] = {
    PB_FIELD(  1, BYTES   , SINGULAR, STATIC  , FIRST, blox_SysInfo_Block, deviceId, deviceId, 0),
    PB_FIELD(  2, STRING  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, version, deviceId, 0),
    PB_FIELD(  3, UENUM   , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, platform, version, 0),
    PB_FIELD(  7, STRING  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, protocolVersion, platform, 0),
    PB_FIELD(  8, STRING  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, releaseDate, protocolVersion, 0),
    PB_FIELD(  9, STRING  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, protocolDate, releaseDate, 0),
    PB_FIELD( 10, UINT32  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, ip, protocolDate, 0),
    PB_FIELD(100, UENUM   , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, command, ip, 0),
    PB_FIELD(101, MESSAGE , REPEATED, STATIC  , OTHER, blox_SysInfo_Block, trace, command, &blox_SysInfo_Trace_fields),
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
PB_STATIC_ASSERT((pb_membersize(blox_SysInfo_Block, trace[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_SysInfo_Trace_blox_SysInfo_Block)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_SysInfo_Block, trace[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_SysInfo_Trace_blox_SysInfo_Block)
#endif


/* @@protoc_insertion_point(eof) */
