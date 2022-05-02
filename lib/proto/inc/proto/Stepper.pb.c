/* Automatically generated nanopb constant definitions */

#include "Stepper.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Stepper_Step_fields[12] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, blox_Stepper_Step, instruction, instruction, 0),
    PB_ONEOF_FIELD(target_oneof,   2, UINT32  , ONEOF, STATIC  , OTHER, blox_Stepper_Step, setpointId, instruction, 0),
    PB_ONEOF_FIELD(target_oneof,   3, UINT32  , ONEOF, STATIC  , UNION, blox_Stepper_Step, digitalId, instruction, 0),
    PB_ONEOF_FIELD(target_oneof,   4, UINT32  , ONEOF, STATIC  , UNION, blox_Stepper_Step, analogId, instruction, 0),
    PB_ONEOF_FIELD(target_oneof,   5, UINT32  , ONEOF, STATIC  , UNION, blox_Stepper_Step, profileId, instruction, 0),
    PB_ONEOF_FIELD(value_oneof,  10, BOOL    , ONEOF, STATIC  , OTHER, blox_Stepper_Step, booleanValue, target_oneof.profileId, 0),
    PB_ONEOF_FIELD(value_oneof,  11, UINT32  , ONEOF, STATIC  , UNION, blox_Stepper_Step, timeValue, target_oneof.profileId, 0),
    PB_ONEOF_FIELD(value_oneof,  12, SINT32  , ONEOF, STATIC  , UNION, blox_Stepper_Step, setpointValue, target_oneof.profileId, 0),
    PB_ONEOF_FIELD(value_oneof,  13, SINT32  , ONEOF, STATIC  , UNION, blox_Stepper_Step, setpointOffsetValue, target_oneof.profileId, 0),
    PB_ONEOF_FIELD(value_oneof,  14, ENUM    , ONEOF, STATIC  , UNION, blox_Stepper_Step, digitalValue, target_oneof.profileId, 0),
    PB_ONEOF_FIELD(value_oneof,  15, SINT32  , ONEOF, STATIC  , UNION, blox_Stepper_Step, analogValue, target_oneof.profileId, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Stepper_Block_fields[5] = {
    PB_FIELD(  1, BOOL    , SINGULAR, STATIC  , FIRST, blox_Stepper_Block, enabled, enabled, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_Stepper_Block, activeStep, enabled, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_Stepper_Block, activeStepStartedAt, activeStep, 0),
    PB_FIELD(  4, MESSAGE , REPEATED, CALLBACK, OTHER, blox_Stepper_Block, steps, activeStepStartedAt, &blox_Stepper_Step_fields),
    PB_LAST_FIELD
};



/* @@protoc_insertion_point(eof) */
