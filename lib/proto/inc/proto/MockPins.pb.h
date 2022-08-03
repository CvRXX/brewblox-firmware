/* Automatically generated nanopb header */

#ifndef PB_BLOX_MOCKPINS_MOCKPINS_PB_H_INCLUDED
#define PB_BLOX_MOCKPINS_MOCKPINS_PB_H_INCLUDED
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
typedef enum _blox_MockPins_ChannelId {
    blox_MockPins_ChannelId_MOCKPINS_CHAN_NONE = 0,
    blox_MockPins_ChannelId_MOCKPINS_CHAN_A = 1,
    blox_MockPins_ChannelId_MOCKPINS_CHAN_B = 2,
    blox_MockPins_ChannelId_MOCKPINS_CHAN_C = 3,
    blox_MockPins_ChannelId_MOCKPINS_CHAN_D = 4,
    blox_MockPins_ChannelId_MOCKPINS_CHAN_E = 5,
    blox_MockPins_ChannelId_MOCKPINS_CHAN_F = 6,
    blox_MockPins_ChannelId_MOCKPINS_CHAN_G = 7,
    blox_MockPins_ChannelId_MOCKPINS_CHAN_H = 8
} blox_MockPins_ChannelId;
#define _blox_MockPins_ChannelId_MIN blox_MockPins_ChannelId_MOCKPINS_CHAN_NONE
#define _blox_MockPins_ChannelId_MAX blox_MockPins_ChannelId_MOCKPINS_CHAN_H
#define _blox_MockPins_ChannelId_ARRAYSIZE ((blox_MockPins_ChannelId)(blox_MockPins_ChannelId_MOCKPINS_CHAN_H+1))

/* Struct definitions */
typedef struct _blox_MockPins_Block {
    pb_size_t channels_count;
    blox_IoArray_IoChannel channels[8];
/* @@protoc_insertion_point(struct:blox_MockPins_Block) */
} blox_MockPins_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_MockPins_Block_init_default         {0, {blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default}}
#define blox_MockPins_Block_init_zero            {0, {blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_MockPins_Block_channels_tag         2

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_MockPins_Block_fields[2];

/* Maximum encoded size of messages (where known) */
#define blox_MockPins_Block_size                 112

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define MOCKPINS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
