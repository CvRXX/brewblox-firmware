/* Automatically generated nanopb constant definitions */

#include "OneWireGpioModule.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_GpioChannel_fields[7] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_GpioChannel, id, id, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, blox_GpioChannel, config, id, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_GpioChannel, pins, config, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_GpioChannel, whenActive, pins, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, blox_GpioChannel, whenInactive, whenActive, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_GpioChannel, pwmDuty, whenInactive, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_OneWireGpioModule_fields[7] = {
    PB_FIELD(  1, MESSAGE , REPEATED, STATIC  , FIRST, blox_OneWireGpioModule, channels, channels, &blox_GpioChannel_fields),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, modulePosition, channels, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, status, modulePosition, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, drive, status, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, overCurrent, drive, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_OneWireGpioModule, openLoad, overCurrent, 0),
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
PB_STATIC_ASSERT((pb_membersize(blox_OneWireGpioModule, channels[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_GpioChannel_blox_OneWireGpioModule)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_OneWireGpioModule, channels[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_GpioChannel_blox_OneWireGpioModule)
#endif


/* @@protoc_insertion_point(eof) */
