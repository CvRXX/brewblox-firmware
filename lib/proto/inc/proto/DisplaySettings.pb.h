/* Automatically generated nanopb header */

#ifndef PB_BLOX_DISPLAYSETTINGS_DISPLAYSETTINGS_PB_H_INCLUDED
#define PB_BLOX_DISPLAYSETTINGS_DISPLAYSETTINGS_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _blox_DisplaySettings_Widget {
    uint8_t pos;
    pb_byte_t color[3];
    char name[16];
    pb_size_t which_WidgetType;
    union {
        uint16_t tempSensor;
        uint16_t setpointSensorPair;
        uint16_t actuatorAnalog;
        uint16_t pid;
    } WidgetType;
/* @@protoc_insertion_point(struct:blox_DisplaySettings_Widget) */
} blox_DisplaySettings_Widget;

typedef struct _blox_DisplaySettings_Block {
    pb_size_t widgets_count;
    blox_DisplaySettings_Widget widgets[6];
    char name[40];
/* @@protoc_insertion_point(struct:blox_DisplaySettings_Block) */
} blox_DisplaySettings_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_DisplaySettings_Widget_init_default {0, {0}, "", 0, {0}}
#define blox_DisplaySettings_Block_init_default  {0, {blox_DisplaySettings_Widget_init_default, blox_DisplaySettings_Widget_init_default, blox_DisplaySettings_Widget_init_default, blox_DisplaySettings_Widget_init_default, blox_DisplaySettings_Widget_init_default, blox_DisplaySettings_Widget_init_default}, ""}
#define blox_DisplaySettings_Widget_init_zero    {0, {0}, "", 0, {0}}
#define blox_DisplaySettings_Block_init_zero     {0, {blox_DisplaySettings_Widget_init_zero, blox_DisplaySettings_Widget_init_zero, blox_DisplaySettings_Widget_init_zero, blox_DisplaySettings_Widget_init_zero, blox_DisplaySettings_Widget_init_zero, blox_DisplaySettings_Widget_init_zero}, ""}

/* Field tags (for use in manual encoding/decoding) */
#define blox_DisplaySettings_Widget_tempSensor_tag 10
#define blox_DisplaySettings_Widget_setpointSensorPair_tag 11
#define blox_DisplaySettings_Widget_actuatorAnalog_tag 12
#define blox_DisplaySettings_Widget_pid_tag      14
#define blox_DisplaySettings_Widget_pos_tag      1
#define blox_DisplaySettings_Widget_color_tag    2
#define blox_DisplaySettings_Widget_name_tag     3
#define blox_DisplaySettings_Block_widgets_tag   1
#define blox_DisplaySettings_Block_name_tag      2

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_DisplaySettings_Widget_fields[8];
extern const pb_field_t blox_DisplaySettings_Block_fields[3];

/* Maximum encoded size of messages (where known) */
#define blox_DisplaySettings_Widget_size         35
#define blox_DisplaySettings_Block_size          264

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DISPLAYSETTINGS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
