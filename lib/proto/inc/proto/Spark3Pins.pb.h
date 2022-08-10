/* Automatically generated nanopb header */

#ifndef PB_BLOX_SPARK3PINS_SPARK3PINS_PB_H_INCLUDED
#define PB_BLOX_SPARK3PINS_SPARK3PINS_PB_H_INCLUDED
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
typedef enum _blox_Spark3Pins_ChannelId {
    blox_Spark3Pins_ChannelId_SPARK3_NO_PIN = 0,
    blox_Spark3Pins_ChannelId_SPARK3_CHAN_TOP1 = 1,
    blox_Spark3Pins_ChannelId_SPARK3_CHAN_TOP2 = 2,
    blox_Spark3Pins_ChannelId_SPARK3_CHAN_TOP3 = 3,
    blox_Spark3Pins_ChannelId_SPARK3_CHAN_BOTTOM1 = 4,
    blox_Spark3Pins_ChannelId_SPARK3_CHAN_BOTTOM2 = 5
} blox_Spark3Pins_ChannelId;
#define _blox_Spark3Pins_ChannelId_MIN blox_Spark3Pins_ChannelId_SPARK3_NO_PIN
#define _blox_Spark3Pins_ChannelId_MAX blox_Spark3Pins_ChannelId_SPARK3_CHAN_BOTTOM2
#define _blox_Spark3Pins_ChannelId_ARRAYSIZE ((blox_Spark3Pins_ChannelId)(blox_Spark3Pins_ChannelId_SPARK3_CHAN_BOTTOM2+1))

/* Struct definitions */
typedef struct _blox_Spark3Pins_Block {
    bool enableIoSupply5V;
    bool enableIoSupply12V;
    bool soundAlarm;
    uint16_t voltage5;
    uint16_t voltage12;
    pb_size_t channels_count;
    blox_IoArray_IoChannel channels[5];
/* @@protoc_insertion_point(struct:blox_Spark3Pins_Block) */
} blox_Spark3Pins_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Spark3Pins_Block_init_default       {0, 0, 0, 0, 0, 0, {blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default, blox_IoArray_IoChannel_init_default}}
#define blox_Spark3Pins_Block_init_zero          {0, 0, 0, 0, 0, 0, {blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero, blox_IoArray_IoChannel_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Spark3Pins_Block_enableIoSupply5V_tag 2
#define blox_Spark3Pins_Block_enableIoSupply12V_tag 3
#define blox_Spark3Pins_Block_soundAlarm_tag     5
#define blox_Spark3Pins_Block_voltage5_tag       6
#define blox_Spark3Pins_Block_voltage12_tag      7
#define blox_Spark3Pins_Block_channels_tag       8

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Spark3Pins_Block_fields[7];

/* Maximum encoded size of messages (where known) */
#define blox_Spark3Pins_Block_size               118

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SPARK3PINS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
