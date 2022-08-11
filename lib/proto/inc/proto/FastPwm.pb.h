/* Automatically generated nanopb header */

#ifndef PB_BLOX_FASTPWM_FASTPWM_PB_H_INCLUDED
#define PB_BLOX_FASTPWM_FASTPWM_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

#include "Constraints.pb.h"

#include "IoArray.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _blox_FastPwm_Block {
    uint16_t hwDevice;
    uint8_t channel;
    blox_IoArray_PwmFrequency frequency;
    int32_t setting;
    int32_t desiredSetting;
    int32_t value;
    blox_Constraints_AnalogConstraints constrainedBy;
    bool enabled;
    blox_IoArray_TransitionDurationPreset transitionDurationPreset;
    uint32_t transitionDurationSetting;
    uint32_t transitionDurationValue;
    bool invert;
    uint16_t claimedBy;
/* @@protoc_insertion_point(struct:blox_FastPwm_Block) */
} blox_FastPwm_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_FastPwm_Block_init_default          {0, 0, _blox_IoArray_PwmFrequency_MIN, 0, 0, 0, blox_Constraints_AnalogConstraints_init_default, 0, _blox_IoArray_TransitionDurationPreset_MIN, 0, 0, 0, 0}
#define blox_FastPwm_Block_init_zero             {0, 0, _blox_IoArray_PwmFrequency_MIN, 0, 0, 0, blox_Constraints_AnalogConstraints_init_zero, 0, _blox_IoArray_TransitionDurationPreset_MIN, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_FastPwm_Block_hwDevice_tag          1
#define blox_FastPwm_Block_channel_tag           2
#define blox_FastPwm_Block_frequency_tag         3
#define blox_FastPwm_Block_setting_tag           4
#define blox_FastPwm_Block_desiredSetting_tag    5
#define blox_FastPwm_Block_value_tag             6
#define blox_FastPwm_Block_constrainedBy_tag     7
#define blox_FastPwm_Block_enabled_tag           8
#define blox_FastPwm_Block_transitionDurationPreset_tag 9
#define blox_FastPwm_Block_transitionDurationSetting_tag 10
#define blox_FastPwm_Block_transitionDurationValue_tag 11
#define blox_FastPwm_Block_invert_tag            12
#define blox_FastPwm_Block_claimedBy_tag         13

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_FastPwm_Block_fields[14];

/* Maximum encoded size of messages (where known) */
#define blox_FastPwm_Block_size                  259

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define FASTPWM_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
