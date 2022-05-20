/* Automatically generated nanopb header */

#ifndef PB_BLOX_SEQUENCE_SEQUENCE_PB_H_INCLUDED
#define PB_BLOX_SEQUENCE_SEQUENCE_PB_H_INCLUDED
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
typedef enum _blox_Sequence_SequenceStatus {
    blox_Sequence_SequenceStatus_UNKNOWN = 0,
    blox_Sequence_SequenceStatus_DISABLED = 1,
    blox_Sequence_SequenceStatus_PAUSED = 2,
    blox_Sequence_SequenceStatus_ACTIVE = 3,
    blox_Sequence_SequenceStatus_WAITING = 4,
    blox_Sequence_SequenceStatus_DONE = 5,
    blox_Sequence_SequenceStatus_RESTART = 6,
    blox_Sequence_SequenceStatus_ERROR = 7
} blox_Sequence_SequenceStatus;
#define _blox_Sequence_SequenceStatus_MIN blox_Sequence_SequenceStatus_UNKNOWN
#define _blox_Sequence_SequenceStatus_MAX blox_Sequence_SequenceStatus_ERROR
#define _blox_Sequence_SequenceStatus_ARRAYSIZE ((blox_Sequence_SequenceStatus)(blox_Sequence_SequenceStatus_ERROR+1))

typedef enum _blox_Sequence_SequenceError {
    blox_Sequence_SequenceError_NONE = 0,
    blox_Sequence_SequenceError_INVALID_ARGUMENT = 1,
    blox_Sequence_SequenceError_INVALID_TARGET = 2,
    blox_Sequence_SequenceError_INVALID_TARGET_TYPE = 3,
    blox_Sequence_SequenceError_DISABLED_TARGET = 4,
    blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE = 5
} blox_Sequence_SequenceError;
#define _blox_Sequence_SequenceError_MIN blox_Sequence_SequenceError_NONE
#define _blox_Sequence_SequenceError_MAX blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE
#define _blox_Sequence_SequenceError_ARRAYSIZE ((blox_Sequence_SequenceError)(blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE+1))

/* Struct definitions */
typedef struct _blox_Sequence_Restart {
    char dummy_field;
/* @@protoc_insertion_point(struct:blox_Sequence_Restart) */
} blox_Sequence_Restart;

typedef struct _blox_Sequence_Block {
    bool enabled;
    pb_callback_t instructions;
    bool overrideState;
    uint16_t activeInstruction;
    uint32_t activeInstructionStartedAt;
    uint32_t disabledAt;
    uint32_t disabledDuration;
    blox_Sequence_SequenceStatus status;
    blox_Sequence_SequenceError error;
/* @@protoc_insertion_point(struct:blox_Sequence_Block) */
} blox_Sequence_Block;

typedef struct _blox_Sequence_EnableDisable {
    uint16_t target;
/* @@protoc_insertion_point(struct:blox_Sequence_EnableDisable) */
} blox_Sequence_EnableDisable;

typedef struct _blox_Sequence_InstructionReset {
    uint16_t activeInstruction;
    uint32_t activeInstructionStartedAt;
/* @@protoc_insertion_point(struct:blox_Sequence_InstructionReset) */
} blox_Sequence_InstructionReset;

typedef struct _blox_Sequence_SetDigital {
    uint16_t target;
    blox_IoArray_DigitalState setting;
/* @@protoc_insertion_point(struct:blox_Sequence_SetDigital) */
} blox_Sequence_SetDigital;

typedef struct _blox_Sequence_SetPwm {
    uint16_t target;
    int32_t setting;
/* @@protoc_insertion_point(struct:blox_Sequence_SetPwm) */
} blox_Sequence_SetPwm;

typedef struct _blox_Sequence_SetSetpoint {
    uint16_t target;
    int32_t setting;
/* @@protoc_insertion_point(struct:blox_Sequence_SetSetpoint) */
} blox_Sequence_SetSetpoint;

