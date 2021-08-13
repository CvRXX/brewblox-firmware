/* Automatically generated nanopb header */

#ifndef PB_BLOX_SPARK3PINS_PB_H_INCLUDED
#define PB_BLOX_SPARK3PINS_PB_H_INCLUDED
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
typedef struct _blox_Spark3IoPin {
    pb_size_t which_Pin;
    union {
        blox_IoChannel top1;
        blox_IoChannel top2;
        blox_IoChannel top3;
        blox_IoChannel bottom1;
        blox_IoChannel bottom2;
    } Pin;
/* @@protoc_insertion_point(struct:blox_Spark3IoPin) */
} blox_Spark3IoPin;

typedef struct _blox_Spark3Pins {
    pb_size_t pins_count;
    blox_Spark3IoPin pins[5];
    bool enableIoSupply5V;
    bool enableIoSupply12V;
    bool soundAlarm;
    uint16_t voltage5;
    uint16_t voltage12;
/* @@protoc_insertion_point(struct:blox_Spark3Pins) */
} blox_Spark3Pins;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Spark3IoPin_init_default            {0, {blox_IoChannel_init_default}}
#define blox_Spark3Pins_init_default             {0, {blox_Spark3IoPin_init_default, blox_Spark3IoPin_init_default, blox_Spark3IoPin_init_default, blox_Spark3IoPin_init_default, blox_Spark3IoPin_init_default}, 0, 0, 0, 0, 0}
#define blox_Spark3IoPin_init_zero               {0, {blox_IoChannel_init_zero}}
#define blox_Spark3Pins_init_zero                {0, {blox_Spark3IoPin_init_zero, blox_Spark3IoPin_init_zero, blox_Spark3IoPin_init_zero, blox_Spark3IoPin_init_zero, blox_Spark3IoPin_init_zero}, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Spark3IoPin_top1_tag                1
#define blox_Spark3IoPin_top2_tag                2
#define blox_Spark3IoPin_top3_tag                3
#define blox_Spark3IoPin_bottom1_tag             4
#define blox_Spark3IoPin_bottom2_tag             5
#define blox_Spark3Pins_pins_tag                 1
#define blox_Spark3Pins_enableIoSupply5V_tag     2
#define blox_Spark3Pins_enableIoSupply12V_tag    3
#define blox_Spark3Pins_soundAlarm_tag           5
#define blox_Spark3Pins_voltage5_tag             6
#define blox_Spark3Pins_voltage12_tag            7

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Spark3IoPin_fields[6];
extern const pb_field_t blox_Spark3Pins_fields[7];

/* Maximum encoded size of messages (where known) */
#define blox_Spark3IoPin_size                    7
#define blox_Spark3Pins_size                     63

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SPARK3PINS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
