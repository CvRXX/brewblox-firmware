/* Automatically generated nanopb constant definitions */

#include "DisplaySettings.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_DisplaySettings_Widget_fields[8] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_DisplaySettings_Widget, pos, pos, 0),
    PB_FIELD(  2, FIXED_LENGTH_BYTES, SINGULAR, STATIC  , OTHER, blox_DisplaySettings_Widget, color, pos, 0),
    PB_FIELD(  3, STRING  , SINGULAR, STATIC  , OTHER, blox_DisplaySettings_Widget, name, color, 0),
    PB_ONEOF_FIELD(WidgetType,  10, UINT32  , ONEOF, STATIC  , OTHER, blox_DisplaySettings_Widget, tempSensor, name, 0),
    PB_ONEOF_FIELD(WidgetType,  11, UINT32  , ONEOF, STATIC  , UNION, blox_DisplaySettings_Widget, setpointSensorPair, name, 0),
    PB_ONEOF_FIELD(WidgetType,  12, UINT32  , ONEOF, STATIC  , UNION, blox_DisplaySettings_Widget, actuatorAnalog, name, 0),
    PB_ONEOF_FIELD(WidgetType,  14, UINT32  , ONEOF, STATIC  , UNION, blox_DisplaySettings_Widget, pid, name, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_DisplaySettings_Block_fields[3] = {
    PB_FIELD(  1, MESSAGE , REPEATED, STATIC  , FIRST, blox_DisplaySettings_Block, widgets, widgets, &blox_DisplaySettings_Widget_fields),
    PB_FIELD(  2, STRING  , SINGULAR, STATIC  , OTHER, blox_DisplaySettings_Block, name, widgets, 0),
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
PB_STATIC_ASSERT((pb_membersize(blox_DisplaySettings_Block, widgets[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_DisplaySettings_Widget_blox_DisplaySettings_Block)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_DisplaySettings_Block, widgets[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_DisplaySettings_Widget_blox_DisplaySettings_Block)
#endif


/* @@protoc_insertion_point(eof) */
