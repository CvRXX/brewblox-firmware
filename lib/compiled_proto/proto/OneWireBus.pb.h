/* Automatically generated nanopb header */

#ifndef PB_BLOX_ONEWIREBUS_ONEWIREBUS_PB_H_INCLUDED
#define PB_BLOX_ONEWIREBUS_ONEWIREBUS_PB_H_INCLUDED
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
typedef struct _blox_OneWireBus_Command {
    uint8_t opcode;
    uint8_t data;
/* @@protoc_insertion_point(struct:blox_OneWireBus_Command) */
} blox_OneWireBus_Command;

typedef struct _blox_OneWireBus_Block {
    blox_OneWireBus_Command command;
    pb_callback_t address;
/* @@protoc_insertion_point(struct:blox_OneWireBus_Block) */
} blox_OneWireBus_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_OneWireBus_Command_init_default     {0, 0}
#define blox_OneWireBus_Block_init_default       {blox_OneWireBus_Command_init_default, {{NULL}, NULL}}
#define blox_OneWireBus_Command_init_zero        {0, 0}
#define blox_OneWireBus_Block_init_zero          {blox_OneWireBus_Command_init_zero, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_OneWireBus_Command_opcode_tag       1
#define blox_OneWireBus_Command_data_tag         2
#define blox_OneWireBus_Block_command_tag        1
#define blox_OneWireBus_Block_address_tag        2

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_OneWireBus_Command_fields[3];
extern const pb_field_t blox_OneWireBus_Block_fields[3];

/* Maximum encoded size of messages (where known) */
#define blox_OneWireBus_Command_size             12
/* blox_OneWireBus_Block_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ONEWIREBUS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
