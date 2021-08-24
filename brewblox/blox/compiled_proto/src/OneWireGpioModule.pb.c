/* Automatically generated nanopb constant definitions */

#include "OneWireGpioModule.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_GpioModuleChannel_fields[5] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_GpioModuleChannel, id, id, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, blox_GpioModuleChannel, deviceType, id, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_GpioModuleChannel, pinsMask, deviceType, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_GpioModuleChannel, width, pinsMask, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_OneWireGpioModule_fields[15] = {
    PB_FIELD(  1, MESSAGE , REPEATED, STATIC  , FIRST, blox_OneWireGpioModule, channels, channels, &blox_GpioModuleChannel_fields),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, modulePosition, channels, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, moduleStatus, modulePosition, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, pullUpDesired, moduleStatus, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, pullUpStatus, pullUpDesired, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, pullUpWhenActive, pullUpStatus, 0),
    PB_FIELD(  7, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, pullUpWhenInactive, pullUpWhenActive, 0),
    PB_FIELD(  8, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, pullDownDesired, pullUpWhenInactive, 0),
    PB_FIELD(  9, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, pullDownStatus, pullDownDesired, 0),
    PB_FIELD( 10, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, pullDownWhenActive, pullDownStatus, 0),
    PB_FIELD( 11, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, pullDownWhenInactive, pullDownWhenActive, 0),
    PB_FIELD( 12, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, overCurrent, pullDownWhenInactive, 0),
    PB_FIELD( 13, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, openLoad, overCurrent, 0),
    PB_FIELD( 32, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, moduleStatusClear, openLoad, 0),
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
PB_STATIC_ASSERT((pb_membersize(blox_OneWireGpioModule, channels[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_GpioModuleChannel_blox_OneWireGpioModule)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_OneWireGpioModule, channels[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_GpioModuleChannel_blox_OneWireGpioModule)
#endif


/* @@protoc_insertion_point(eof) */
