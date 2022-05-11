/* Automatically generated nanopb constant definitions */

#include "guiMessage.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t guiMessage_LayoutNode_fields[5] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, guiMessage_LayoutNode, parent, parent, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, guiMessage_LayoutNode, nodeId, parent, 0),
    PB_FIELD(  3, UENUM   , SINGULAR, STATIC  , OTHER, guiMessage_LayoutNode, type, nodeId, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, guiMessage_LayoutNode, weight, type, 0),
    PB_LAST_FIELD
};

const pb_field_t guiMessage_Color_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, guiMessage_Color, r, r, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, guiMessage_Color, g, r, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, guiMessage_Color, b, g, 0),
    PB_LAST_FIELD
};

const pb_field_t guiMessage_NumericValue_fields[4] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, guiMessage_NumericValue, color, color, &guiMessage_Color_fields),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, guiMessage_NumericValue, value, color, 0),
    PB_FIELD(  3, STRING  , SINGULAR, STATIC  , OTHER, guiMessage_NumericValue, label, value, 0),
    PB_LAST_FIELD
};

const pb_field_t guiMessage_Widget_fields[2] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, guiMessage_Widget, color, color, &guiMessage_Color_fields),
    PB_LAST_FIELD
};

const pb_field_t guiMessage_ContentNode_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, guiMessage_ContentNode, layoutNodeId, layoutNodeId, 0),
    PB_ONEOF_FIELD(Content,   2, MESSAGE , ONEOF, STATIC  , OTHER, guiMessage_ContentNode, numericValue, layoutNodeId, &guiMessage_NumericValue_fields),
    PB_ONEOF_FIELD(Content,   3, MESSAGE , ONEOF, STATIC  , UNION, guiMessage_ContentNode, widget, layoutNodeId, &guiMessage_Widget_fields),
    PB_LAST_FIELD
};

const pb_field_t guiMessage_Gui_fields[3] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, guiMessage_Gui, layoutNodes, layoutNodes, &guiMessage_LayoutNode_fields),
    PB_FIELD(  2, MESSAGE , REPEATED, CALLBACK, OTHER, guiMessage_Gui, contentNodes, layoutNodes, &guiMessage_ContentNode_fields),
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
PB_STATIC_ASSERT((pb_membersize(guiMessage_NumericValue, color) < 65536 && pb_membersize(guiMessage_Widget, color) < 65536 && pb_membersize(guiMessage_ContentNode, Content.numericValue) < 65536 && pb_membersize(guiMessage_ContentNode, Content.widget) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_guiMessage_LayoutNode_guiMessage_Color_guiMessage_NumericValue_guiMessage_Widget_guiMessage_ContentNode_guiMessage_Gui)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(guiMessage_NumericValue, color) < 256 && pb_membersize(guiMessage_Widget, color) < 256 && pb_membersize(guiMessage_ContentNode, Content.numericValue) < 256 && pb_membersize(guiMessage_ContentNode, Content.widget) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_guiMessage_LayoutNode_guiMessage_Color_guiMessage_NumericValue_guiMessage_Widget_guiMessage_ContentNode_guiMessage_Gui)
#endif


/* @@protoc_insertion_point(eof) */
