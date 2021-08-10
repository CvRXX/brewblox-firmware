/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Tue Aug 10 21:42:38 2021. */

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
typedef struct _blox_MockPinsIoPin {
    pb_size_t which_Pin;
    union {
        blox_IoChannel mock1;
        blox_IoChannel mock2;
        blox_IoChannel mock3;
        blox_IoChannel mock4;
        blox_IoChannel mock5;
        blox_IoChannel mock6;
        blox_IoChannel mock7;
        blox_IoChannel mock8;
    } Pin;
/* @@protoc_insertion_point(struct:blox_MockPinsIoPin) */
} blox_MockPinsIoPin;

typedef struct _blox_MockPins {
    pb_size_t pins_count;
    blox_MockPinsIoPin pins[8];
/* @@protoc_insertion_point(struct:blox_MockPins) */
} blox_MockPins;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_MockPinsIoPin_init_default          {0, {blox_IoChannel_init_default}}
#define blox_MockPins_init_default               {0, {blox_MockPinsIoPin_init_default, blox_MockPinsIoPin_init_default, blox_MockPinsIoPin_init_default, blox_MockPinsIoPin_init_default, blox_MockPinsIoPin_init_default, blox_MockPinsIoPin_init_default, blox_MockPinsIoPin_init_default, blox_MockPinsIoPin_init_default}}
#define blox_MockPinsIoPin_init_zero             {0, {blox_IoChannel_init_zero}}
#define blox_MockPins_init_zero                  {0, {blox_MockPinsIoPin_init_zero, blox_MockPinsIoPin_init_zero, blox_MockPinsIoPin_init_zero, blox_MockPinsIoPin_init_zero, blox_MockPinsIoPin_init_zero, blox_MockPinsIoPin_init_zero, blox_MockPinsIoPin_init_zero, blox_MockPinsIoPin_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_MockPinsIoPin_mock1_tag             1
#define blox_MockPinsIoPin_mock2_tag             2
#define blox_MockPinsIoPin_mock3_tag             3
#define blox_MockPinsIoPin_mock4_tag             4
#define blox_MockPinsIoPin_mock5_tag             5
#define blox_MockPinsIoPin_mock6_tag             6
#define blox_MockPinsIoPin_mock7_tag             7
#define blox_MockPinsIoPin_mock8_tag             8
#define blox_MockPins_pins_tag                   1

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_MockPinsIoPin_fields[9];
extern const pb_field_t blox_MockPins_fields[2];

/* Maximum encoded size of messages (where known) */
#define blox_MockPinsIoPin_size                  7
#define blox_MockPins_size                       72

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define MOCKPINS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
