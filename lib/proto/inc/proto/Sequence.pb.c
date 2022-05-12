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
    PB_ONEOF_FIELD(instruction_oneof,   1, MESSAGE , ONEOF, STATIC  , FIRST, blox_Sequence_Instruction, restart, restart, &blox_Sequence_Restart_fields),
    PB_ONEOF_FIELD(instruction_oneof,   2, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, enable, enable, &blox_Sequence_EnableDisable_fields),
    PB_ONEOF_FIELD(instruction_oneof,   3, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, disable, disable, &blox_Sequence_EnableDisable_fields),
    PB_ONEOF_FIELD(instruction_oneof,   4, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitDuration, waitDuration, &blox_Sequence_WaitDuration_fields),
    PB_ONEOF_FIELD(instruction_oneof,   5, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitUntil, waitUntil, &blox_Sequence_WaitUntil_fields),
    PB_ONEOF_FIELD(instruction_oneof,   6, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitTemperature, waitTemperature, &blox_Sequence_WaitTemperature_fields),
    PB_ONEOF_FIELD(instruction_oneof,   7, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitTemperatureAbove, waitTemperatureAbove, &blox_Sequence_WaitTemperatureBoundary_fields),
    PB_ONEOF_FIELD(instruction_oneof,   8, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitTemperatureBelow, waitTemperatureBelow, &blox_Sequence_WaitTemperatureBoundary_fields),
    PB_ONEOF_FIELD(instruction_oneof,   9, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, setSetpoint, setSetpoint, &blox_Sequence_SetSetpoint_fields),
    PB_ONEOF_FIELD(instruction_oneof,  10, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitSetpoint, waitSetpoint, &blox_Sequence_WaitSetpoint_fields),
    PB_ONEOF_FIELD(instruction_oneof,  11, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, setDigital, setDigital, &blox_Sequence_SetDigital_fields),
    PB_ONEOF_FIELD(instruction_oneof,  12, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitDigital, waitDigital, &blox_Sequence_WaitDigital_fields),
    PB_ONEOF_FIELD(instruction_oneof,  13, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, setPwm, setPwm, &blox_Sequence_SetPwm_fields),
    PB_ONEOF_FIELD(instruction_oneof,  14, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitPwm, waitPwm, &blox_Sequence_WaitPwm_fields),
    PB_ONEOF_FIELD(instruction_oneof,  15, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, startProfile, startProfile, &blox_Sequence_StartWaitProfile_fields),
    PB_ONEOF_FIELD(instruction_oneof,  16, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitProfile, waitProfile, &blox_Sequence_StartWaitProfile_fields),
    PB_ONEOF_FIELD(instruction_oneof,  17, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, startSequence, startSequence, &blox_Sequence_StartWaitSequence_fields),
    PB_ONEOF_FIELD(instruction_oneof,  18, MESSAGE , ONEOF, STATIC  , UNION, blox_Sequence_Instruction, waitSequence, waitSequence, &blox_Sequence_StartWaitSequence_fields),
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
PB_STATIC_ASSERT((pb_membersize(blox_Sequence_Instruction, instruction_oneof.restart) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.enable) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.disable) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitDuration) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitUntil) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitTemperature) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitTemperatureAbove) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitTemperatureBelow) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.setSetpoint) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitSetpoint) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.setDigital) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitDigital) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.setPwm) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitPwm) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.startProfile) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitProfile) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.startSequence) < 65536 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitSequence) < 65536 && pb_membersize(blox_Sequence_Block, reset_oneof.reset) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_Sequence_Restart_blox_Sequence_EnableDisable_blox_Sequence_WaitDuration_blox_Sequence_WaitUntil_blox_Sequence_WaitTemperature_blox_Sequence_WaitTemperatureBoundary_blox_Sequence_SetSetpoint_blox_Sequence_WaitSetpoint_blox_Sequence_SetDigital_blox_Sequence_WaitDigital_blox_Sequence_SetPwm_blox_Sequence_WaitPwm_blox_Sequence_StartWaitProfile_blox_Sequence_StartWaitSequence_blox_Sequence_Instruction_blox_Sequence_InstructionReset_blox_Sequence_Block)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_Sequence_Instruction, instruction_oneof.restart) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.enable) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.disable) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitDuration) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitUntil) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitTemperature) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitTemperatureAbove) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitTemperatureBelow) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.setSetpoint) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitSetpoint) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.setDigital) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitDigital) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.setPwm) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitPwm) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.startProfile) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitProfile) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.startSequence) < 256 && pb_membersize(blox_Sequence_Instruction, instruction_oneof.waitSequence) < 256 && pb_membersize(blox_Sequence_Block, reset_oneof.reset) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_Sequence_Restart_blox_Sequence_EnableDisable_blox_Sequence_WaitDuration_blox_Sequence_WaitUntil_blox_Sequence_WaitTemperature_blox_Sequence_WaitTemperatureBoundary_blox_Sequence_SetSetpoint_blox_Sequence_WaitSetpoint_blox_Sequence_SetDigital_blox_Sequence_WaitDigital_blox_Sequence_SetPwm_blox_Sequence_WaitPwm_blox_Sequence_StartWaitProfile_blox_Sequence_StartWaitSequence_blox_Sequence_Instruction_blox_Sequence_InstructionReset_blox_Sequence_Block)
#endif


/* @@protoc_insertion_point(eof) */
