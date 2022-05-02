/* Automatically generated nanopb header */

#ifndef PB_BLOX_STEPPER_STEPPER_PB_H_INCLUDED
#define PB_BLOX_STEPPER_STEPPER_PB_H_INCLUDED
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
typedef enum _blox_Stepper_Instruction {
    blox_Stepper_Instruction_NOOP = 0,
    blox_Stepper_Instruction_RESTART = 1,
    blox_Stepper_Instruction_TIME_WAIT_DURATION = 2,
    blox_Stepper_Instruction_TIME_WAIT_ABSOLUTE = 3,
    blox_Stepper_Instruction_PROFILE_ENABLE = 10,
    blox_Stepper_Instruction_PROFILE_RESET = 11,
    blox_Stepper_Instruction_PROFILE_WAIT = 12,
    blox_Stepper_Instruction_SETPOINT_ENABLE = 20,
    blox_Stepper_Instruction_SETPOINT_SETTING = 21,
    blox_Stepper_Instruction_SETPOINT_WAIT = 22,
    blox_Stepper_Instruction_DIGITAL_ENABLE = 30,
    blox_Stepper_Instruction_DIGITAL_SETTING = 31,
    blox_Stepper_Instruction_DIGITAL_WAIT = 32,
    blox_Stepper_Instruction_ANALOG_ENABLE = 40,
    blox_Stepper_Instruction_ANALOG_SETTING = 41,
    blox_Stepper_Instruction_ANALOG_WAIT = 42
} blox_Stepper_Instruction;
#define _blox_Stepper_Instruction_MIN blox_Stepper_Instruction_NOOP
#define _blox_Stepper_Instruction_MAX blox_Stepper_Instruction_ANALOG_WAIT
#define _blox_Stepper_Instruction_ARRAYSIZE ((blox_Stepper_Instruction)(blox_Stepper_Instruction_ANALOG_WAIT+1))

/* Struct definitions */
typedef struct _blox_Stepper_Block {
    bool enabled;
    uint16_t activeStep;
    uint32_t activeStepStartedAt;
    pb_callback_t steps;
/* @@protoc_insertion_point(struct:blox_Stepper_Block) */
} blox_Stepper_Block;

typedef struct _blox_Stepper_Step {
    blox_Stepper_Instruction instruction;
    pb_size_t which_target_oneof;
    union {
        uint16_t setpointId;
        uint16_t digitalId;
        uint16_t analogId;
        uint16_t profileId;
    } target_oneof;
    pb_size_t which_value_oneof;
    union {
        bool booleanValue;
        uint32_t timeValue;
        int32_t setpointValue;
        int32_t setpointOffsetValue;
        blox_IoArray_DigitalState digitalValue;
        int32_t analogValue;
    } value_oneof;
/* @@protoc_insertion_point(struct:blox_Stepper_Step) */
} blox_Stepper_Step;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Stepper_Step_init_default           {_blox_Stepper_Instruction_MIN, 0, {0}, 0, {0}}
#define blox_Stepper_Block_init_default          {0, 0, 0, {{NULL}, NULL}}
#define blox_Stepper_Step_init_zero              {_blox_Stepper_Instruction_MIN, 0, {0}, 0, {0}}
#define blox_Stepper_Block_init_zero             {0, 0, 0, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Stepper_Block_enabled_tag           1
#define blox_Stepper_Block_activeStep_tag        2
#define blox_Stepper_Block_activeStepStartedAt_tag 3
#define blox_Stepper_Block_steps_tag             4
#define blox_Stepper_Step_setpointId_tag         2
#define blox_Stepper_Step_digitalId_tag          3
#define blox_Stepper_Step_analogId_tag           4
#define blox_Stepper_Step_profileId_tag          5
#define blox_Stepper_Step_booleanValue_tag       10
#define blox_Stepper_Step_timeValue_tag          11
#define blox_Stepper_Step_setpointValue_tag      12
#define blox_Stepper_Step_setpointOffsetValue_tag 13
#define blox_Stepper_Step_digitalValue_tag       14
#define blox_Stepper_Step_analogValue_tag        15
#define blox_Stepper_Step_instruction_tag        1

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Stepper_Step_fields[12];
extern const pb_field_t blox_Stepper_Block_fields[5];

/* Maximum encoded size of messages (where known) */
#define blox_Stepper_Step_size                   14
/* blox_Stepper_Block_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define STEPPER_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
