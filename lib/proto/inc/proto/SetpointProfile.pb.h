/* Automatically generated nanopb header */

#ifndef PB_BLOX_SETPOINTPROFILE_SETPOINTPROFILE_PB_H_INCLUDED
#define PB_BLOX_SETPOINTPROFILE_SETPOINTPROFILE_PB_H_INCLUDED
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
typedef struct _blox_SetpointProfile_Block {
    pb_callback_t points;
    bool enabled;
    uint16_t targetId;
    uint32_t start;
    bool drivenTargetId;
/* @@protoc_insertion_point(struct:blox_SetpointProfile_Block) */
} blox_SetpointProfile_Block;

typedef struct _blox_SetpointProfile_Point {
    uint32_t time;
    pb_size_t which_temperature_oneof;
    union {
        int32_t temperature;
    } temperature_oneof;
/* @@protoc_insertion_point(struct:blox_SetpointProfile_Point) */
} blox_SetpointProfile_Point;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_SetpointProfile_Point_init_default  {0, 0, {0}}
#define blox_SetpointProfile_Block_init_default  {{{NULL}, NULL}, 0, 0, 0, 0}
#define blox_SetpointProfile_Point_init_zero     {0, 0, {0}}
#define blox_SetpointProfile_Block_init_zero     {{{NULL}, NULL}, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_SetpointProfile_Block_points_tag    1
#define blox_SetpointProfile_Block_enabled_tag   3
#define blox_SetpointProfile_Block_targetId_tag  4
#define blox_SetpointProfile_Block_start_tag     6
#define blox_SetpointProfile_Block_drivenTargetId_tag 90
#define blox_SetpointProfile_Point_temperature_tag 2
#define blox_SetpointProfile_Point_time_tag      1

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_SetpointProfile_Point_fields[3];
extern const pb_field_t blox_SetpointProfile_Block_fields[6];

/* Maximum encoded size of messages (where known) */
#define blox_SetpointProfile_Point_size          17
/* blox_SetpointProfile_Block_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SETPOINTPROFILE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
