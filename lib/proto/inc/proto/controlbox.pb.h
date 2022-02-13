/* Automatically generated nanopb header */

#ifndef PB_CONTROLBOX_CONTROLBOX_PB_H_INCLUDED
#define PB_CONTROLBOX_CONTROLBOX_PB_H_INCLUDED
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
typedef enum _controlbox_Opcode {
    controlbox_Opcode_OPCODE_NONE = 0,
    controlbox_Opcode_OPCODE_READ_OBJECT = 1,
    controlbox_Opcode_OPCODE_WRITE_OBJECT = 2,
    controlbox_Opcode_OPCODE_CREATE_OBJECT = 3,
    controlbox_Opcode_OPCODE_DELETE_OBJECT = 4,
    controlbox_Opcode_OPCODE_LIST_OBJECTS = 5,
    controlbox_Opcode_OPCODE_READ_STORED_OBJECT = 6,
    controlbox_Opcode_OPCODE_LIST_STORED_OBJECTS = 7,
    controlbox_Opcode_OPCODE_CLEAR_OBJECTS = 8,
    controlbox_Opcode_OPCODE_REBOOT = 9,
    controlbox_Opcode_OPCODE_FACTORY_RESET = 10,
    controlbox_Opcode_OPCODE_LIST_COMPATIBLE_OBJECTS = 11,
    controlbox_Opcode_OPCODE_DISCOVER_OBJECTS = 12,
    controlbox_Opcode_OPCODE_FIRMWARE_UPDATE = 100
} controlbox_Opcode;
#define _controlbox_Opcode_MIN controlbox_Opcode_OPCODE_NONE
#define _controlbox_Opcode_MAX controlbox_Opcode_OPCODE_FIRMWARE_UPDATE
#define _controlbox_Opcode_ARRAYSIZE ((controlbox_Opcode)(controlbox_Opcode_OPCODE_FIRMWARE_UPDATE+1))

typedef enum _controlbox_ErrorCode {
    controlbox_ErrorCode_ERR_OK = 0,
    controlbox_ErrorCode_ERR_UNKNOWN_ERROR = 1,
    controlbox_ErrorCode_ERR_INSUFFICIENT_HEAP = 4,
    controlbox_ErrorCode_ERR_STREAM_ERROR_UNSPECIFIED = 8,
    controlbox_ErrorCode_ERR_OUTPUT_STREAM_WRITE_ERROR = 9,
    controlbox_ErrorCode_ERR_INPUT_STREAM_READ_ERROR = 10,
    controlbox_ErrorCode_ERR_INPUT_STREAM_DECODING_ERROR = 11,
    controlbox_ErrorCode_ERR_OUTPUT_STREAM_ENCODING_ERROR = 12,
    controlbox_ErrorCode_ERR_INSUFFICIENT_PERSISTENT_STORAGE = 16,
    controlbox_ErrorCode_ERR_PERSISTED_OBJECT_NOT_FOUND = 17,
    controlbox_ErrorCode_ERR_INVALID_PERSISTED_BLOCK_TYPE = 18,
    controlbox_ErrorCode_ERR_COULD_NOT_READ_PERSISTED_BLOCK_SIZE = 19,
    controlbox_ErrorCode_ERR_PERSISTED_BLOCK_STREAM_ERROR = 20,
    controlbox_ErrorCode_ERR_PERSISTED_STORAGE_WRITE_ERROR = 21,
    controlbox_ErrorCode_ERR_CRC_ERROR_IN_STORED_OBJECT = 22,
    controlbox_ErrorCode_ERR_OBJECT_NOT_WRITABLE = 32,
    controlbox_ErrorCode_ERR_OBJECT_NOT_READABLE = 33,
    controlbox_ErrorCode_ERR_OBJECT_NOT_CREATABLE = 34,
    controlbox_ErrorCode_ERR_OBJECT_NOT_DELETABLE = 35,
    controlbox_ErrorCode_ERR_INVALID_COMMAND = 63,
    controlbox_ErrorCode_ERR_INVALID_OBJECT_ID = 64,
    controlbox_ErrorCode_ERR_INVALID_OBJECT_TYPE = 65,
    controlbox_ErrorCode_ERR_INVALID_OBJECT_GROUPS = 66,
    controlbox_ErrorCode_ERR_CRC_ERROR_IN_COMMAND = 67,
    controlbox_ErrorCode_ERR_OBJECT_DATA_NOT_ACCEPTED = 68,
    controlbox_ErrorCode_ERR_WRITE_TO_INACTIVE_OBJECT = 200
} controlbox_ErrorCode;
#define _controlbox_ErrorCode_MIN controlbox_ErrorCode_ERR_OK
#define _controlbox_ErrorCode_MAX controlbox_ErrorCode_ERR_WRITE_TO_INACTIVE_OBJECT
#define _controlbox_ErrorCode_ARRAYSIZE ((controlbox_ErrorCode)(controlbox_ErrorCode_ERR_WRITE_TO_INACTIVE_OBJECT+1))

/* Struct definitions */
typedef struct _controlbox_Payload {
    uint32_t blockId;
    brewblox_BlockType objtype;
    uint16_t subtype;
    pb_callback_t data;
/* @@protoc_insertion_point(struct:controlbox_Payload) */
} controlbox_Payload;

typedef struct _controlbox_Response {
    uint32_t msgId;
    controlbox_ErrorCode error;
    pb_callback_t payload;
/* @@protoc_insertion_point(struct:controlbox_Response) */
} controlbox_Response;

typedef struct _controlbox_Request {
    uint32_t msgId;
    controlbox_Opcode opcode;
    controlbox_Payload payload;
/* @@protoc_insertion_point(struct:controlbox_Request) */
} controlbox_Request;

/* Default values for struct fields */

/* Initializer values for message structs */
#define controlbox_Payload_init_default          {0, _brewblox_BlockType_MIN, 0, {{NULL}, NULL}}
#define controlbox_Request_init_default          {0, _controlbox_Opcode_MIN, controlbox_Payload_init_default}
#define controlbox_Response_init_default         {0, _controlbox_ErrorCode_MIN, {{NULL}, NULL}}
#define controlbox_Payload_init_zero             {0, _brewblox_BlockType_MIN, 0, {{NULL}, NULL}}
#define controlbox_Request_init_zero             {0, _controlbox_Opcode_MIN, controlbox_Payload_init_zero}
#define controlbox_Response_init_zero            {0, _controlbox_ErrorCode_MIN, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define controlbox_Payload_blockId_tag           1
#define controlbox_Payload_objtype_tag           2
#define controlbox_Payload_subtype_tag           3
#define controlbox_Payload_data_tag              4
#define controlbox_Response_msgId_tag            1
#define controlbox_Response_error_tag            2
#define controlbox_Response_payload_tag          3
#define controlbox_Request_msgId_tag             1
#define controlbox_Request_opcode_tag            2
#define controlbox_Request_payload_tag           3

/* Struct field encoding specification for nanopb */
extern const pb_field_t controlbox_Payload_fields[5];
extern const pb_field_t controlbox_Request_fields[4];
extern const pb_field_t controlbox_Response_fields[4];

/* Maximum encoded size of messages (where known) */
/* controlbox_Payload_size depends on runtime parameters */
/* controlbox_Request_size depends on runtime parameters */
/* controlbox_Response_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define CONTROLBOX_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
