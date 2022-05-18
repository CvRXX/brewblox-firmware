/* Automatically generated nanopb constant definitions */

#include "Sequence.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Sequence_Restart_fields[1] = {
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_EnableDisable_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_EnableDisable, target, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_WaitDuration_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_WaitDuration, duration, duration, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_WaitUntil_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_WaitUntil, time, time, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_WaitTemperature_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_WaitTemperature, target, target, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_WaitTemperature, lower, target, 0),
    PB_FIELD(  3, SINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_WaitTemperature, upper, lower, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_WaitTemperatureBoundary_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_WaitTemperatureBoundary, target, target, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_WaitTemperatureBoundary, value, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_SetSetpoint_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_SetSetpoint, target, target, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_SetSetpoint, setting, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_WaitSetpoint_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_WaitSetpoint, target, target, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_WaitSetpoint, precision, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_SetDigital_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_SetDigital, target, target, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, blox_Sequence_SetDigital, setting, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_WaitDigital_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_WaitDigital, target, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_SetPwm_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_SetPwm, target, target, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_SetPwm, setting, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_WaitPwm_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_WaitPwm, target, target, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_WaitPwm, precision, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_StartWaitProfile_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_StartWaitProfile, target, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_StartWaitSequence_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_StartWaitSequence, target, target, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_Instruction_fields[19] = {
    PB_ONEOF_FIELD(instruction_oneof,   1, MESSAGE , ONEOF, STATIC  , FIRST, blox_Sequence_Instruction, RESTART, RESTART, &blox_Sequence_Restart_fields),
    PB_ONEOF_FIELD(instruction_oneof,   2, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, ENABLE, ENABLE, &blox_Sequence_EnableDisable_fields),
    PB_ONEOF_FIELD(instruction_oneof,   3, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, DISABLE, DISABLE, &blox_Sequence_EnableDisable_fields),
    PB_ONEOF_FIELD(instruction_oneof,   4, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_DURATION, WAIT_DURATION, &blox_Sequence_WaitDuration_fields),
    PB_ONEOF_FIELD(instruction_oneof,   5, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_UNTIL, WAIT_UNTIL, &blox_Sequence_WaitUntil_fields),
    PB_ONEOF_FIELD(instruction_oneof,   6, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_TEMPERATURE_BETWEEN, WAIT_TEMPERATURE_BETWEEN, &blox_Sequence_WaitTemperature_fields),
    PB_ONEOF_FIELD(instruction_oneof,   7, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_TEMPERATURE_ABOVE, WAIT_TEMPERATURE_ABOVE, &blox_Sequence_WaitTemperatureBoundary_fields),
    PB_ONEOF_FIELD(instruction_oneof,   8, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_TEMPERATURE_BELOW, WAIT_TEMPERATURE_BELOW, &blox_Sequence_WaitTemperatureBoundary_fields),
    PB_ONEOF_FIELD(instruction_oneof,   9, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, SET_SETPOINT, SET_SETPOINT, &blox_Sequence_SetSetpoint_fields),
    PB_ONEOF_FIELD(instruction_oneof,  10, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_SETPOINT, WAIT_SETPOINT, &blox_Sequence_WaitSetpoint_fields),
    PB_ONEOF_FIELD(instruction_oneof,  11, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, SET_DIGITAL, SET_DIGITAL, &blox_Sequence_SetDigital_fields),
    PB_ONEOF_FIELD(instruction_oneof,  12, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_DIGITAL, WAIT_DIGITAL, &blox_Sequence_WaitDigital_fields),
    PB_ONEOF_FIELD(instruction_oneof,  13, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, SET_PWM, SET_PWM, &blox_Sequence_SetPwm_fields),
    PB_ONEOF_FIELD(instruction_oneof,  14, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_PWM, WAIT_PWM, &blox_Sequence_WaitPwm_fields),
    PB_ONEOF_FIELD(instruction_oneof,  15, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, START_PROFILE, START_PROFILE, &blox_Sequence_StartWaitProfile_fields),
    PB_ONEOF_FIELD(instruction_oneof,  16, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_PROFILE, WAIT_PROFILE, &blox_Sequence_StartWaitProfile_fields),
    PB_ONEOF_FIELD(instruction_oneof,  17, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, START_SEQUENCE, START_SEQUENCE, &blox_Sequence_StartWaitSequence_fields),
    PB_ONEOF_FIELD(instruction_oneof,  18, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, WAIT_SEQUENCE, WAIT_SEQUENCE, &blox_Sequence_StartWaitSequence_fields),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_InstructionReset_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Sequence_InstructionReset, activeInstruction, activeInstruction, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_InstructionReset, activeInstructionStartedAt, activeInstruction, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Sequence_Block_fields[10] = {
    PB_FIELD(  1, BOOL    , SINGULAR, STATIC  , FIRST, blox_Sequence_Block, enabled, enabled, 0),
    PB_FIELD(  2, MESSAGE , REPEATED, CALLBACK, OTHER, blox_Sequence_Block, instructions, enabled, &blox_Sequence_Instruction_fields),
    PB_ONEOF_FIELD(reset_oneof,   3, MESSAGE , ONEOF, STATIC  , OTHER, blox_Sequence_Block, reset, instructions, &blox_Sequence_InstructionReset_fields),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_Block, activeInstruction, reset_oneof.reset, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_Block, activeInstructionStartedAt, activeInstruction, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_Block, disabledAt, activeInstructionStartedAt, 0),
    PB_FIELD(  7, UINT32  , SINGULAR, STATIC  , OTHER, blox_Sequence_Block, disabledDuration, disabledAt, 0),
    PB_FIELD(  8, UENUM   , SINGULAR, STATIC  , OTHER, blox_Sequence_Block, status, disabledDuration, 0),
    PB_FIELD(  9, UENUM   , SINGULAR, STATIC  , OTHER, blox_Sequence_Block, error, status, 0),
    PB_LAST_FIELD
};




/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_Sequence_Instruction, instruction_oneof.RESTART) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.ENABLE) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.DISABLE) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_DURATION) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_UNTIL) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_TEMPERATURE_BETWEEN) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_TEMPERATURE_ABOVE) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_TEMPERATURE_BELOW) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.SET_SETPOINT) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_SETPOINT) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.SET_DIGITAL) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_DIGITAL) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.SET_PWM) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_PWM) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.START_PROFILE) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_PROFILE) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.START_SEQUENCE) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_SEQUENCE) < 65536 && pb_membersize(blox_Sequence_Block, reset_oneof.reset) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_Sequence_Restart_blox_Sequence_EnableDisable_blox_Sequence_WaitDuration_blox_Sequence_WaitUntil_blox_Sequence_WaitTemperature_blox_Sequence_WaitTemperatureBoundary_blox_Sequence_SetSetpoint_blox_Sequence_WaitSetpoint_blox_Sequence_SetDigital_blox_Sequence_WaitDigital_blox_Sequence_SetPwm_blox_Sequence_WaitPwm_blox_Sequence_StartWaitProfile_blox_Sequence_StartWaitSequence_blox_Sequence_Instruction_blox_Sequence_InstructionReset_blox_Sequence_Block)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_Sequence_Instruction, instruction_oneof.RESTART) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.ENABLE) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.DISABLE) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_DURATION) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_UNTIL) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_TEMPERATURE_BETWEEN) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_TEMPERATURE_ABOVE) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_TEMPERATURE_BELOW) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.SET_SETPOINT) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_SETPOINT) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.SET_DIGITAL) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_DIGITAL) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.SET_PWM) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_PWM) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.START_PROFILE) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_PROFILE) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.START_SEQUENCE) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.WAIT_SEQUENCE) < 256 && pb_membersize(blox_Sequence_Block, reset_oneof.reset) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_Sequence_Restart_blox_Sequence_EnableDisable_blox_Sequence_WaitDuration_blox_Sequence_WaitUntil_blox_Sequence_WaitTemperature_blox_Sequence_WaitTemperatureBoundary_blox_Sequence_SetSetpoint_blox_Sequence_WaitSetpoint_blox_Sequence_SetDigital_blox_Sequence_WaitDigital_blox_Sequence_SetPwm_blox_Sequence_WaitPwm_blox_Sequence_StartWaitProfile_blox_Sequence_StartWaitSequence_blox_Sequence_Instruction_blox_Sequence_InstructionReset_blox_Sequence_Block)
#endif


/* @@protoc_insertion_point(eof) */
