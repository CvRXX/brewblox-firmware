/* Automatically generated nanopb header */

#ifndef PB_SCREENCONFIG_SCREENCONFIG_PB_H_INCLUDED
#define PB_SCREENCONFIG_SCREENCONFIG_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _ScreenConfig_LayoutNode_Type {
    ScreenConfig_LayoutNode_Type_Row = 0,
    ScreenConfig_LayoutNode_Type_Column = 1,
    ScreenConfig_LayoutNode_Type_Content = 2
} ScreenConfig_LayoutNode_Type;
#define _ScreenConfig_LayoutNode_Type_MIN ScreenConfig_LayoutNode_Type_Row
#define _ScreenConfig_LayoutNode_Type_MAX ScreenConfig_LayoutNode_Type_Content
#define _ScreenConfig_LayoutNode_Type_ARRAYSIZE ((ScreenConfig_LayoutNode_Type)(ScreenConfig_LayoutNode_Type_Content+1))

/* Struct definitions */
typedef struct _ScreenConfig_ScreenConfig {
    pb_callback_t layoutNodes;
    pb_callback_t contentNodes;
/* @@protoc_insertion_point(struct:ScreenConfig_ScreenConfig) */
} ScreenConfig_ScreenConfig;

typedef struct _ScreenConfig_Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
/* @@protoc_insertion_point(struct:ScreenConfig_Color) */
} ScreenConfig_Color;

typedef struct _ScreenConfig_LayoutNode {
    uint8_t parent;
    uint8_t nodeId;
    ScreenConfig_LayoutNode_Type type;
    uint16_t weight;
/* @@protoc_insertion_point(struct:ScreenConfig_LayoutNode) */
} ScreenConfig_LayoutNode;

typedef struct _ScreenConfig_ColorWidget {
    ScreenConfig_Color color;
/* @@protoc_insertion_point(struct:ScreenConfig_ColorWidget) */
} ScreenConfig_ColorWidget;

typedef struct _ScreenConfig_NumericValueWidget {
    ScreenConfig_Color color;
    uint8_t value;
    char label[41];
/* @@protoc_insertion_point(struct:ScreenConfig_NumericValueWidget) */
} ScreenConfig_NumericValueWidget;

typedef struct _ScreenConfig_ContentNode {
    uint8_t layoutNodeId;
    pb_size_t which_content;
    union {
        ScreenConfig_NumericValueWidget numericValueWidget;
        ScreenConfig_ColorWidget colorWidget;
    } content;
/* @@protoc_insertion_point(struct:ScreenConfig_ContentNode) */
} ScreenConfig_ContentNode;

/* Default values for struct fields */

/* Initializer values for message structs */
#define ScreenConfig_LayoutNode_init_default     {0, 0, _ScreenConfig_LayoutNode_Type_MIN, 0}
#define ScreenConfig_Color_init_default          {0, 0, 0}
#define ScreenConfig_NumericValueWidget_init_default {ScreenConfig_Color_init_default, 0, ""}
#define ScreenConfig_ColorWidget_init_default    {ScreenConfig_Color_init_default}
#define ScreenConfig_ContentNode_init_default    {0, 0, {ScreenConfig_NumericValueWidget_init_default}}
#define ScreenConfig_ScreenConfig_init_default   {{{NULL}, NULL}, {{NULL}, NULL}}
#define ScreenConfig_LayoutNode_init_zero        {0, 0, _ScreenConfig_LayoutNode_Type_MIN, 0}
#define ScreenConfig_Color_init_zero             {0, 0, 0}
#define ScreenConfig_NumericValueWidget_init_zero {ScreenConfig_Color_init_zero, 0, ""}
#define ScreenConfig_ColorWidget_init_zero       {ScreenConfig_Color_init_zero}
#define ScreenConfig_ContentNode_init_zero       {0, 0, {ScreenConfig_NumericValueWidget_init_zero}}
#define ScreenConfig_ScreenConfig_init_zero      {{{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define ScreenConfig_ScreenConfig_layoutNodes_tag 1
#define ScreenConfig_ScreenConfig_contentNodes_tag 2
#define ScreenConfig_Color_r_tag                 1
#define ScreenConfig_Color_g_tag                 2
#define ScreenConfig_Color_b_tag                 3
#define ScreenConfig_LayoutNode_parent_tag       1
#define ScreenConfig_LayoutNode_nodeId_tag       2
#define ScreenConfig_LayoutNode_type_tag         3
#define ScreenConfig_LayoutNode_weight_tag       4
#define ScreenConfig_ColorWidget_color_tag       1
#define ScreenConfig_NumericValueWidget_color_tag 1
#define ScreenConfig_NumericValueWidget_value_tag 2
#define ScreenConfig_NumericValueWidget_label_tag 3
#define ScreenConfig_ContentNode_numericValueWidget_tag 2
#define ScreenConfig_ContentNode_colorWidget_tag 3
#define ScreenConfig_ContentNode_layoutNodeId_tag 1

/* Struct field encoding specification for nanopb */
extern const pb_field_t ScreenConfig_LayoutNode_fields[5];
extern const pb_field_t ScreenConfig_Color_fields[4];
extern const pb_field_t ScreenConfig_NumericValueWidget_fields[4];
extern const pb_field_t ScreenConfig_ColorWidget_fields[2];
extern const pb_field_t ScreenConfig_ContentNode_fields[4];
extern const pb_field_t ScreenConfig_ScreenConfig_fields[3];

/* Maximum encoded size of messages (where known) */
#define ScreenConfig_LayoutNode_size             20
#define ScreenConfig_Color_size                  18
#define ScreenConfig_NumericValueWidget_size     69
#define ScreenConfig_ColorWidget_size            20
#define ScreenConfig_ContentNode_size            77
/* ScreenConfig_ScreenConfig_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SCREENCONFIG_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
