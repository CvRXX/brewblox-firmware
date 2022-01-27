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
typedef enum _Controlbox_Opcode {
    Controlbox_Opcode_OPCODE_NONE = 0,
    Controlbox_Opcode_OPCODE_READ_OBJECT = 1,
    Controlbox_Opcode_OPCODE_WRITE_OBJECT = 2,
    Controlbox_Opcode_OPCODE_CREATE_OBJECT = 3,
    Controlbox_Opcode_OPCODE_DELETE_OBJECT = 4,
    Controlbox_Opcode_OPCODE_LIST_OBJECTS = 5,
    Controlbox_Opcode_OPCODE_READ_STORED_OBJECT = 6,
    Controlbox_Opcode_OPCODE_LIST_STORED_OBJECTS = 7,
    Controlbox_Opcode_OPCODE_CLEAR_OBJECTS = 8,
    Controlbox_Opcode_OPCODE_REBOOT = 9,
    Controlbox_Opcode_OPCODE_FACTORY_RESET = 10,
    Controlbox_Opcode_OPCODE_LIST_COMPATIBLE_OBJECTS = 11,
    Controlbox_Opcode_OPCODE_DISCOVER_OBJECTS = 12,
    Controlbox_Opcode_OPCODE_FIRMWARE_UPDATE = 100
} Controlbox_Opcode;
#define _Controlbox_Opcode_MIN Controlbox_Opcode_OPCODE_NONE
#define _Controlbox_Opcode_MAX Controlbox_Opcode_OPCODE_FIRMWARE_UPDATE
#define _Controlbox_Opcode_ARRAYSIZE ((Controlbox_Opcode)(Controlbox_Opcode_OPCODE_FIRMWARE_UPDATE+1))

typedef enum _Controlbox_ErrorCode {
    Controlbox_ErrorCode_ERR_OK = 0,
    Controlbox_ErrorCode_ERR_UNKNOWN_ERROR = 1,
    Controlbox_ErrorCode_ERR_INSUFFICIENT_HEAP = 4,
    Controlbox_ErrorCode_ERR_STREAM_ERROR_UNSPECIFIED = 8,
    Controlbox_ErrorCode_ERR_OUTPUT_STREAM_WRITE_ERROR = 9,
    Controlbox_ErrorCode_ERR_INPUT_STREAM_READ_ERROR = 10,
    Controlbox_ErrorCode_ERR_INPUT_STREAM_DECODING_ERROR = 11,
    Controlbox_ErrorCode_ERR_OUTPUT_STREAM_ENCODING_ERROR = 12,
    Controlbox_ErrorCode_ERR_INSUFFICIENT_PERSISTENT_STORAGE = 16,
    Controlbox_ErrorCode_ERR_PERSISTED_OBJECT_NOT_FOUND = 17,
    Controlbox_ErrorCode_ERR_INVALID_PERSISTED_BLOCK_TYPE = 18,
    Controlbox_ErrorCode_ERR_COULD_NOT_READ_PERSISTED_BLOCK_SIZE = 19,
    Controlbox_ErrorCode_ERR_PERSISTED_BLOCK_STREAM_ERROR = 20,
    Controlbox_ErrorCode_ERR_PERSISTED_STORAGE_WRITE_ERROR = 21,
    Controlbox_ErrorCode_ERR_CRC_ERROR_IN_STORED_OBJECT = 22,
    Controlbox_ErrorCode_ERR_OBJECT_NOT_WRITABLE = 32,
    Controlbox_ErrorCode_ERR_OBJECT_NOT_READABLE = 33,
    Controlbox_ErrorCode_ERR_OBJECT_NOT_CREATABLE = 34,
    Controlbox_ErrorCode_ERR_OBJECT_NOT_DELETABLE = 35,
    Controlbox_ErrorCode_ERR_INVALID_COMMAND = 63,
    Controlbox_ErrorCode_ERR_INVALID_OBJECT_ID = 64,
    Controlbox_ErrorCode_ERR_INVALID_OBJECT_TYPE = 65,
    Controlbox_ErrorCode_ERR_INVALID_OBJECT_GROUPS = 66,
    Controlbox_ErrorCode_ERR_CRC_ERROR_IN_COMMAND = 67,
    Controlbox_ErrorCode_ERR_OBJECT_DATA_NOT_ACCEPTED = 68,
    Controlbox_ErrorCode_ERR_WRITE_TO_INACTIVE_OBJECT = 200
} Controlbox_ErrorCode;
#define _Controlbox_ErrorCode_MIN Controlbox_ErrorCode_ERR_OK
#define _Controlbox_ErrorCode_MAX Controlbox_ErrorCode_ERR_WRITE_TO_INACTIVE_OBJECT
#define _Controlbox_ErrorCode_ARRAYSIZE ((Controlbox_ErrorCode)(Controlbox_ErrorCode_ERR_WRITE_TO_INACTIVE_OBJECT+1))

/* Struct definitions */
typedef struct _Controlbox_Payload {
    uint32_t blockId;
    BlockType objtype;
    uint16_t subtype;
    pb_callback_t data;
/* @@protoc_insertion_point(struct:Controlbox_Payload) */
} Controlbox_Payload;

typedef struct _Controlbox_Response {
    uint32_t msgId;
    Controlbox_ErrorCode error;
    pb_callback_t payload;
/* @@protoc_insertion_point(struct:Controlbox_Response) */
} Controlbox_Response;

typedef struct _Controlbox_Request {
    uint32_t msgId;
    Controlbox_Opcode opcode;
    Controlbox_Payload payload;
/* @@protoc_insertion_point(struct:Controlbox_Request) */
} Controlbox_Request;

/* Default values for struct fields */

/* Initializer values for message structs */
#define Controlbox_Payload_init_default          {0, _BlockType_MIN, 0, {{NULL}, NULL}}
#define Controlbox_Request_init_default          {0, _Controlbox_Opcode_MIN, Controlbox_Payload_init_default}
#define Controlbox_Response_init_default         {0, _Controlbox_ErrorCode_MIN, {{NULL}, NULL}}
#define Controlbox_Payload_init_zero             {0, _BlockType_MIN, 0, {{NULL}, NULL}}
#define Controlbox_Request_init_zero             {0, _Controlbox_Opcode_MIN, Controlbox_Payload_init_zero}
#define Controlbox_Response_init_zero            {0, _Controlbox_ErrorCode_MIN, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define Controlbox_Payload_blockId_tag           1
#define Controlbox_Payload_objtype_tag           2
#define Controlbox_Payload_subtype_tag           3
#define Controlbox_Payload_data_tag              4
#define Controlbox_Response_msgId_tag            1
#define Controlbox_Response_error_tag            2
#define Controlbox_Response_payload_tag          3
#define Controlbox_Request_msgId_tag             1
#define Controlbox_Request_opcode_tag            2
#define Controlbox_Request_payload_tag           3

/* Struct field encoding specification for nanopb */
extern const pb_field_t Controlbox_Payload_fields[5];
extern const pb_field_t Controlbox_Request_fields[4];
extern const pb_field_t Controlbox_Response_fields[4];

/* Maximum encoded size of messages (where known) */
/* Controlbox_Payload_size depends on runtime parameters */
/* Controlbox_Request_size depends on runtime parameters */
/* Controlbox_Response_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define CONTROLBOX_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
