/* Automatically generated nanopb header */

#ifndef PB_BLOX_DS2408_DS2408_PB_H_INCLUDED
#define PB_BLOX_DS2408_DS2408_PB_H_INCLUDED
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
typedef enum _blox_DS2408_ChannelId {
    blox_DS2408_ChannelId_DS2408_CHAN_NONE = 0,
    blox_DS2408_ChannelId_DS2408_CHAN_A = 1,
    blox_DS2408_ChannelId_DS2408_CHAN_B = 2,
    blox_DS2408_ChannelId_DS2408_CHAN_C = 3,
    blox_DS2408_ChannelId_DS2408_CHAN_D = 4,
    blox_DS2408_ChannelId_DS2408_CHAN_E = 5,
    blox_DS2408_ChannelId_DS2408_CHAN_F = 6,
    blox_DS2408_ChannelId_DS2408_CHAN_G = 7,
    blox_DS2408_ChannelId_DS2408_CHAN_H = 8,
    blox_DS2408_ChannelId_DS2408_VALVE_NONE = 0,
    blox_DS2408_ChannelId_DS2408_VALVE_A = 5,
    blox_DS2408_ChannelId_DS2408_VALVE_B = 1
} blox_DS2408_ChannelId;
#define _blox_DS2408_ChannelId_MIN blox_DS2408_ChannelId_DS2408_CHAN_NONE
#define _blox_DS2408_ChannelId_MAX blox_DS2408_ChannelId_DS2408_VALVE_B
#define _blox_DS2408_ChannelId_ARRAYSIZE ((blox_DS2408_ChannelId)(blox_DS2408_ChannelId_DS2408_VALVE_B+1))

typedef enum _blox_DS2408_PinConnectMode {
    blox_DS2408_PinConnectMode_CONNECT_VALVE = 0,
    blox_DS2408_PinConnectMode_CONNECT_ACTUATOR = 1
} blox_DS2408_PinConnectMode;
#define _blox_DS2408_PinConnectMode_MIN blox_DS2408_PinConnectMode_CONNECT_VALVE
#define _blox_DS2408_PinConnectMode_MAX blox_DS2408_PinConnectMode_CONNECT_ACTUATOR
#define _blox_DS2408_PinConnectMode_ARRAYSIZE ((blox_DS2408_PinConnectMode)(blox_DS2408_PinConnectMode_CONNECT_ACTUATOR+1))

/* Struct definitions */
typedef struct _blox_DS2408_Block {
    uint64_t address;
    bool connected;
    blox_DS2408_PinConnectMode connectMode;
    uint16_t oneWireBusId;
    pb_size_t channels_count;
    blox_IoArray_IoChannel channels[8];
/* @@protoc_insertion_point(struct:blox_DS2408_Block) */
} blox_DS2408_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_DS2408_Block_init_default           {0, 0, _blox_DS2408_PinConnectMode_MIN, 0, 0, {blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default}}
#define blox_DS2408_Block_init_zero              {0, 0, _blox_DS2408_PinConnectMode_MIN, 0, 0, {blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_DS2408_Block_address_tag            1
#define blox_DS2408_Block_connected_tag          6
#define blox_DS2408_Block_connectMode_tag        9
#define blox_DS2408_Block_oneWireBusId_tag       10
#define blox_DS2408_Block_channels_tag           11

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_DS2408_Block_fields[6];

/* Maximum encoded size of messages (where known) */
#define blox_DS2408_Block_size                   179

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DS2408_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
