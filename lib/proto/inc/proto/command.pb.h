/* Automatically generated nanopb header */

#ifndef PB_COMMAND_COMMAND_PB_H_INCLUDED
#define PB_COMMAND_COMMAND_PB_H_INCLUDED
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
typedef enum _command_Opcode {
    command_Opcode_NONE = 0,
    command_Opcode_VERSION = 1,
    command_Opcode_BLOCK_READ = 10,
    command_Opcode_BLOCK_READ_ALL = 11,
    command_Opcode_BLOCK_WRITE = 12,
    command_Opcode_BLOCK_CREATE = 13,
    command_Opcode_BLOCK_DELETE = 14,
    command_Opcode_BLOCK_DISCOVER = 15,
    command_Opcode_STORAGE_READ = 20,
    command_Opcode_STORAGE_READ_ALL = 21,
    command_Opcode_REBOOT = 30,
    command_Opcode_CLEAR_BLOCKS = 31,
    command_Opcode_CLEAR_WIFI = 32,
    command_Opcode_FACTORY_RESET = 33,
    command_Opcode_FIRMWARE_UPDATE = 40
} command_Opcode;
#define _command_Opcode_MIN command_Opcode_NONE
#define _command_Opcode_MAX command_Opcode_FIRMWARE_UPDATE
#define _command_Opcode_ARRAYSIZE ((command_Opcode)(command_Opcode_FIRMWARE_UPDATE+1))

typedef enum _command_ErrorCode {
    command_ErrorCode_OK = 0,
    command_ErrorCode_UNKNOWN_ERROR = 1,
    command_ErrorCode_INVALID_OPCODE = 2,
    command_ErrorCode_INSUFFICIENT_HEAP = 4,
    command_ErrorCode_INSUFFICIENT_STORAGE = 5,
    command_ErrorCode_NETWORK_ERROR = 10,
    command_ErrorCode_NETWORK_READ_ERROR = 11,
    command_ErrorCode_NETWORK_DECODING_ERROR = 12,
    command_ErrorCode_NETWORK_WRITE_ERROR = 13,
    command_ErrorCode_NETWORK_ENCODING_ERROR = 14,
    command_ErrorCode_STORAGE_ERROR = 20,
    command_ErrorCode_STORAGE_READ_ERROR = 21,
    command_ErrorCode_STORAGE_DECODING_ERROR = 22,
    command_ErrorCode_STORAGE_CRC_ERROR = 23,
    command_ErrorCode_STORAGE_WRITE_ERROR = 24,
    command_ErrorCode_STORAGE_ENCODING_ERROR = 25,
    command_ErrorCode_BLOCK_NOT_WRITABLE = 30,
    command_ErrorCode_BLOCK_NOT_READABLE = 31,
    command_ErrorCode_BLOCK_NOT_CREATABLE = 32,
    command_ErrorCode_BLOCK_NOT_DELETABLE = 33,
    command_ErrorCode_INVALID_BLOCK = 40,
    command_ErrorCode_INVALID_BLOCK_ID = 41,
    command_ErrorCode_INVALID_BLOCK_TYPE = 42,
    command_ErrorCode_INVALID_BLOCK_SUBTYPE = 43,
    command_ErrorCode_INVALID_BLOCK_CONTENT = 44,
    command_ErrorCode_INVALID_STORED_BLOCK = 50,
    command_ErrorCode_INVALID_STORED_BLOCK_ID = 51,
    command_ErrorCode_INVALID_STORED_BLOCK_TYPE = 52,
    command_ErrorCode_INVALID_STORED_BLOCK_SUBTYPE = 53,
    command_ErrorCode_INVALID_STORED_BLOCK_CONTENT = 54
} command_ErrorCode;
#define _command_ErrorCode_MIN command_ErrorCode_OK
#define _command_ErrorCode_MAX command_ErrorCode_INVALID_STORED_BLOCK_CONTENT
#define _command_ErrorCode_ARRAYSIZE ((command_ErrorCode)(command_ErrorCode_INVALID_STORED_BLOCK_CONTENT+1))

typedef enum _command_MaskMode {
    command_MaskMode_ANY = 0,
    command_MaskMode_INCLUSIVE = 1,
    command_MaskMode_EXCLUSIVE = 2
} command_MaskMode;
#define _command_MaskMode_MIN command_MaskMode_ANY
#define _command_MaskMode_MAX command_MaskMode_EXCLUSIVE
#define _command_MaskMode_ARRAYSIZE ((command_MaskMode)(command_MaskMode_EXCLUSIVE+1))

/* Struct definitions */
typedef struct _command_Payload {
    uint16_t blockId;
    brewblox_BlockType blockType;
    uint16_t subtype;
    pb_callback_t content;
    pb_callback_t mask;
    command_MaskMode maskMode;
/* @@protoc_insertion_point(struct:command_Payload) */
} command_Payload;

typedef struct _command_Response {
    uint32_t msgId;
    command_ErrorCode error;
    pb_callback_t payload;
/* @@protoc_insertion_point(struct:command_Response) */
} command_Response;

typedef struct _command_Request {
    uint32_t msgId;
    command_Opcode opcode;
    command_Payload payload;
/* @@protoc_insertion_point(struct:command_Request) */
} command_Request;

/* Default values for struct fields */

/* Initializer values for message structs */
#define command_Payload_init_default             {0, _brewblox_BlockType_MIN, 0, {{NULL}, NULL}, {{NULL}, NULL}, _command_MaskMode_MIN}
#define command_Request_init_default             {0, _command_Opcode_MIN, command_Payload_init_default}
#define command_Response_init_default            {0, _command_ErrorCode_MIN, {{NULL}, NULL}}
#define command_Payload_init_zero                {0, _brewblox_BlockType_MIN, 0, {{NULL}, NULL}, {{NULL}, NULL}, _command_MaskMode_MIN}
#define command_Request_init_zero                {0, _command_Opcode_MIN, command_Payload_init_zero}
#define command_Response_init_zero               {0, _command_ErrorCode_MIN, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define command_Payload_blockId_tag              1
#define command_Payload_blockType_tag            2
#define command_Payload_subtype_tag              3
#define command_Payload_content_tag              4
#define command_Payload_mask_tag                 5
#define command_Payload_maskMode_tag             6
#define command_Response_msgId_tag               1
#define command_Response_error_tag               2
#define command_Response_payload_tag             3
#define command_Request_msgId_tag                1
#define command_Request_opcode_tag               2
#define command_Request_payload_tag              3

/* Struct field encoding specification for nanopb */
extern const pb_field_t command_Payload_fields[7];
extern const pb_field_t command_Request_fields[4];
extern const pb_field_t command_Response_fields[4];

/* Maximum encoded size of messages (where known) */
/* command_Payload_size depends on runtime parameters */
/* command_Request_size depends on runtime parameters */
/* command_Response_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define COMMAND_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
