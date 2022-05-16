/* Automatically generated nanopb constant definitions */

#include "ScreenConfig.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_ScreenConfig_LayoutNode_fields[5] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_ScreenConfig_LayoutNode, parent, parent, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_ScreenConfig_LayoutNode, nodeId, parent, 0),
    PB_FIELD(  3, UENUM   , SINGULAR, STATIC  , OTHER, blox_ScreenConfig_LayoutNode, type, nodeId, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, blox_ScreenConfig_LayoutNode, weight, type, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_ScreenConfig_Color_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_ScreenConfig_Color, r, r, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_ScreenConfig_Color, g, r, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_ScreenConfig_Color, b, g, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_ScreenConfig_NumericValueWidget_fields[4] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, blox_ScreenConfig_NumericValueWidget, color, color, &blox_ScreenConfig_Color_fields),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, blox_ScreenConfig_NumericValueWidget, value, color, 0),
    PB_FIELD(  3, STRING  , SINGULAR, STATIC  , OTHER, blox_ScreenConfig_NumericValueWidget, label, value, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_ScreenConfig_ColorWidget_fields[2] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, blox_ScreenConfig_ColorWidget, color, color, &blox_ScreenConfig_Color_fields),
    PB_LAST_FIELD
};

const pb_field_t blox_ScreenConfig_ContentNode_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_ScreenConfig_ContentNode, layoutNodeId, layoutNodeId, 0),
    PB_ONEOF_FIELD(Content,   2, MESSAGE , ONEOF, STATIC  , OTHER, blox_ScreenConfig_ContentNode, numericValueWidget, layoutNodeId, &blox_ScreenConfig_NumericValueWidget_fields),
    PB_ONEOF_FIELD(Content,   3, MESSAGE , ONEOF, STATIC  , UNION, blox_ScreenConfig_ContentNode, colorWidget, layoutNodeId, &blox_ScreenConfig_ColorWidget_fields),
    PB_LAST_FIELD
};

const pb_field_t blox_ScreenConfig_ScreenConfig_fields[3] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, blox_ScreenConfig_ScreenConfig, layoutNodes, layoutNodes, &blox_ScreenConfig_LayoutNode_fields),
    PB_FIELD(  2, MESSAGE , REPEATED, CALLBACK, OTHER, blox_ScreenConfig_ScreenConfig, contentNodes, layoutNodes, &blox_ScreenConfig_ContentNode_fields),
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
PB_STATIC_ASSERT((pb_membersize(blox_ScreenConfig_NumericValueWidget, color) < 65536 && pb_membersize(blox_ScreenConfig_ColorWidget, color) < 65536 && pb_membersize(blox_ScreenConfig_ContentNode, Content.numericValueWidget) < 65536 && pb_membersize(blox_ScreenConfig_ContentNode, Content.colorWidget) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_ScreenConfig_LayoutNode_blox_ScreenConfig_Color_blox_ScreenConfig_NumericValueWidget_blox_ScreenConfig_ColorWidget_blox_ScreenConfig_ContentNode_blox_ScreenConfig_ScreenConfig)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_ScreenConfig_NumericValueWidget, color) < 256 && pb_membersize(blox_ScreenConfig_ColorWidget, color) < 256 && pb_membersize(blox_ScreenConfig_ContentNode, Content.numericValueWidget) < 256 && pb_membersize(blox_ScreenConfig_ContentNode, Content.colorWidget) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_ScreenConfig_LayoutNode_blox_ScreenConfig_Color_blox_ScreenConfig_NumericValueWidget_blox_ScreenConfig_ColorWidget_blox_ScreenConfig_ContentNode_blox_ScreenConfig_ScreenConfig)
#endif


/* @@protoc_insertion_point(eof) */
