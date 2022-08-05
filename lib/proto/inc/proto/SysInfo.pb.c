/* Automatically generated nanopb constant definitions */

#include "SysInfo.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_SysInfo_Block_fields[14] = {
    PB_FIELD(  1, BYTES   , SINGULAR, STATIC  , FIRST, blox_SysInfo_Block, deviceId, deviceId, 0),
    PB_FIELD(  2, STRING  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, version, deviceId, 0),
    PB_FIELD(  3, UENUM   , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, platform, version, 0),
    PB_FIELD(  7, STRING  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, protocolVersion, platform, 0),
    PB_FIELD(  8, STRING  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, releaseDate, protocolVersion, 0),
    PB_FIELD(  9, STRING  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, protocolDate, releaseDate, 0),
    PB_FIELD( 10, UINT32  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, ip, protocolDate, 0),
    PB_FIELD( 11, UINT32  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, uptime, ip, 0),
    PB_FIELD( 12, UINT32  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, updatesPerSecond, uptime, 0),
    PB_FIELD( 13, UINT32  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, systemTime, updatesPerSecond, 0),
    PB_FIELD( 14, STRING  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, timeZone, systemTime, 0),
    PB_FIELD( 15, UENUM   , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, tempUnit, timeZone, 0),
    PB_FIELD( 16, UINT32  , SINGULAR, STATIC  , OTHER, blox_SysInfo_Block, displayBrightness, tempUnit, 0),
    PB_LAST_FIELD
};




/* @@protoc_insertion_point(eof) */
