/* Automatically generated nanopb header */

#ifndef PB_BLOX_SCREENCONFIG_SCREENCONFIG_PB_H_INCLUDED
#define PB_BLOX_SCREENCONFIG_SCREENCONFIG_PB_H_INCLUDED
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
typedef enum _blox_ScreenConfig_Type {
    blox_ScreenConfig_Type_Row = 0,
    blox_ScreenConfig_Type_Column = 1,
    blox_ScreenConfig_Type_Content = 2
} blox_ScreenConfig_Type;
#define _blox_ScreenConfig_Type_MIN blox_ScreenConfig_Type_Row
#define _blox_ScreenConfig_Type_MAX blox_ScreenConfig_Type_Content
#define _blox_ScreenConfig_Type_ARRAYSIZE ((blox_ScreenConfig_Type)(blox_ScreenConfig_Type_Content+1))

/* Struct definitions */
typedef struct _blox_ScreenConfig_ScreenConfig {
    pb_callback_t layoutNodes;
    pb_callback_t contentNodes;
/* @@protoc_insertion_point(struct:blox_ScreenConfig_ScreenConfig) */
} blox_ScreenConfig_ScreenConfig;

typedef struct _blox_ScreenConfig_Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
/* @@protoc_insertion_point(struct:blox_ScreenConfig_Color) */
} blox_ScreenConfig_Color;

typedef struct _blox_ScreenConfig_LayoutNode {
    uint8_t parent;
    uint8_t nodeId;
    blox_ScreenConfig_Type type;
    uint16_t weight;
/* @@protoc_insertion_point(struct:blox_ScreenConfig_LayoutNode) */
} blox_ScreenConfig_LayoutNode;

typedef struct _blox_ScreenConfig_ColorWidget {
    blox_ScreenConfig_Color color;
/* @@protoc_insertion_point(struct:blox_ScreenConfig_ColorWidget) */
} blox_ScreenConfig_ColorWidget;

typedef struct _blox_ScreenConfig_NumericValueWidget {
    blox_ScreenConfig_Color color;
    uint8_t value;
    char label[41];
/* @@protoc_insertion_point(struct:blox_ScreenConfig_NumericValueWidget) */
} blox_ScreenConfig_NumericValueWidget;

typedef struct _blox_ScreenConfig_ContentNode {
    uint8_t layoutNodeId;
    pb_size_t which_Content;
    union {
        blox_ScreenConfig_NumericValueWidget numericValueWidget;
        blox_ScreenConfig_ColorWidget colorWidget;
    } Content;
/* @@protoc_insertion_point(struct:blox_ScreenConfig_ContentNode) */
} blox_ScreenConfig_ContentNode;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_ScreenConfig_LayoutNode_init_default {0, 0, _blox_ScreenConfig_Type_MIN, 0}
#define blox_ScreenConfig_Color_init_default     {0, 0, 0}
#define blox_ScreenConfig_NumericValueWidget_init_default {blox_ScreenConfig_Color_init_default, 0, ""}
#define blox_ScreenConfig_ColorWidget_init_default {blox_ScreenConfig_Color_init_default}
#define blox_ScreenConfig_ContentNode_init_default {0, 0, {blox_ScreenConfig_NumericValueWidget_init_default}}
#define blox_ScreenConfig_ScreenConfig_init_default {{{NULL}, NULL}, {{NULL}, NULL}}
#define blox_ScreenConfig_LayoutNode_init_zero   {0, 0, _blox_ScreenConfig_Type_MIN, 0}
#define blox_ScreenConfig_Color_init_zero        {0, 0, 0}
#define blox_ScreenConfig_NumericValueWidget_init_zero {blox_ScreenConfig_Color_init_zero, 0, ""}
#define blox_ScreenConfig_ColorWidget_init_zero  {blox_ScreenConfig_Color_init_zero}
#define blox_ScreenConfig_ContentNode_init_zero  {0, 0, {blox_ScreenConfig_NumericValueWidget_init_zero}}
#define blox_ScreenConfig_ScreenConfig_init_zero {{{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_ScreenConfig_ScreenConfig_layoutNodes_tag 1
#define blox_ScreenConfig_ScreenConfig_contentNodes_tag 2
#define blox_ScreenConfig_Color_r_tag            1
#define blox_ScreenConfig_Color_g_tag            2
#define blox_ScreenConfig_Color_b_tag            3
#define blox_ScreenConfig_LayoutNode_parent_tag  1
#define blox_ScreenConfig_LayoutNode_nodeId_tag  2
#define blox_ScreenConfig_LayoutNode_type_tag    3
#define blox_ScreenConfig_LayoutNode_weight_tag  4
#define blox_ScreenConfig_ColorWidget_color_tag  1
#define blox_ScreenConfig_NumericValueWidget_color_tag 1
#define blox_ScreenConfig_NumericValueWidget_value_tag 2
#define blox_ScreenConfig_NumericValueWidget_label_tag 3
#define blox_ScreenConfig_ContentNode_numericValueWidget_tag 2
#define blox_ScreenConfig_ContentNode_colorWidget_tag 3
#define blox_ScreenConfig_ContentNode_layoutNodeId_tag 1

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_ScreenConfig_LayoutNode_fields[5];
extern const pb_field_t blox_ScreenConfig_Color_fields[4];
extern const pb_field_t blox_ScreenConfig_NumericValueWidget_fields[4];
extern const pb_field_t blox_ScreenConfig_ColorWidget_fields[2];
extern const pb_field_t blox_ScreenConfig_ContentNode_fields[4];
extern const pb_field_t blox_ScreenConfig_ScreenConfig_fields[3];

/* Maximum encoded size of messages (where known) */
#define blox_ScreenConfig_LayoutNode_size        20
#define blox_ScreenConfig_Color_size             18
#define blox_ScreenConfig_NumericValueWidget_size 69
#define blox_ScreenConfig_ColorWidget_size       20
#define blox_ScreenConfig_ContentNode_size       77
/* blox_ScreenConfig_ScreenConfig_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SCREENCONFIG_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
