/* Automatically generated nanopb header */

#ifndef PB_BLOX_TICKS_TICKS_PB_H_INCLUDED
#define PB_BLOX_TICKS_TICKS_PB_H_INCLUDED
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
typedef struct _blox_Ticks_Block {
    uint32_t millisSinceBoot;
    uint32_t secondsSinceEpoch;
    uint32_t avgCommunicationTask;
    uint32_t avgBlocksUpdateTask;
    uint32_t avgDisplayTask;
    uint32_t avgSystemTask;
/* @@protoc_insertion_point(struct:blox_Ticks_Block) */
} blox_Ticks_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Ticks_Block_init_default            {0, 0, 0, 0, 0, 0}
#define blox_Ticks_Block_init_zero               {0, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Ticks_Block_millisSinceBoot_tag     1
#define blox_Ticks_Block_secondsSinceEpoch_tag   2
#define blox_Ticks_Block_avgCommunicationTask_tag 3
#define blox_Ticks_Block_avgBlocksUpdateTask_tag 4
#define blox_Ticks_Block_avgDisplayTask_tag      5
#define blox_Ticks_Block_avgSystemTask_tag       6

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Ticks_Block_fields[7];

/* Maximum encoded size of messages (where known) */
#define blox_Ticks_Block_size                    36

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TICKS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
