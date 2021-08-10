/* Automatically generated nanopb header */

#ifndef PB_BLOX_PID_PB_H_INCLUDED
#define PB_BLOX_PID_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

#include "SetpointSensorPair.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _blox_Pid {
    uint16_t inputId;
    uint16_t outputId;
    int32_t inputValue;
    int32_t inputSetting;
    int32_t outputValue;
    int32_t outputSetting;
    bool enabled;
    bool active;
    int32_t kp;
    uint16_t ti;
    uint16_t td;
    int32_t p;
    int32_t i;
    int32_t d;
    int32_t error;
    int32_t integral;
    int32_t derivative;
    uint16_t drivenOutputId;
    int32_t integralReset;
    int32_t boilPointAdjust;
    int32_t boilMinOutput;
    bool boilModeActive;
    blox_FilterChoice derivativeFilter;
    pb_size_t strippedFields_count;
    uint16_t strippedFields[4];
/* @@protoc_insertion_point(struct:blox_Pid) */
} blox_Pid;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Pid_init_default                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _blox_FilterChoice_MIN, 0, {0, 0, 0, 0}}
#define blox_Pid_init_zero                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _blox_FilterChoice_MIN, 0, {0, 0, 0, 0}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Pid_inputId_tag                     1
#define blox_Pid_outputId_tag                    2
#define blox_Pid_inputValue_tag                  5
#define blox_Pid_inputSetting_tag                6
#define blox_Pid_outputValue_tag                 7
#define blox_Pid_outputSetting_tag               8
#define blox_Pid_enabled_tag                     11
#define blox_Pid_active_tag                      12
#define blox_Pid_kp_tag                          13
#define blox_Pid_ti_tag                          14
#define blox_Pid_td_tag                          15
#define blox_Pid_p_tag                           16
#define blox_Pid_i_tag                           17
#define blox_Pid_d_tag                           18
#define blox_Pid_error_tag                       19
#define blox_Pid_integral_tag                    20
#define blox_Pid_derivative_tag                  21
#define blox_Pid_drivenOutputId_tag              22
#define blox_Pid_integralReset_tag               23
#define blox_Pid_boilPointAdjust_tag             24
#define blox_Pid_boilMinOutput_tag               25
#define blox_Pid_boilModeActive_tag              26
#define blox_Pid_derivativeFilter_tag            27
#define blox_Pid_strippedFields_tag              99

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Pid_fields[25];

/* Maximum encoded size of messages (where known) */
#define blox_Pid_size                            162

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define PID_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
