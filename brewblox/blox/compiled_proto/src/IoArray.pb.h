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

typedef enum _blox_ChannelConfig {
    blox_ChannelConfig_CHANNEL_UNUSED = 0,
    blox_ChannelConfig_CHANNEL_DRIVING_OFF = 1,
    blox_ChannelConfig_CHANNEL_DRIVING_ON = 2,
    blox_ChannelConfig_CHANNEL_DRIVING_REVERSE = 3,
    blox_ChannelConfig_CHANNEL_DRIVING_BRAKE_LOW_SIDE = 4,
    blox_ChannelConfig_CHANNEL_DRIVING_BRAKE_HIGH_SIDE = 5,
    blox_ChannelConfig_CHANNEL_DRIVING_PWM = 6,
    blox_ChannelConfig_CHANNEL_DRIVING_PWM_REVERSE = 7,
    blox_ChannelConfig_CHANNEL_INPUT = 10,
    blox_ChannelConfig_CHANNEL_UNKNOWN = 255,
    blox_ChannelConfig_CHANNEL_ACTIVE_LOW = 1,
    blox_ChannelConfig_CHANNEL_ACTIVE_HIGH = 2
} blox_ChannelConfig;
#define _blox_ChannelConfig_MIN blox_ChannelConfig_CHANNEL_UNUSED
#define _blox_ChannelConfig_MAX blox_ChannelConfig_CHANNEL_ACTIVE_HIGH
#define _blox_ChannelConfig_ARRAYSIZE ((blox_ChannelConfig)(blox_ChannelConfig_CHANNEL_ACTIVE_HIGH+1))

/* Struct definitions */
typedef struct _blox_IoChannel {
    blox_ChannelConfig config;
    blox_DigitalState state;
/* @@protoc_insertion_point(struct:blox_IoChannel) */
} blox_IoChannel;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_IoChannel_init_default              {_blox_ChannelConfig_MIN, _blox_DigitalState_MIN}
#define blox_IoChannel_init_zero                 {_blox_ChannelConfig_MIN, _blox_DigitalState_MIN}

/* Field tags (for use in manual encoding/decoding) */
#define blox_IoChannel_config_tag                1
#define blox_IoChannel_state_tag                 2

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_IoChannel_fields[3];

/* Maximum encoded size of messages (where known) */
#define blox_IoChannel_size                      5

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define IOARRAY_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
