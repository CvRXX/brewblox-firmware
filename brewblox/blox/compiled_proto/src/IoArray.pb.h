/* Automatically generated nanopb header */

#ifndef PB_BLOX_IOARRAY_PB_H_INCLUDED
#define PB_BLOX_IOARRAY_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _blox_DigitalState {
    blox_DigitalState_STATE_INACTIVE = 0,
    blox_DigitalState_STATE_ACTIVE = 1,
    blox_DigitalState_STATE_UNKNOWN = 2,
    blox_DigitalState_STATE_REVERSE = 3,
    blox_DigitalState_Inactive = 0,
    blox_DigitalState_Active = 1,
    blox_DigitalState_Unknown = 2
} blox_DigitalState;
#define _blox_DigitalState_MIN blox_DigitalState_STATE_INACTIVE
#define _blox_DigitalState_MAX blox_DigitalState_Unknown
#define _blox_DigitalState_ARRAYSIZE ((blox_DigitalState)(blox_DigitalState_Unknown+1))

/* Struct definitions */
typedef struct _blox_IoChannel {
    uint8_t id;
/* @@protoc_insertion_point(struct:blox_IoChannel) */
} blox_IoChannel;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_IoChannel_init_default              {0}
#define blox_IoChannel_init_zero                 {0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_IoChannel_id_tag                    1

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_IoChannel_fields[2];

/* Maximum encoded size of messages (where known) */
#define blox_IoChannel_size                      6

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define IOARRAY_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
