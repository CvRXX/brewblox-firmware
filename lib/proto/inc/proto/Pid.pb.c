/* Automatically generated nanopb constant definitions */

#include "Pid.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Pid_Block_fields[24] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Pid_Block, inputId, inputId, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, outputId, inputId, 0),
    PB_FIELD(  5, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, inputValue, outputId, 0),
    PB_FIELD(  6, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, inputSetting, inputValue, 0),
    PB_FIELD(  7, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, outputValue, inputSetting, 0),
    PB_FIELD(  8, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, outputSetting, outputValue, 0),
    PB_FIELD( 11, BOOL    , SINGULAR, STATIC  , OTHER, blox_Pid_Block, enabled, outputSetting, 0),
    PB_FIELD( 12, BOOL    , SINGULAR, STATIC  , OTHER, blox_Pid_Block, active, enabled, 0),
    PB_FIELD( 13, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, kp, active, 0),
    PB_FIELD( 14, UINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, ti, kp, 0),
    PB_FIELD( 15, UINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, td, ti, 0),
    PB_FIELD( 16, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, p, td, 0),
    PB_FIELD( 17, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, i, p, 0),
    PB_FIELD( 18, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, d, i, 0),
    PB_FIELD( 19, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, error, d, 0),
    PB_FIELD( 20, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, integral, error, 0),
    PB_FIELD( 21, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, derivative, integral, 0),
    PB_FIELD( 22, UINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, drivenOutputId, derivative, 0),
    PB_FIELD( 23, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, integralReset, drivenOutputId, 0),
    PB_FIELD( 24, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, boilPointAdjust, integralReset, 0),
    PB_FIELD( 25, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid_Block, boilMinOutput, boilPointAdjust, 0),
    PB_FIELD( 26, BOOL    , SINGULAR, STATIC  , OTHER, blox_Pid_Block, boilModeActive, boilMinOutput, 0),
    PB_FIELD( 27, UENUM   , SINGULAR, STATIC  , OTHER, blox_Pid_Block, derivativeFilter, boilModeActive, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
