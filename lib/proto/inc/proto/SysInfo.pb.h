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

typedef enum _blox_SysInfo_Command {
    blox_SysInfo_Command_SYS_CMD_NONE = 0,
    blox_SysInfo_Command_SYS_CMD_TRACE_READ = 1,
    blox_SysInfo_Command_SYS_CMD_TRACE_RESUME = 2,
    blox_SysInfo_Command_SYS_CMD_TRACE_READ_RESUME = 3
} blox_SysInfo_Command;
#define _blox_SysInfo_Command_MIN blox_SysInfo_Command_SYS_CMD_NONE
#define _blox_SysInfo_Command_MAX blox_SysInfo_Command_SYS_CMD_TRACE_READ_RESUME
#define _blox_SysInfo_Command_ARRAYSIZE ((blox_SysInfo_Command)(blox_SysInfo_Command_SYS_CMD_TRACE_READ_RESUME+1))

typedef enum _blox_SysInfo_Trace_Action {
    blox_SysInfo_Trace_Action_NONE = 0,
    blox_SysInfo_Trace_Action_READ_OBJECT = 1,
    blox_SysInfo_Trace_Action_WRITE_OBJECT = 2,
    blox_SysInfo_Trace_Action_CREATE_OBJECT = 3,
    blox_SysInfo_Trace_Action_DELETE_OBJECT = 4,
    blox_SysInfo_Trace_Action_LIST_ACTIVE_OBJECTS = 5,
    blox_SysInfo_Trace_Action_READ_STORED_OBJECT = 6,
    blox_SysInfo_Trace_Action_LIST_STORED_OBJECTS = 7,
    blox_SysInfo_Trace_Action_CLEAR_OBJECTS = 8,
    blox_SysInfo_Trace_Action_REBOOT = 9,
    blox_SysInfo_Trace_Action_FACTORY_RESET = 10,
    blox_SysInfo_Trace_Action_LIST_COMPATIBLE_OBJECTS = 11,
    blox_SysInfo_Trace_Action_DISCOVER_NEW_OBJECTS = 12,
    blox_SysInfo_Trace_Action_CONSTRUCT_OBJECT = 20,
    blox_SysInfo_Trace_Action_DESTRUCT_OBJECT = 21,
    blox_SysInfo_Trace_Action_STREAM_FROM_OBJECT = 22,
    blox_SysInfo_Trace_Action_STREAM_TO_OBJECT = 23,
    blox_SysInfo_Trace_Action_UPDATE_OBJECT = 24,
    blox_SysInfo_Trace_Action_PERSIST_OBJECT = 25,
    blox_SysInfo_Trace_Action_LOAD_STORED_OBJECT = 26,
    blox_SysInfo_Trace_Action_UPDATE_OBJECTS = 27,
    blox_SysInfo_Trace_Action_UPDATE_CONNECTIONS = 28,
    blox_SysInfo_Trace_Action_UPDATE_DISPLAY = 101,
    blox_SysInfo_Trace_Action_SYSTEM_TASKS = 102,
    blox_SysInfo_Trace_Action_MANAGE_CONNECTIVITY = 103,
    blox_SysInfo_Trace_Action_MDNS_START = 104,
    blox_SysInfo_Trace_Action_MDNS_PROCESS = 105,
    blox_SysInfo_Trace_Action_HTTP_START = 106,
    blox_SysInfo_Trace_Action_HTTP_STOP = 107,
    blox_SysInfo_Trace_Action_HTTP_RESPONSE = 108,
    blox_SysInfo_Trace_Action_WIFI_CONNECT = 109,
    blox_SysInfo_Trace_Action_FIRMWARE_UPDATE_STARTED = 110
} blox_SysInfo_Trace_Action;
#define _blox_SysInfo_Trace_Action_MIN blox_SysInfo_Trace_Action_NONE
#define _blox_SysInfo_Trace_Action_MAX blox_SysInfo_Trace_Action_FIRMWARE_UPDATE_STARTED
#define _blox_SysInfo_Trace_Action_ARRAYSIZE ((blox_SysInfo_Trace_Action)(blox_SysInfo_Trace_Action_FIRMWARE_UPDATE_STARTED+1))

/* Struct definitions */
typedef struct _blox_SysInfo_Trace {
    blox_SysInfo_Trace_Action action;
    uint16_t id;
    uint16_t type;
/* @@protoc_insertion_point(struct:blox_SysInfo_Trace) */
} blox_SysInfo_Trace;

typedef PB_BYTES_ARRAY_T(12) blox_SysInfo_Block_deviceId_t;
typedef struct _blox_SysInfo_Block {
    blox_SysInfo_Block_deviceId_t deviceId;
    char version[12];
    blox_SysInfo_Platform platform;
    char protocolVersion[12];
    char releaseDate[12];
    char protocolDate[12];
    uint32_t ip;
    blox_SysInfo_Command command;
    pb_size_t trace_count;
    blox_SysInfo_Trace trace[10];
/* @@protoc_insertion_point(struct:blox_SysInfo_Block) */
} blox_SysInfo_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_SysInfo_Trace_init_default          {_blox_SysInfo_Trace_Action_MIN, 0, 0}
#define blox_SysInfo_Block_init_default          {{0, {0}}, "", _blox_SysInfo_Platform_MIN, "", "", "", 0, _blox_SysInfo_Command_MIN, 0, {blox_SysInfo_Trace_init_default, blox_SysInfo_Trace_init_default, blox_SysInfo_Trace_init_default, blox_SysInfo_Trace_init_default, blox_SysInfo_Trace_init_default, blox_SysInfo_Trace_init_default, blox_SysInfo_Trace_init_default, blox_SysInfo_Trace_init_default, blox_SysInfo_Trace_init_default, blox_SysInfo_Trace_init_default}}
#define blox_SysInfo_Trace_init_zero             {_blox_SysInfo_Trace_Action_MIN, 0, 0}
#define blox_SysInfo_Block_init_zero             {{0, {0}}, "", _blox_SysInfo_Platform_MIN, "", "", "", 0, _blox_SysInfo_Command_MIN, 0, {blox_SysInfo_Trace_init_zero, blox_SysInfo_Trace_init_zero, blox_SysInfo_Trace_init_zero, blox_SysInfo_Trace_init_zero, blox_SysInfo_Trace_init_zero, blox_SysInfo_Trace_init_zero, blox_SysInfo_Trace_init_zero, blox_SysInfo_Trace_init_zero, blox_SysInfo_Trace_init_zero, blox_SysInfo_Trace_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_SysInfo_Trace_action_tag            1
#define blox_SysInfo_Trace_id_tag                2
#define blox_SysInfo_Trace_type_tag              3
#define blox_SysInfo_Block_deviceId_tag          1
#define blox_SysInfo_Block_version_tag           2
#define blox_SysInfo_Block_platform_tag          3
#define blox_SysInfo_Block_protocolVersion_tag   7
#define blox_SysInfo_Block_releaseDate_tag       8
#define blox_SysInfo_Block_protocolDate_tag      9
#define blox_SysInfo_Block_ip_tag                10
#define blox_SysInfo_Block_command_tag           100
#define blox_SysInfo_Block_trace_tag             101

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_SysInfo_Trace_fields[4];
extern const pb_field_t blox_SysInfo_Block_fields[10];

/* Maximum encoded size of messages (where known) */
#define blox_SysInfo_Trace_size                  14
#define blox_SysInfo_Block_size                  251

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SYSINFO_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
