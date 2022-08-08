/* Automatically generated nanopb header */

#ifndef PB_BLOX_IOARRAY_IOARRAY_PB_H_INCLUDED
#define PB_BLOX_IOARRAY_IOARRAY_PB_H_INCLUDED
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
typedef enum _blox_IoArray_DigitalState {
    blox_IoArray_DigitalState_STATE_INACTIVE = 0,
    blox_IoArray_DigitalState_STATE_ACTIVE = 1,
    blox_IoArray_DigitalState_STATE_UNKNOWN = 2,
    blox_IoArray_DigitalState_STATE_REVERSE = 3,
    blox_IoArray_DigitalState_Inactive = 0,
    blox_IoArray_DigitalState_Active = 1,
    blox_IoArray_DigitalState_Unknown = 2
} blox_IoArray_DigitalState;
#define _blox_IoArray_DigitalState_MIN blox_IoArray_DigitalState_STATE_INACTIVE
#define _blox_IoArray_DigitalState_MAX blox_IoArray_DigitalState_Unknown
#define _blox_IoArray_DigitalState_ARRAYSIZE ((blox_IoArray_DigitalState)(blox_IoArray_DigitalState_Unknown+1))

typedef enum _blox_IoArray_TransitionDurationPreset {
    blox_IoArray_TransitionDurationPreset_ST_OFF = 0,
    blox_IoArray_TransitionDurationPreset_ST_FAST = 1,
    blox_IoArray_TransitionDurationPreset_ST_MEDIUM = 2,
    blox_IoArray_TransitionDurationPreset_ST_SLOW = 3,
    blox_IoArray_TransitionDurationPreset_ST_CUSTOM = 4
} blox_IoArray_TransitionDurationPreset;
#define _blox_IoArray_TransitionDurationPreset_MIN blox_IoArray_TransitionDurationPreset_ST_OFF
#define _blox_IoArray_TransitionDurationPreset_MAX blox_IoArray_TransitionDurationPreset_ST_CUSTOM
#define _blox_IoArray_TransitionDurationPreset_ARRAYSIZE ((blox_IoArray_TransitionDurationPreset)(blox_IoArray_TransitionDurationPreset_ST_CUSTOM+1))

typedef enum _blox_IoArray_ChannelCapabilities {
    blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_NONE = 0,
    blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_DIGITAL_OUTPUT = 1,
    blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_PWM_80HZ = 2,
    blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_PWM_100HZ = 4,
    blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_PWM_200HZ = 8,
    blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_PWM_2000HZ = 16,
    blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_BIDIRECTIONAL = 32,
    blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_DIGITAL_INPUT = 64
} blox_IoArray_ChannelCapabilities;
#define _blox_IoArray_ChannelCapabilities_MIN blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_NONE
#define _blox_IoArray_ChannelCapabilities_MAX blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_DIGITAL_INPUT
#define _blox_IoArray_ChannelCapabilities_ARRAYSIZE ((blox_IoArray_ChannelCapabilities)(blox_IoArray_ChannelCapabilities_CHAN_SUPPORTS_DIGITAL_INPUT+1))

typedef enum _blox_IoArray_PwmFrequency {
    blox_IoArray_PwmFrequency_PWM_FREQ_80HZ = 0,
    blox_IoArray_PwmFrequency_PWM_FREQ_100HZ = 1,
    blox_IoArray_PwmFrequency_PWM_FREQ_200HZ = 2,
    blox_IoArray_PwmFrequency_PWM_FREQ_2000HZ = 3
} blox_IoArray_PwmFrequency;
#define _blox_IoArray_PwmFrequency_MIN blox_IoArray_PwmFrequency_PWM_FREQ_80HZ
#define _blox_IoArray_PwmFrequency_MAX blox_IoArray_PwmFrequency_PWM_FREQ_2000HZ
#define _blox_IoArray_PwmFrequency_ARRAYSIZE ((blox_IoArray_PwmFrequency)(blox_IoArray_PwmFrequency_PWM_FREQ_2000HZ+1))

/* Struct definitions */
typedef struct _blox_IoArray_IoChannel {
    uint8_t id;
    uint16_t capabilities;
/* @@protoc_insertion_point(struct:blox_IoArray_IoChannel) */
} blox_IoArray_IoChannel;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_IoArray_IoChannel_init_default      {0, 0}
#define blox_IoArray_IoChannel_init_zero         {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_IoArray_IoChannel_id_tag            1
#define blox_IoArray_IoChannel_capabilities_tag  2

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_IoArray_IoChannel_fields[3];

/* Maximum encoded size of messages (where known) */
#define blox_IoArray_IoChannel_size              12

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define IOARRAY_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
