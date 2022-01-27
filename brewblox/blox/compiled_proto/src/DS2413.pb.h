/* Automatically generated nanopb header */

#ifndef PB_BLOX_DS2413_DS2413_PB_H_INCLUDED
#define PB_BLOX_DS2413_DS2413_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

#include "IoArray.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _blox_DS2413_ChannelId {
    blox_DS2413_ChannelId_DS2413_CHAN_NONE = 0,
    blox_DS2413_ChannelId_DS2413_CHAN_A = 1,
    blox_DS2413_ChannelId_DS2413_CHAN_B = 2
} blox_DS2413_ChannelId;
#define _blox_DS2413_ChannelId_MIN blox_DS2413_ChannelId_DS2413_CHAN_NONE
#define _blox_DS2413_ChannelId_MAX blox_DS2413_ChannelId_DS2413_CHAN_B
#define _blox_DS2413_ChannelId_ARRAYSIZE ((blox_DS2413_ChannelId)(blox_DS2413_ChannelId_DS2413_CHAN_B+1))

/* Struct definitions */
typedef struct _blox_DS2413_Block {
    uint64_t address;
    bool connected;
    uint16_t oneWireBusId;
    pb_size_t channels_count;
    blox_IoArray_IoChannel channels[2];
/* @@protoc_insertion_point(struct:blox_DS2413_Block) */
} blox_DS2413_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_DS2413_Block_init_default           {0, 0, 0, 0, {blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default}}
#define blox_DS2413_Block_init_zero              {0, 0, 0, 0, {blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_DS2413_Block_address_tag            1
#define blox_DS2413_Block_connected_tag          6
#define blox_DS2413_Block_oneWireBusId_tag       8
#define blox_DS2413_Block_channels_tag           9

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_DS2413_Block_fields[5];

/* Maximum encoded size of messages (where known) */
#define blox_DS2413_Block_size                   33

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DS2413_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
