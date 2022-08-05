/* Automatically generated nanopb header */

#ifndef PB_BLOX_SYSINFO_SYSINFO_PB_H_INCLUDED
#define PB_BLOX_SYSINFO_SYSINFO_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _blox_SysInfo_Platform {
    blox_SysInfo_Platform_PLATFORM_UNKNOWN = 0,
    blox_SysInfo_Platform_PLATFORM_GCC = 3,
    blox_SysInfo_Platform_PLATFORM_PHOTON = 6,
    blox_SysInfo_Platform_PLATFORM_P1 = 8
} blox_SysInfo_Platform;
#define _blox_SysInfo_Platform_MIN blox_SysInfo_Platform_PLATFORM_UNKNOWN
#define _blox_SysInfo_Platform_MAX blox_SysInfo_Platform_PLATFORM_P1
#define _blox_SysInfo_Platform_ARRAYSIZE ((blox_SysInfo_Platform)(blox_SysInfo_Platform_PLATFORM_P1+1))

typedef enum _blox_SysInfo_TemperatureUnit {
    blox_SysInfo_TemperatureUnit_TEMP_CELSIUS = 0,
    blox_SysInfo_TemperatureUnit_TEMP_FAHRENHEIT = 1
} blox_SysInfo_TemperatureUnit;
#define _blox_SysInfo_TemperatureUnit_MIN blox_SysInfo_TemperatureUnit_TEMP_CELSIUS
#define _blox_SysInfo_TemperatureUnit_MAX blox_SysInfo_TemperatureUnit_TEMP_FAHRENHEIT
#define _blox_SysInfo_TemperatureUnit_ARRAYSIZE ((blox_SysInfo_TemperatureUnit)(blox_SysInfo_TemperatureUnit_TEMP_FAHRENHEIT+1))

/* Struct definitions */
typedef PB_BYTES_ARRAY_T(12) blox_SysInfo_Block_deviceId_t;
typedef struct _blox_SysInfo_Block {
    blox_SysInfo_Block_deviceId_t deviceId;
    char version[12];
    blox_SysInfo_Platform platform;
    char protocolVersion[12];
    char releaseDate[12];
    char protocolDate[12];
    uint32_t ip;
    uint32_t uptime;
    uint32_t systemTime;
    char timeZone[32];
    blox_SysInfo_TemperatureUnit tempUnit;
    uint8_t displayBrightness;
/* @@protoc_insertion_point(struct:blox_SysInfo_Block) */
} blox_SysInfo_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_SysInfo_Block_init_default          {{0, {0}}, "", _blox_SysInfo_Platform_MIN, "", "", "", 0, 0, 0, "", _blox_SysInfo_TemperatureUnit_MIN, 0}
#define blox_SysInfo_Block_init_zero             {{0, {0}}, "", _blox_SysInfo_Platform_MIN, "", "", "", 0, 0, 0, "", _blox_SysInfo_TemperatureUnit_MIN, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_SysInfo_Block_deviceId_tag          1
#define blox_SysInfo_Block_version_tag           2
#define blox_SysInfo_Block_platform_tag          3
#define blox_SysInfo_Block_protocolVersion_tag   7
#define blox_SysInfo_Block_releaseDate_tag       8
#define blox_SysInfo_Block_protocolDate_tag      9
#define blox_SysInfo_Block_ip_tag                10
#define blox_SysInfo_Block_uptime_tag            11
#define blox_SysInfo_Block_systemTime_tag        12
#define blox_SysInfo_Block_timeZone_tag          13
#define blox_SysInfo_Block_tempUnit_tag          14
#define blox_SysInfo_Block_displayBrightness_tag 15

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_SysInfo_Block_fields[13];

/* Maximum encoded size of messages (where known) */
#define blox_SysInfo_Block_size                  132

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SYSINFO_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
