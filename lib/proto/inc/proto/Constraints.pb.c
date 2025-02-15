/* Automatically generated nanopb constant definitions */

#include "Constraints.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Constraints_Balanced_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Constraints_Balanced, balancerId, balancerId, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_Constraints_Balanced, granted, balancerId, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_Constraints_Balanced, id, granted, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Constraints_Mutexed_fields[5] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Constraints_Mutexed, mutexId, mutexId, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_Constraints_Mutexed, extraHoldTime, mutexId, 0),
    PB_FIELD(  3, BOOL    , SINGULAR, STATIC  , OTHER, blox_Constraints_Mutexed, hasCustomHoldTime, extraHoldTime, 0),
    PB_FIELD(  4, BOOL    , SINGULAR, STATIC  , OTHER, blox_Constraints_Mutexed, hasLock, hasCustomHoldTime, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Constraints_AnalogConstraint_fields[5] = {
    PB_ONEOF_FIELD(constraint,   1, SINT32  , ONEOF, STATIC  , FIRST, blox_Constraints_AnalogConstraint, min, min, 0),
    PB_ONEOF_FIELD(constraint,   2, SINT32  , ONEOF, STATIC  , UNION, blox_Constraints_AnalogConstraint, max, max, 0),
    PB_ONEOF_FIELD(constraint,   3, MESSAGE , ONEOF, STATIC  , UNION, blox_Constraints_AnalogConstraint, balanced, balanced, &blox_Constraints_Balanced_fields),
    PB_FIELD(100, BOOL    , SINGULAR, STATIC  , OTHER, blox_Constraints_AnalogConstraint, limiting, constraint.balanced, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Constraints_AnalogConstraints_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, STATIC  , FIRST, blox_Constraints_AnalogConstraints, constraints, constraints, &blox_Constraints_AnalogConstraint_fields),
    PB_LAST_FIELD
};

const pb_field_t blox_Constraints_DigitalConstraint_fields[8] = {
    PB_ONEOF_FIELD(constraint,   1, UINT32  , ONEOF, STATIC  , FIRST, blox_Constraints_DigitalConstraint, minOff, minOff, 0),
    PB_ONEOF_FIELD(constraint,   2, UINT32  , ONEOF, STATIC  , UNION, blox_Constraints_DigitalConstraint, minOn, minOn, 0),
    PB_ONEOF_FIELD(constraint,   3, UINT32  , ONEOF, STATIC  , UNION, blox_Constraints_DigitalConstraint, mutex, mutex, 0),
    PB_ONEOF_FIELD(constraint,   4, MESSAGE , ONEOF, STATIC  , UNION, blox_Constraints_DigitalConstraint, mutexed, mutexed, &blox_Constraints_Mutexed_fields),
    PB_ONEOF_FIELD(constraint,   5, UINT32  , ONEOF, STATIC  , UNION, blox_Constraints_DigitalConstraint, delayedOff, delayedOff, 0),
    PB_ONEOF_FIELD(constraint,   6, UINT32  , ONEOF, STATIC  , UNION, blox_Constraints_DigitalConstraint, delayedOn, delayedOn, 0),
    PB_FIELD(101, UINT32  , SINGULAR, STATIC  , OTHER, blox_Constraints_DigitalConstraint, remaining, constraint.delayedOn, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Constraints_DigitalConstraints_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, STATIC  , FIRST, blox_Constraints_DigitalConstraints, constraints, constraints, &blox_Constraints_DigitalConstraint_fields),
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
PB_STATIC_ASSERT((pb_membersize(blox_Constraints_AnalogConstraint, constraint.balanced) < 65536 && pb_membersize(blox_Constraints_AnalogConstraints, constraints[0]) < 65536 && pb_membersize(blox_Constraints_DigitalConstraint, constraint.mutexed) < 65536 && pb_membersize(blox_Constraints_DigitalConstraints, constraints[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_Constraints_Balanced_blox_Constraints_Mutexed_blox_Constraints_AnalogConstraint_blox_Constraints_AnalogConstraints_blox_Constraints_DigitalConstraint_blox_Constraints_DigitalConstraints)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_Constraints_AnalogConstraint, constraint.balanced) < 256 && pb_membersize(blox_Constraints_AnalogConstraints, constraints[0]) < 256 && pb_membersize(blox_Constraints_DigitalConstraint, constraint.mutexed) < 256 && pb_membersize(blox_Constraints_DigitalConstraints, constraints[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_Constraints_Balanced_blox_Constraints_Mutexed_blox_Constraints_AnalogConstraint_blox_Constraints_AnalogConstraints_blox_Constraints_DigitalConstraint_blox_Constraints_DigitalConstraints)
#endif


/* @@protoc_insertion_point(eof) */
