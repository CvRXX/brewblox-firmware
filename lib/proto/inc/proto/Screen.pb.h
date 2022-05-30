/* Automatically generated nanopb header */

#ifndef PB_SCREEN_SCREEN_PB_H_INCLUDED
#define PB_SCREEN_SCREEN_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _screen_LayoutNode_Type {
    screen_LayoutNode_Type_Row = 0,
    screen_LayoutNode_Type_Column = 1,
    screen_LayoutNode_Type_Content = 2
} screen_LayoutNode_Type;
#define _screen_LayoutNode_Type_MIN screen_LayoutNode_Type_Row
#define _screen_LayoutNode_Type_MAX screen_LayoutNode_Type_Content
#define _screen_LayoutNode_Type_ARRAYSIZE ((screen_LayoutNode_Type)(screen_LayoutNode_Type_Content+1))

/* Struct definitions */
typedef struct _screen_Config {
    pb_callback_t layoutNodes;
    pb_callback_t contentNodes;
/* @@protoc_insertion_point(struct:screen_Config) */
} screen_Config;

typedef struct _screen_Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
/* @@protoc_insertion_point(struct:screen_Color) */
} screen_Color;

typedef struct _screen_LayoutNode {
    uint8_t parent;
    uint8_t nodeId;
    screen_LayoutNode_Type type;
    uint16_t weight;
/* @@protoc_insertion_point(struct:screen_LayoutNode) */
} screen_LayoutNode;

typedef struct _screen_ColorWidget {
    screen_Color color;
/* @@protoc_insertion_point(struct:screen_ColorWidget) */
} screen_ColorWidget;

typedef struct _screen_NumericValueWidget {
    screen_Color color;
    uint8_t value;
    char label[41];
/* @@protoc_insertion_point(struct:screen_NumericValueWidget) */
} screen_NumericValueWidget;

typedef struct _screen_ContentNode {
    uint8_t layoutNodeId;
    pb_size_t which_content;
    union {
        screen_NumericValueWidget numericValueWidget;
        screen_ColorWidget colorWidget;
    } content;
/* @@protoc_insertion_point(struct:screen_ContentNode) */
} screen_ContentNode;

/* Default values for struct fields */

/* Initializer values for message structs */
#define screen_LayoutNode_init_default           {0, 0, _screen_LayoutNode_Type_MIN, 0}
#define screen_Color_init_default                {0, 0, 0}
#define screen_NumericValueWidget_init_default   {screen_Color_init_default, 0, ""}
#define screen_ColorWidget_init_default          {screen_Color_init_default}
#define screen_ContentNode_init_default          {0, 0, {screen_NumericValueWidget_init_default}}
#define screen_Config_init_default               {{{NULL}, NULL}, {{NULL}, NULL}}
#define screen_LayoutNode_init_zero              {0, 0, _screen_LayoutNode_Type_MIN, 0}
#define screen_Color_init_zero                   {0, 0, 0}
#define screen_NumericValueWidget_init_zero      {screen_Color_init_zero, 0, ""}
#define screen_ColorWidget_init_zero             {screen_Color_init_zero}
#define screen_ContentNode_init_zero             {0, 0, {screen_NumericValueWidget_init_zero}}
#define screen_Config_init_zero                  {{{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define screen_Config_layoutNodes_tag            1
#define screen_Config_contentNodes_tag           2
#define screen_Color_r_tag                       1
#define screen_Color_g_tag                       2
#define screen_Color_b_tag                       3
#define screen_LayoutNode_parent_tag             1
#define screen_LayoutNode_nodeId_tag             2
#define screen_LayoutNode_type_tag               3
#define screen_LayoutNode_weight_tag             4
#define screen_ColorWidget_color_tag             1
#define screen_NumericValueWidget_color_tag      1
#define screen_NumericValueWidget_value_tag      2
#define screen_NumericValueWidget_label_tag      3
#define screen_ContentNode_numericValueWidget_tag 2
#define screen_ContentNode_colorWidget_tag       3
#define screen_ContentNode_layoutNodeId_tag      1

/* Struct field encoding specification for nanopb */
extern const pb_field_t screen_LayoutNode_fields[5];
extern const pb_field_t screen_Color_fields[4];
extern const pb_field_t screen_NumericValueWidget_fields[4];
extern const pb_field_t screen_ColorWidget_fields[2];
extern const pb_field_t screen_ContentNode_fields[4];
extern const pb_field_t screen_Config_fields[3];

/* Maximum encoded size of messages (where known) */
#define screen_LayoutNode_size                   20
#define screen_Color_size                        18
#define screen_NumericValueWidget_size           69
#define screen_ColorWidget_size                  20
#define screen_ContentNode_size                  77
/* screen_Config_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SCREEN_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
