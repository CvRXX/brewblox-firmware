/* Automatically generated nanopb constant definitions */

#include "OneWireGpioModule.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_OneWireGpioModule_GpioModuleChannel_fields[8] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_OneWireGpioModule_GpioModuleChannel, id, id, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_GpioModuleChannel, deviceType, id, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_GpioModuleChannel, pinsMask, deviceType, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_GpioModuleChannel, width, pinsMask, 0),
    PB_FIELD(  5, STRING  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_GpioModuleChannel, name, width, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_GpioModuleChannel, capabilities, name, 0),
    PB_FIELD(  7, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_GpioModuleChannel, claimedBy, capabilities, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_OneWireGpioModule_Block_fields[17] = {
    PB_FIELD(  1, MESSAGE , REPEATED, STATIC  , FIRST, blox_OneWireGpioModule_Block, channels, channels, &blox_OneWireGpioModule_GpioModuleChannel_fields),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, modulePosition, channels, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, moduleStatus, modulePosition, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, pullUpDesired, moduleStatus, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, pullUpStatus, pullUpDesired, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, pullUpWhenActive, pullUpStatus, 0),
    PB_FIELD(  7, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, pullUpWhenInactive, pullUpWhenActive, 0),
    PB_FIELD(  8, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, pullDownDesired, pullUpWhenInactive, 0),
    PB_FIELD(  9, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, pullDownStatus, pullDownDesired, 0),
    PB_FIELD( 10, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, pullDownWhenActive, pullDownStatus, 0),
    PB_FIELD( 11, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, pullDownWhenInactive, pullDownWhenActive, 0),
    PB_FIELD( 12, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, overCurrent, pullDownWhenInactive, 0),
    PB_FIELD( 13, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, openLoad, overCurrent, 0),
    PB_FIELD( 14, BOOL    , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, useExternalPower, openLoad, 0),
    PB_FIELD( 32, BOOL    , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, clearFaults, useExternalPower, 0),
    PB_FIELD( 90, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule_Block, moduleStatusClear, clearFaults, 0),
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
PB_STATIC_ASSERT((pb_membersize(blox_OneWireGpioModule_Block, channels[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_OneWireGpioModule_GpioModuleChannel_blox_OneWireGpioModule_Block)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_OneWireGpioModule_Block, channels[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_OneWireGpioModule_GpioModuleChannel_blox_OneWireGpioModule_Block)
#endif


/* @@protoc_insertion_point(eof) */
