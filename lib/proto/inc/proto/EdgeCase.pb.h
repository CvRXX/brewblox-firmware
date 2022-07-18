/* Automatically generated nanopb header */

#ifndef PB_BLOX_EDGECASE_EDGECASE_PB_H_INCLUDED
#define PB_BLOX_EDGECASE_EDGECASE_PB_H_INCLUDED
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
typedef struct _blox_EdgeCase_NestedLink {
    uint32_t connection;
/* @@protoc_insertion_point(struct:blox_EdgeCase_NestedLink) */
} blox_EdgeCase_NestedLink;

typedef struct _blox_EdgeCase_Settings {
    uint64_t address;
    int32_t offset;
/* @@protoc_insertion_point(struct:blox_EdgeCase_Settings) */
} blox_EdgeCase_Settings;

typedef struct _blox_EdgeCase_State {
    int32_t value;
    bool connected;
/* @@protoc_insertion_point(struct:blox_EdgeCase_State) */
} blox_EdgeCase_State;

typedef struct _blox_EdgeCase_SubCase {
    uint32_t subvalue;
/* @@protoc_insertion_point(struct:blox_EdgeCase_SubCase) */
} blox_EdgeCase_SubCase;

typedef struct _blox_EdgeCase_Block {
    blox_EdgeCase_Settings settings;
    blox_EdgeCase_State state;
    uint32_t link;
    pb_callback_t additionalLinks;
    pb_callback_t listValues;
    uint32_t deltaV;
    uint32_t logged;
    uint32_t unLogged;
    uint16_t drivenDevice;
    uint32_t ip;
/* @@protoc_insertion_point(struct:blox_EdgeCase_Block) */
} blox_EdgeCase_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_EdgeCase_Settings_init_default      {0, 0}
#define blox_EdgeCase_State_init_default         {0, 0}
#define blox_EdgeCase_NestedLink_init_default    {0}
#define blox_EdgeCase_Block_init_default         {blox_EdgeCase_Settings_init_default, blox_EdgeCase_State_init_default, 0, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, 0, 0, 0}
#define blox_EdgeCase_SubCase_init_default       {0}
#define blox_EdgeCase_Settings_init_zero         {0, 0}
#define blox_EdgeCase_State_init_zero            {0, 0}
#define blox_EdgeCase_NestedLink_init_zero       {0}
#define blox_EdgeCase_Block_init_zero            {blox_EdgeCase_Settings_init_zero, blox_EdgeCase_State_init_zero, 0, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, 0, 0, 0}
#define blox_EdgeCase_SubCase_init_zero          {0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_EdgeCase_NestedLink_connection_tag  1
#define blox_EdgeCase_Settings_address_tag       1
#define blox_EdgeCase_Settings_offset_tag        2
#define blox_EdgeCase_State_value_tag            1
#define blox_EdgeCase_State_connected_tag        2
#define blox_EdgeCase_SubCase_subvalue_tag       1
#define blox_EdgeCase_Block_settings_tag         1
#define blox_EdgeCase_Block_state_tag            2
#define blox_EdgeCase_Block_link_tag             3
#define blox_EdgeCase_Block_additionalLinks_tag  4
#define blox_EdgeCase_Block_listValues_tag       5
#define blox_EdgeCase_Block_deltaV_tag           6
#define blox_EdgeCase_Block_logged_tag           7
#define blox_EdgeCase_Block_unLogged_tag         8
#define blox_EdgeCase_Block_drivenDevice_tag     9
#define blox_EdgeCase_Block_ip_tag               10

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_EdgeCase_Settings_fields[3];
extern const pb_field_t blox_EdgeCase_State_fields[3];
extern const pb_field_t blox_EdgeCase_NestedLink_fields[2];
extern const pb_field_t blox_EdgeCase_Block_fields[11];
extern const pb_field_t blox_EdgeCase_SubCase_fields[2];

/* Maximum encoded size of messages (where known) */
#define blox_EdgeCase_Settings_size              15
#define blox_EdgeCase_State_size                 8
#define blox_EdgeCase_NestedLink_size            6
/* blox_EdgeCase_Block_size depends on runtime parameters */
#define blox_EdgeCase_SubCase_size               6

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define EDGECASE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
