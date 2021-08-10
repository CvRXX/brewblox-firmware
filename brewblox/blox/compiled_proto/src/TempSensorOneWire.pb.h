/* Automatically generated nanopb header */

#ifndef PB_BLOX_TEMPSENSORONEWIRE_PB_H_INCLUDED
#define PB_BLOX_TEMPSENSORONEWIRE_PB_H_INCLUDED
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
typedef struct _blox_TempSensorOneWire {
    int32_t value;
    int32_t offset;
    uint64_t address;
    uint16_t oneWireBusId;
    pb_size_t strippedFields_count;
    uint16_t strippedFields[1];
/* @@protoc_insertion_point(struct:blox_TempSensorOneWire) */
} blox_TempSensorOneWire;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_TempSensorOneWire_init_default      {0, 0, 0, 0, 0, {0}}
#define blox_TempSensorOneWire_init_zero         {0, 0, 0, 0, 0, {0}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_TempSensorOneWire_value_tag         1
#define blox_TempSensorOneWire_offset_tag        3
#define blox_TempSensorOneWire_address_tag       4
#define blox_TempSensorOneWire_oneWireBusId_tag  5
#define blox_TempSensorOneWire_strippedFields_tag 99

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_TempSensorOneWire_fields[6];

/* Maximum encoded size of messages (where known) */
#define blox_TempSensorOneWire_size              35

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TEMPSENSORONEWIRE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
