/* Automatically generated nanopb header */

#ifndef PB_BLOX_MUTEX_MUTEX_PB_H_INCLUDED
#define PB_BLOX_MUTEX_MUTEX_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _blox_Mutex_Block {
    uint32_t differentActuatorWait;
    uint32_t waitRemaining;
/* @@protoc_insertion_point(struct:blox_Mutex_Block) */
} blox_Mutex_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Mutex_Block_init_default            {0, 0}
#define blox_Mutex_Block_init_zero               {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Mutex_Block_differentActuatorWait_tag 1
#define blox_Mutex_Block_waitRemaining_tag       2

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Mutex_Block_fields[3];

/* Maximum encoded size of messages (where known) */
#define blox_Mutex_Block_size                    12

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define MUTEX_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
