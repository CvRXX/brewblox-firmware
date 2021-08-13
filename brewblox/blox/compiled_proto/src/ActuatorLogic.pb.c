/* Automatically generated nanopb constant definitions */

#include "ActuatorLogic.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Compare_fields[1] = {
    PB_LAST_FIELD
};

const pb_field_t blox_DigitalCompare_fields[5] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, blox_DigitalCompare, op, op, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, blox_DigitalCompare, result, op, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_DigitalCompare, id, result, 0),
    PB_FIELD(  4, UENUM   , SINGULAR, STATIC  , OTHER, blox_DigitalCompare, rhs, id, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_AnalogCompare_fields[5] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, blox_AnalogCompare, op, op, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, blox_AnalogCompare, result, op, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_AnalogCompare, id, result, 0),
    PB_FIELD(  4, SINT32  , SINGULAR, STATIC  , OTHER, blox_AnalogCompare, rhs, id, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_ActuatorLogic_fields[9] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_ActuatorLogic, targetId, targetId, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_ActuatorLogic, drivenTargetId, targetId, 0),
    PB_FIELD(  3, BOOL    , SINGULAR, STATIC  , OTHER, blox_ActuatorLogic, enabled, drivenTargetId, 0),
    PB_FIELD(  4, UENUM   , SINGULAR, STATIC  , OTHER, blox_ActuatorLogic, result, enabled, 0),
    PB_FIELD(  5, STRING  , SINGULAR, STATIC  , OTHER, blox_ActuatorLogic, expression, result, 0),
    PB_FIELD(  6, MESSAGE , REPEATED, STATIC  , OTHER, blox_ActuatorLogic, digital, expression, &blox_DigitalCompare_fields),
    PB_FIELD(  7, MESSAGE , REPEATED, STATIC  , OTHER, blox_ActuatorLogic, analog, digital, &blox_AnalogCompare_fields),
    PB_FIELD(  8, UINT32  , SINGULAR, STATIC  , OTHER, blox_ActuatorLogic, errorPos, analog, 0),
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
PB_STATIC_ASSERT((pb_membersize(blox_ActuatorLogic, digital[0]) < 65536 && pb_membersize(blox_ActuatorLogic, analog[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_Compare_blox_DigitalCompare_blox_AnalogCompare_blox_ActuatorLogic)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_ActuatorLogic, digital[0]) < 256 && pb_membersize(blox_ActuatorLogic, analog[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_Compare_blox_DigitalCompare_blox_AnalogCompare_blox_ActuatorLogic)
#endif


/* @@protoc_insertion_point(eof) */
