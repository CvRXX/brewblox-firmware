/* Automatically generated nanopb header */

#ifndef PB_BLOX_SPARK2PINS_PB_H_INCLUDED
#define PB_BLOX_SPARK2PINS_PB_H_INCLUDED
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

/* Enum definitions */
typedef enum _blox_Spark2Pins_Hardware {
    blox_Spark2Pins_Hardware_HW_UNKNOWN = 0,
    blox_Spark2Pins_Hardware_HW_SPARK1 = 1,
    blox_Spark2Pins_Hardware_HW_SPARK2 = 2
} blox_Spark2Pins_Hardware;
#define _blox_Spark2Pins_Hardware_MIN blox_Spark2Pins_Hardware_HW_UNKNOWN
#define _blox_Spark2Pins_Hardware_MAX blox_Spark2Pins_Hardware_HW_SPARK2
#define _blox_Spark2Pins_Hardware_ARRAYSIZE ((blox_Spark2Pins_Hardware)(blox_Spark2Pins_Hardware_HW_SPARK2+1))

/* Struct definitions */
typedef struct _blox_Spark2PinsIoPin {
    pb_size_t which_Pin;
    union {
        blox_IoChannel bottom1;
        blox_IoChannel bottom2;
        blox_IoChannel bottom3;
        blox_IoChannel bottom0;
    } Pin;
/* @@protoc_insertion_point(struct:blox_Spark2PinsIoPin) */
} blox_Spark2PinsIoPin;

typedef struct _blox_Spark2Pins {
    pb_size_t pins_count;
    blox_Spark2PinsIoPin pins[4];
    bool soundAlarm;
    blox_Spark2Pins_Hardware hardware;
/* @@protoc_insertion_point(struct:blox_Spark2Pins) */
} blox_Spark2Pins;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_Spark2PinsIoPin_init_default        {0, {blox_IoChannel_init_default}}
#define blox_Spark2Pins_init_default             {0, {blox_Spark2PinsIoPin_init_default, blox_Spark2PinsIoPin_init_default, blox_Spark2PinsIoPin_init_default, blox_Spark2PinsIoPin_init_default}, 0, _blox_Spark2Pins_Hardware_MIN}
#define blox_Spark2PinsIoPin_init_zero           {0, {blox_IoChannel_init_zero}}
#define blox_Spark2Pins_init_zero                {0, {blox_Spark2PinsIoPin_init_zero, blox_Spark2PinsIoPin_init_zero, blox_Spark2PinsIoPin_init_zero, blox_Spark2PinsIoPin_init_zero}, 0, _blox_Spark2Pins_Hardware_MIN}

/* Field tags (for use in manual encoding/decoding) */
#define blox_Spark2PinsIoPin_bottom1_tag         1
#define blox_Spark2PinsIoPin_bottom2_tag         2
#define blox_Spark2PinsIoPin_bottom3_tag         3
#define blox_Spark2PinsIoPin_bottom0_tag         4
#define blox_Spark2Pins_pins_tag                 1
#define blox_Spark2Pins_soundAlarm_tag           5
#define blox_Spark2Pins_hardware_tag             8

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_Spark2PinsIoPin_fields[5];
extern const pb_field_t blox_Spark2Pins_fields[4];

/* Maximum encoded size of messages (where known) */
#define blox_Spark2PinsIoPin_size                7
#define blox_Spark2Pins_size                     40

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SPARK2PINS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