typedef struct _blox_Sequence_StartWaitProfile {
    uint16_t target;
/* @@protoc_insertion_point(struct:blox_Sequence_StartWaitProfile) */
} blox_Sequence_StartWaitProfile;

typedef struct _blox_Sequence_StartWaitSequence {
    uint16_t target;
/* @@protoc_insertion_point(struct:blox_Sequence_StartWaitSequence) */
} blox_Sequence_StartWaitSequence;

typedef struct _blox_Sequence_WaitDigital {
    uint16_t target;
/* @@protoc_insertion_point(struct:blox_Sequence_WaitDigital) */
} blox_Sequence_WaitDigital;

typedef struct _blox_Sequence_WaitDuration {
    uint32_t duration;
/* @@protoc_insertion_point(struct:blox_Sequence_WaitDuration) */
} blox_Sequence_WaitDuration;

typedef struct _blox_Sequence_WaitPwm {
    uint16_t target;
    int32_t precision;
/* @@protoc_insertion_point(struct:blox_Sequence_WaitPwm) */
} blox_Sequence_WaitPwm;

typedef struct _blox_Sequence_WaitSetpoint {
    uint16_t target;
    int32_t precision;
/* @@protoc_insertion_point(struct:blox_Sequence_WaitSetpoint) */
} blox_Sequence_WaitSetpoint;

typedef struct _blox_Sequence_WaitTemperature {
    uint16_t target;
    int32_t lower;
    int32_t upper;
/* @@protoc_insertion_point(struct:blox_Sequence_WaitTemperature) */
} blox_Sequence_WaitTemperature;

typedef struct _blox_Sequence_WaitTemperatureBoundary {
    uint16_t target;
    int32_t value;
/* @@protoc_insertion_point(struct:blox_Sequence_WaitTemperatureBoundary) */
} blox_Sequence_WaitTemperatureBoundary;

typedef struct _blox_Sequence_WaitUntil {
    uint32_t time;
/* @@protoc_insertion_point(struct:blox_Sequence_WaitUntil) */
} blox_Sequence_WaitUntil;

