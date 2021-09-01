/* Automatically generated nanopb header */

#ifndef PB_BLOX_SPARK2PINS_PB_H_INCLUDED
#define PB_BLOX_SPARK2PINS_PB_H_INCLUDED
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
typedef enum _blox_Spark2ChannelIds {
    blox_Spark2ChannelIds_SPARK2_CHAN_NONE = 0,
    blox_Spark2ChannelIds_SPARK2_CHAN_BOTTOM1 = 1,
    blox_Spark2ChannelIds_SPARK2_CHAN_BOTTOM2 = 2,
    blox_Spark2ChannelIds_SPARK2_CHAN_BOTTOM3 = 3,
    blox_Spark2ChannelIds_SPARK2_CHAN_BOTTOM0 = 4
} blox_Spark2ChannelIds;
#define _blox_Spark2ChannelIds_MIN blox_Spark2ChannelIds_SPARK2_CHAN_NONE
#define _blox_Spark2ChannelIds_MAX blox_Spark2ChannelIds_SPARK2_CHAN_BOTTOM0
#define _blox_Spark2ChannelIds_ARRAYSIZE ((blox_Spark2ChannelIds)(blox_Spark2ChannelIds_SPARK2_CHAN_BOTTOM0+1))

typedef enum _blox_Spark2Pins_Hardware {
    blox_Spark2Pins_Hardware_HW_UNKNOWN = 0,
    blox_Spark2Pins_Hardware_HW_SPARK1 = 1,
    blox_Spark2Pins_Hardware_HW_SPARK2 = 2
} blox_Spark2Pins_Hardware;
#define _blox_Spark2Pins_Hardware_MIN blox_Spark2Pins_Hardware_HW_UNKNOWN
#define _blox_Spark2Pins_Hardware_MAX blox_Spark2Pins_Hardware_HW_SPARK2
#define _blox_Spark2Pins_Hardware_ARRAYSIZE ((blox_Spark2Pins_Hardware)(blox_Spark2Pins_Hardware_HW_SPARK2+1))

/* Struct definitions */
typedef struct _blox_Spark2Pins {
    bool soundAlarm;
    blox_Spark2Pins_Hardware hardware;
    pb_size_t channels_count;
    blox_IoChannel channels[4];
/* @@protoc_insertion_point(struct:blox_Spark2Pins) */
} blox_Spark2Pins;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Spark2Pins_init_default             {0, _blox_Spark2Pins_Hardware_MIN, 0, {blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default}}
#define blox_Spark2Pins_init_zero                {0, _blox_Spark2Pins_Hardware_MIN, 0, {blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Spark2Pins_soundAlarm_tag           5
#define blox_Spark2Pins_hardware_tag             8
#define blox_Spark2Pins_channels_tag             9

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Spark2Pins_fields[4];

/* Maximum encoded size of messages (where known) */
#define blox_Spark2Pins_size                     36

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SPARK2PINS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
