/* Automatically generated nanopb header */

#ifndef PB_GUIMESSAGE_GUIMESSAGE_PB_H_INCLUDED
#define PB_GUIMESSAGE_GUIMESSAGE_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _guiMessage_Type {
    guiMessage_Type_Row = 0,
    guiMessage_Type_Column = 1,
    guiMessage_Type_Content = 2
} guiMessage_Type;
#define _guiMessage_Type_MIN guiMessage_Type_Row
#define _guiMessage_Type_MAX guiMessage_Type_Content
#define _guiMessage_Type_ARRAYSIZE ((guiMessage_Type)(guiMessage_Type_Content+1))

/* Struct definitions */
typedef struct _guiMessage_Gui {
    pb_callback_t layoutNodes;
    pb_callback_t contentNodes;
/* @@protoc_insertion_point(struct:guiMessage_Gui) */
} guiMessage_Gui;

typedef struct _guiMessage_Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
/* @@protoc_insertion_point(struct:guiMessage_Color) */
} guiMessage_Color;

typedef struct _guiMessage_LayoutNode {
    uint8_t parent;
    uint8_t nodeId;
    guiMessage_Type type;
    uint16_t weight;
/* @@protoc_insertion_point(struct:guiMessage_LayoutNode) */
} guiMessage_LayoutNode;

typedef struct _guiMessage_NumericValue {
    guiMessage_Color color;
    uint8_t value;
    char label[41];
/* @@protoc_insertion_point(struct:guiMessage_NumericValue) */
} guiMessage_NumericValue;

typedef struct _guiMessage_Widget {
    guiMessage_Color color;
/* @@protoc_insertion_point(struct:guiMessage_Widget) */
} guiMessage_Widget;

typedef struct _guiMessage_ContentNode {
    uint32_t layoutNodeId;
    pb_size_t which_Content;
    union {
        guiMessage_NumericValue numericValue;
        guiMessage_Widget widget;
    } Content;
/* @@protoc_insertion_point(struct:guiMessage_ContentNode) */
} guiMessage_ContentNode;

/* Default values for struct fields */

/* Initializer values for message structs */
#define guiMessage_LayoutNode_init_default       {0, 0, _guiMessage_Type_MIN, 0}
#define guiMessage_Color_init_default            {0, 0, 0}
#define guiMessage_NumericValue_init_default     {guiMessage_Color_init_default, 0, ""}
#define guiMessage_Widget_init_default           {guiMessage_Color_init_default}
#define guiMessage_ContentNode_init_default      {0, 0, {guiMessage_NumericValue_init_default}}
#define guiMessage_Gui_init_default              {{{NULL}, NULL}, {{NULL}, NULL}}
#define guiMessage_LayoutNode_init_zero          {0, 0, _guiMessage_Type_MIN, 0}
#define guiMessage_Color_init_zero               {0, 0, 0}
#define guiMessage_NumericValue_init_zero        {guiMessage_Color_init_zero, 0, ""}
#define guiMessage_Widget_init_zero              {guiMessage_Color_init_zero}
#define guiMessage_ContentNode_init_zero         {0, 0, {guiMessage_NumericValue_init_zero}}
#define guiMessage_Gui_init_zero                 {{{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define guiMessage_Gui_layoutNodes_tag           1
#define guiMessage_Gui_contentNodes_tag          2
#define guiMessage_Color_r_tag                   1
#define guiMessage_Color_g_tag                   2
#define guiMessage_Color_b_tag                   3
#define guiMessage_LayoutNode_parent_tag         1
#define guiMessage_LayoutNode_nodeId_tag         2
#define guiMessage_LayoutNode_type_tag           3
#define guiMessage_LayoutNode_weight_tag         4
#define guiMessage_NumericValue_color_tag        1
#define guiMessage_NumericValue_value_tag        2
#define guiMessage_NumericValue_label_tag        3
#define guiMessage_Widget_color_tag              1
#define guiMessage_ContentNode_numericValue_tag  2
#define guiMessage_ContentNode_widget_tag        3
#define guiMessage_ContentNode_layoutNodeId_tag  1

/* Struct field encoding specification for nanopb */
extern const pb_field_t guiMessage_LayoutNode_fields[5];
extern const pb_field_t guiMessage_Color_fields[4];
extern const pb_field_t guiMessage_NumericValue_fields[4];
extern const pb_field_t guiMessage_Widget_fields[2];
extern const pb_field_t guiMessage_ContentNode_fields[4];
extern const pb_field_t guiMessage_Gui_fields[3];

/* Maximum encoded size of messages (where known) */
#define guiMessage_LayoutNode_size               20
#define guiMessage_Color_size                    18
#define guiMessage_NumericValue_size             69
#define guiMessage_Widget_size                   20
#define guiMessage_ContentNode_size              77
/* guiMessage_Gui_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define GUIMESSAGE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