typedef struct _blox_Sequence_Instruction {
    pb_size_t which_instruction_oneof;
    union {
        blox_Sequence_Restart RESTART;
        blox_Sequence_EnableDisable ENABLE;
        blox_Sequence_EnableDisable DISABLE;
        blox_Sequence_WaitDuration WAIT_DURATION;
        blox_Sequence_WaitUntil WAIT_UNTIL;
        blox_Sequence_WaitTemperature WAIT_TEMPERATURE_BETWEEN;
        blox_Sequence_WaitTemperatureBoundary WAIT_TEMPERATURE_ABOVE;
        blox_Sequence_WaitTemperatureBoundary WAIT_TEMPERATURE_BELOW;
        blox_Sequence_SetSetpoint SET_SETPOINT;
        blox_Sequence_WaitSetpoint WAIT_SETPOINT;
        blox_Sequence_SetDigital SET_DIGITAL;
        blox_Sequence_WaitDigital WAIT_DIGITAL;
        blox_Sequence_SetPwm SET_PWM;
        blox_Sequence_WaitPwm WAIT_PWM;
        blox_Sequence_StartWaitProfile START_PROFILE;
        blox_Sequence_StartWaitProfile WAIT_PROFILE;
        blox_Sequence_StartWaitSequence START_SEQUENCE;
        blox_Sequence_StartWaitSequence WAIT_SEQUENCE;
    } instruction_oneof;
/* @@protoc_insertion_point(struct:blox_Sequence_Instruction) */
} blox_Sequence_Instruction;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Sequence_Restart_init_default       {0}
#define blox_Sequence_EnableDisable_init_default {0}
#define blox_Sequence_WaitDuration_init_default  {0}
#define blox_Sequence_WaitUntil_init_default     {0}
#define blox_Sequence_WaitTemperature_init_default {0, 0, 0}
#define blox_Sequence_WaitTemperatureBoundary_init_default {0, 0}
#define blox_Sequence_SetSetpoint_init_default   {0, 0}
#define blox_Sequence_WaitSetpoint_init_default  {0, 0}
#define blox_Sequence_SetDigital_init_default    {0, _blox_IoArray_DigitalState_MIN}
#define blox_Sequence_WaitDigital_init_default   {0}
#define blox_Sequence_SetPwm_init_default        {0, 0}
#define blox_Sequence_WaitPwm_init_default       {0, 0}
#define blox_Sequence_StartWaitProfile_init_default {0}
#define blox_Sequence_StartWaitSequence_init_default {0}
#define blox_Sequence_Instruction_init_default   {0, {blox_Sequence_Restart_init_default}}
#define blox_Sequence_InstructionReset_init_default {0, 0}
#define blox_Sequence_Block_init_default         {0, {{NULL}, NULL}, 0, 0, 0, 0, 0, _blox_Sequence_SequenceStatus_MIN, _blox_Sequence_SequenceError_MIN}
#define blox_Sequence_Restart_init_zero          {0}
#define blox_Sequence_EnableDisable_init_zero    {0}
#define blox_Sequence_WaitDuration_init_zero     {0}
#define blox_Sequence_WaitUntil_init_zero        {0}
#define blox_Sequence_WaitTemperature_init_zero  {0, 0, 0}
#define blox_Sequence_WaitTemperatureBoundary_init_zero {0, 0}
#define blox_Sequence_SetSetpoint_init_zero      {0, 0}
#define blox_Sequence_WaitSetpoint_init_zero     {0, 0}
#define blox_Sequence_SetDigital_init_zero       {0, _blox_IoArray_DigitalState_MIN}
#define blox_Sequence_WaitDigital_init_zero      {0}
#define blox_Sequence_SetPwm_init_zero           {0, 0}
#define blox_Sequence_WaitPwm_init_zero          {0, 0}
#define blox_Sequence_StartWaitProfile_init_zero {0}
#define blox_Sequence_StartWaitSequence_init_zero {0}
#define blox_Sequence_Instruction_init_zero      {0, {blox_Sequence_Restart_init_zero}}
#define blox_Sequence_InstructionReset_init_zero {0, 0}
#define blox_Sequence_Block_init_zero            {0, {{NULL}, NULL}, 0, 0, 0, 0, 0, _blox_Sequence_SequenceStatus_MIN, _blox_Sequence_SequenceError_MIN}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Sequence_Block_enabled_tag          1
#define blox_Sequence_Block_instructions_tag     2
#define blox_Sequence_Block_overrideState_tag    3
#define blox_Sequence_Block_activeInstruction_tag 4
#define blox_Sequence_Block_activeInstructionStartedAt_tag 5
#define blox_Sequence_Block_disabledAt_tag       6
#define blox_Sequence_Block_disabledDuration_tag 7
#define blox_Sequence_Block_status_tag           8
#define blox_Sequence_Block_error_tag            9
#define blox_Sequence_EnableDisable_target_tag   1
#define blox_Sequence_InstructionReset_activeInstruction_tag 1
#define blox_Sequence_InstructionReset_activeInstructionStartedAt_tag 2
#define blox_Sequence_SetDigital_target_tag      1
#define blox_Sequence_SetDigital_setting_tag     2
#define blox_Sequence_SetPwm_target_tag          1
#define blox_Sequence_SetPwm_setting_tag         2
#define blox_Sequence_SetSetpoint_target_tag     1
#define blox_Sequence_SetSetpoint_setting_tag    2
#define blox_Sequence_StartWaitProfile_target_tag 1
#define blox_Sequence_StartWaitSequence_target_tag 1
#define blox_Sequence_WaitDigital_target_tag     1
#define blox_Sequence_WaitDuration_duration_tag  1
#define blox_Sequence_WaitPwm_target_tag         1
#define blox_Sequence_WaitPwm_precision_tag      2
#define blox_Sequence_WaitSetpoint_target_tag    1
#define blox_Sequence_WaitSetpoint_precision_tag 2
#define blox_Sequence_WaitTemperature_target_tag 1
#define blox_Sequence_WaitTemperature_lower_tag  2
#define blox_Sequence_WaitTemperature_upper_tag  3
#define blox_Sequence_WaitTemperatureBoundary_target_tag 1
#define blox_Sequence_WaitTemperatureBoundary_value_tag 2
#define blox_Sequence_WaitUntil_time_tag         1
#define blox_Sequence_Instruction_RESTART_tag    1
#define blox_Sequence_Instruction_ENABLE_tag     2
#define blox_Sequence_Instruction_DISABLE_tag    3
#define blox_Sequence_Instruction_WAIT_DURATION_tag 4
#define blox_Sequence_Instruction_WAIT_UNTIL_tag 5
#define blox_Sequence_Instruction_WAIT_TEMPERATURE_BETWEEN_tag 6
#define blox_Sequence_Instruction_WAIT_TEMPERATURE_ABOVE_tag 7
#define blox_Sequence_Instruction_WAIT_TEMPERATURE_BELOW_tag 8
#define blox_Sequence_Instruction_SET_SETPOINT_tag 9
#define blox_Sequence_Instruction_WAIT_SETPOINT_tag 10
#define blox_Sequence_Instruction_SET_DIGITAL_tag 11
#define blox_Sequence_Instruction_WAIT_DIGITAL_tag 12
#define blox_Sequence_Instruction_SET_PWM_tag    13
#define blox_Sequence_Instruction_WAIT_PWM_tag   14
#define blox_Sequence_Instruction_START_PROFILE_tag 15
#define blox_Sequence_Instruction_WAIT_PROFILE_tag 16
#define blox_Sequence_Instruction_START_SEQUENCE_tag 17
#define blox_Sequence_Instruction_WAIT_SEQUENCE_tag 18

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Sequence_Restart_fields[1];
extern const pb_field_t blox_Sequence_EnableDisable_fields[2];
extern const pb_field_t blox_Sequence_WaitDuration_fields[2];
extern const pb_field_t blox_Sequence_WaitUntil_fields[2];
extern const pb_field_t blox_Sequence_WaitTemperature_fields[4];
extern const pb_field_t blox_Sequence_WaitTemperatureBoundary_fields[3];
extern const pb_field_t blox_Sequence_SetSetpoint_fields[3];
extern const pb_field_t blox_Sequence_WaitSetpoint_fields[3];
extern const pb_field_t blox_Sequence_SetDigital_fields[3];
extern const pb_field_t blox_Sequence_WaitDigital_fields[2];
extern const pb_field_t blox_Sequence_SetPwm_fields[3];
extern const pb_field_t blox_Sequence_WaitPwm_fields[3];
extern const pb_field_t blox_Sequence_StartWaitProfile_fields[2];
extern const pb_field_t blox_Sequence_StartWaitSequence_fields[2];
extern const pb_field_t blox_Sequence_Instruction_fields[19];
extern const pb_field_t blox_Sequence_InstructionReset_fields[3];
extern const pb_field_t blox_Sequence_Block_fields[10];

/* Maximum encoded size of messages (where known) */
#define blox_Sequence_Restart_size               0
#define blox_Sequence_EnableDisable_size         6
#define blox_Sequence_WaitDuration_size          6
#define blox_Sequence_WaitUntil_size             6
#define blox_Sequence_WaitTemperature_size       18
#define blox_Sequence_WaitTemperatureBoundary_size 12
#define blox_Sequence_SetSetpoint_size           12
#define blox_Sequence_WaitSetpoint_size          12
#define blox_Sequence_SetDigital_size            8
#define blox_Sequence_WaitDigital_size           6
#define blox_Sequence_SetPwm_size                12
#define blox_Sequence_WaitPwm_size               12
#define blox_Sequence_StartWaitProfile_size      6
#define blox_Sequence_StartWaitSequence_size     6
#define blox_Sequence_Instruction_size           20
#define blox_Sequence_InstructionReset_size      12
/* blox_Sequence_Block_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SEQUENCE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
