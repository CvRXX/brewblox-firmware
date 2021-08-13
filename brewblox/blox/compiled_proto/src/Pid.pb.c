/* Automatically generated nanopb constant definitions */

#include "Pid.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Pid_fields[25] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Pid, inputId, inputId, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, outputId, inputId, 0),
    PB_FIELD(  5, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, inputValue, outputId, 0),
    PB_FIELD(  6, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, inputSetting, inputValue, 0),
    PB_FIELD(  7, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, outputValue, inputSetting, 0),
    PB_FIELD(  8, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, outputSetting, outputValue, 0),
    PB_FIELD( 11, BOOL    , SINGULAR, STATIC  , OTHER, blox_Pid, enabled, outputSetting, 0),
    PB_FIELD( 12, BOOL    , SINGULAR, STATIC  , OTHER, blox_Pid, active, enabled, 0),
    PB_FIELD( 13, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, kp, active, 0),
    PB_FIELD( 14, UINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, ti, kp, 0),
    PB_FIELD( 15, UINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, td, ti, 0),
    PB_FIELD( 16, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, p, td, 0),
    PB_FIELD( 17, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, i, p, 0),
    PB_FIELD( 18, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, d, i, 0),
    PB_FIELD( 19, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, error, d, 0),
    PB_FIELD( 20, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, integral, error, 0),
    PB_FIELD( 21, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, derivative, integral, 0),
    PB_FIELD( 22, UINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, drivenOutputId, derivative, 0),
    PB_FIELD( 23, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, integralReset, drivenOutputId, 0),
    PB_FIELD( 24, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, boilPointAdjust, integralReset, 0),
    PB_FIELD( 25, SINT32  , SINGULAR, STATIC  , OTHER, blox_Pid, boilMinOutput, boilPointAdjust, 0),
    PB_FIELD( 26, BOOL    , SINGULAR, STATIC  , OTHER, blox_Pid, boilModeActive, boilMinOutput, 0),
    PB_FIELD( 27, UENUM   , SINGULAR, STATIC  , OTHER, blox_Pid, derivativeFilter, boilModeActive, 0),
    PB_FIELD( 99, UINT32  , REPEATED, STATIC  , OTHER, blox_Pid, strippedFields, derivativeFilter, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
