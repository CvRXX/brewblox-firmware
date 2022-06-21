/* Automatically generated nanopb constant definitions */

#include "ActuatorAnalogMock.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_ActuatorAnalogMock_Block_fields[9] = {
    PB_FIELD(  1, SINT32  , SINGULAR, STATIC  , FIRST, blox_ActuatorAnalogMock_Block, setting, setting, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_ActuatorAnalogMock_Block, value, setting, 0),
    PB_FIELD(  4, SINT32  , SINGULAR, STATIC  , OTHER, blox_ActuatorAnalogMock_Block, minSetting, value, 0),
    PB_FIELD(  5, SINT32  , SINGULAR, STATIC  , OTHER, blox_ActuatorAnalogMock_Block, maxSetting, minSetting, 0),
    PB_FIELD(  6, SINT32  , SINGULAR, STATIC  , OTHER, blox_ActuatorAnalogMock_Block, minValue, maxSetting, 0),
    PB_FIELD(  7, SINT32  , SINGULAR, STATIC  , OTHER, blox_ActuatorAnalogMock_Block, maxValue, minValue, 0),
    PB_FIELD(  8, MESSAGE , SINGULAR, STATIC  , OTHER, blox_ActuatorAnalogMock_Block, constrainedBy, maxValue, &blox_Constraints_AnalogConstraints_fields),
    PB_FIELD(  9, SINT32  , SINGULAR, STATIC  , OTHER, blox_ActuatorAnalogMock_Block, desiredSetting, constrainedBy, 0),
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
PB_STATIC_ASSERT((pb_membersize(blox_ActuatorAnalogMock_Block, constrainedBy) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_ActuatorAnalogMock_Block)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_ActuatorAnalogMock_Block, constrainedBy) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_ActuatorAnalogMock_Block)
#endif


/* @@protoc_insertion_point(eof) */
