/* Automatically generated nanopb header */

#ifndef PB_BLOX_MOCKPINS_PB_H_INCLUDED
#define PB_BLOX_MOCKPINS_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

#include "IoArray.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _blox_MockPins {
    pb_size_t channels_count;
    blox_IoChannel channels[8];
/* @@protoc_insertion_point(struct:blox_MockPins) */
} blox_MockPins;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_MockPins_init_default               {0, {blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default}}
#define blox_MockPins_init_zero                  {0, {blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_MockPins_channels_tag               2

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_MockPins_fields[2];

/* Maximum encoded size of messages (where known) */
#define blox_MockPins_size                       64

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define MOCKPINS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
