/* Automatically generated nanopb header */

#ifndef PB_BLOX_EDGECASE_PB_H_INCLUDED
#define PB_BLOX_EDGECASE_PB_H_INCLUDED
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
typedef struct _blox_NestedLink {
    uint32_t connection;
/* @@protoc_insertion_point(struct:blox_NestedLink) */
} blox_NestedLink;

typedef struct _blox_Settings {
    uint64_t address;
    int32_t offset;
/* @@protoc_insertion_point(struct:blox_Settings) */
} blox_Settings;

typedef struct _blox_State {
    int32_t value;
    bool connected;
/* @@protoc_insertion_point(struct:blox_State) */
} blox_State;

typedef struct _blox_EdgeCase {
    blox_Settings settings;
    blox_State state;
    uint32_t link;
    pb_callback_t additionalLinks;
    pb_callback_t listValues;
    uint32_t deltaV;
    uint32_t logged;
    uint32_t unLogged;
    uint16_t drivenDevice;
    pb_size_t strippedFields_count;
    uint16_t strippedFields[2];
/* @@protoc_insertion_point(struct:blox_EdgeCase) */
} blox_EdgeCase;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Settings_init_default               {0, 0}
#define blox_State_init_default                  {0, 0}
#define blox_NestedLink_init_default             {0}
#define blox_EdgeCase_init_default               {blox_Settings_init_default, blox_State_init_default, 0, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, 0, 0, 0, {0, 0}}
#define blox_Settings_init_zero                  {0, 0}
#define blox_State_init_zero                     {0, 0}
#define blox_NestedLink_init_zero                {0}
#define blox_EdgeCase_init_zero                  {blox_Settings_init_zero, blox_State_init_zero, 0, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, 0, 0, 0, {0, 0}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_NestedLink_connection_tag           1
#define blox_Settings_address_tag                1
#define blox_Settings_offset_tag                 2
#define blox_State_value_tag                     1
#define blox_State_connected_tag                 2
#define blox_EdgeCase_settings_tag               1
#define blox_EdgeCase_state_tag                  2
#define blox_EdgeCase_link_tag                   3
#define blox_EdgeCase_additionalLinks_tag        4
#define blox_EdgeCase_listValues_tag             5
#define blox_EdgeCase_deltaV_tag                 6
#define blox_EdgeCase_logged_tag                 7
#define blox_EdgeCase_unLogged_tag               8
#define blox_EdgeCase_drivenDevice_tag           9
#define blox_EdgeCase_strippedFields_tag         99

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Settings_fields[3];
extern const pb_field_t blox_State_fields[3];
extern const pb_field_t blox_NestedLink_fields[2];
extern const pb_field_t blox_EdgeCase_fields[11];

/* Maximum encoded size of messages (where known) */
#define blox_Settings_size                       15
#define blox_State_size                          8
#define blox_NestedLink_size                     6
/* blox_EdgeCase_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define EDGECASE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
