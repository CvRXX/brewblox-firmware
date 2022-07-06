/* Automatically generated nanopb constant definitions */

#include "Screen.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t screen_LayoutNode_fields[5] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, screen_LayoutNode, parent, parent, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, screen_LayoutNode, nodeId, parent, 0),
    PB_FIELD(  3, UENUM   , SINGULAR, STATIC  , OTHER, screen_LayoutNode, type, nodeId, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, screen_LayoutNode, weight, type, 0),
    PB_LAST_FIELD
};

const pb_field_t screen_Color_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, screen_Color, r, r, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, screen_Color, g, r, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, screen_Color, b, g, 0),
    PB_LAST_FIELD
};

const pb_field_t screen_NumericValueWidget_fields[4] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, screen_NumericValueWidget, color, color, &screen_Color_fields),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, screen_NumericValueWidget, value, color, 0),
    PB_FIELD(  3, STRING  , SINGULAR, STATIC  , OTHER, screen_NumericValueWidget, label, value, 0),
    PB_LAST_FIELD
};

const pb_field_t screen_TemperatureWidget_fields[4] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, screen_TemperatureWidget, color, color, &screen_Color_fields),
    PB_FIELD(  2, STRING  , SINGULAR, STATIC  , OTHER, screen_TemperatureWidget, label, color, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, screen_TemperatureWidget, tempSensor, label, 0),
    PB_LAST_FIELD
};

const pb_field_t screen_SetpointSensorPairWidget_fields[4] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, screen_SetpointSensorPairWidget, color, color, &screen_Color_fields),
    PB_FIELD(  2, STRING  , SINGULAR, STATIC  , OTHER, screen_SetpointSensorPairWidget, label, color, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, screen_SetpointSensorPairWidget, setpointSensorPair, label, 0),
    PB_LAST_FIELD
};

const pb_field_t screen_ColorWidget_fields[2] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, screen_ColorWidget, color, color, &screen_Color_fields),
    PB_LAST_FIELD
};

const pb_field_t screen_ContentNode_fields[6] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, screen_ContentNode, layoutNodeId, layoutNodeId, 0),
    PB_ONEOF_FIELD(content,   2, MESSAGE , ONEOF, STATIC  , OTHER, screen_ContentNode, numericValueWidget, layoutNodeId, &screen_NumericValueWidget_fields),
    PB_ONEOF_FIELD(content,   3, MESSAGE , ONEOF, STATIC  , UNION, screen_ContentNode, colorWidget, layoutNodeId, &screen_ColorWidget_fields),
    PB_ONEOF_FIELD(content,   4, MESSAGE , ONEOF, STATIC  , UNION, screen_ContentNode, temperatureWidget, layoutNodeId, &screen_TemperatureWidget_fields),
    PB_ONEOF_FIELD(content,   5, MESSAGE , ONEOF, STATIC  , UNION, screen_ContentNode, setpointSensorPairWidget, layoutNodeId, &screen_SetpointSensorPairWidget_fields),
    PB_LAST_FIELD
};

const pb_field_t screen_Block_fields[7] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, screen_Block, layoutNodes, layoutNodes, &screen_LayoutNode_fields),
    PB_FIELD(  2, MESSAGE , REPEATED, CALLBACK, OTHER, screen_Block, contentNodes, layoutNodes, &screen_ContentNode_fields),
    PB_FIELD(  3, STRING  , SINGULAR, STATIC  , OTHER, screen_Block, name, contentNodes, 0),
    PB_FIELD(  4, UENUM   , SINGULAR, STATIC  , OTHER, screen_Block, tempUnit, name, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, screen_Block, brightness, tempUnit, 0),
    PB_FIELD(  6, STRING  , SINGULAR, STATIC  , OTHER, screen_Block, timeZone, brightness, 0),
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
PB_STATIC_ASSERT((pb_membersize(screen_NumericValueWidget, color) < 65536 && pb_membersize(screen_TemperatureWidget, color) < 65536 && pb_membersize(screen_SetpointSensorPairWidget, color) < 65536 && pb_membersize(screen_ColorWidget, color) < 65536 && pb_membersize(screen_ContentNode, content.numericValueWidget) < 65536 && pb_membersize(screen_ContentNode, content.colorWidget) < 65536 && pb_membersize(screen_ContentNode, content.temperatureWidget) < 65536 && pb_membersize(screen_ContentNode, content.setpointSensorPairWidget) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_screen_LayoutNode_screen_Color_screen_NumericValueWidget_screen_TemperatureWidget_screen_SetpointSensorPairWidget_screen_ColorWidget_screen_ContentNode_screen_Block)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(screen_NumericValueWidget, color) < 256 && pb_membersize(screen_TemperatureWidget, color) < 256 && pb_membersize(screen_SetpointSensorPairWidget, color) < 256 && pb_membersize(screen_ColorWidget, color) < 256 && pb_membersize(screen_ContentNode, content.numericValueWidget) < 256 && pb_membersize(screen_ContentNode, content.colorWidget) < 256 && pb_membersize(screen_ContentNode, content.temperatureWidget) < 256 && pb_membersize(screen_ContentNode, content.setpointSensorPairWidget) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_screen_LayoutNode_screen_Color_screen_NumericValueWidget_screen_TemperatureWidget_screen_SetpointSensorPairWidget_screen_ColorWidget_screen_ContentNode_screen_Block)
#endif


/* @@protoc_insertion_point(eof) */
