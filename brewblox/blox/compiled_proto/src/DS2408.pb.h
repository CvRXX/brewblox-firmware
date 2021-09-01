/* Automatically generated nanopb header */

#ifndef PB_BLOX_DS2408_PB_H_INCLUDED
#define PB_BLOX_DS2408_PB_H_INCLUDED
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
typedef enum _blox_DS2408_PinConnectMode {
    blox_DS2408_PinConnectMode_CONNECT_VALVE = 0,
    blox_DS2408_PinConnectMode_CONNECT_ACTUATOR = 1
} blox_DS2408_PinConnectMode;
#define _blox_DS2408_PinConnectMode_MIN blox_DS2408_PinConnectMode_CONNECT_VALVE
#define _blox_DS2408_PinConnectMode_MAX blox_DS2408_PinConnectMode_CONNECT_ACTUATOR
#define _blox_DS2408_PinConnectMode_ARRAYSIZE ((blox_DS2408_PinConnectMode)(blox_DS2408_PinConnectMode_CONNECT_ACTUATOR+1))

/* Struct definitions */
typedef struct _blox_DS2408 {
    uint64_t address;
    bool connected;
    blox_DS2408_PinConnectMode connectMode;
    uint16_t oneWireBusId;
    pb_size_t channels_count;
    blox_IoChannel channels[8];
/* @@protoc_insertion_point(struct:blox_DS2408) */
} blox_DS2408;

typedef struct _blox_DS2408IoPin {
    pb_size_t which_Pin;
    union {
        blox_IoChannel A;
        blox_IoChannel B;
        blox_IoChannel C;
        blox_IoChannel D;
        blox_IoChannel E;
        blox_IoChannel F;
        blox_IoChannel G;
        blox_IoChannel H;
    } Pin;
/* @@protoc_insertion_point(struct:blox_DS2408IoPin) */
} blox_DS2408IoPin;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_DS2408IoPin_init_default            {0, {blox_IoChannel_init_default}}
#define blox_DS2408_init_default                 {0, 0, _blox_DS2408_PinConnectMode_MIN, 0, 0, {blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default, blox_IoChannel_init_default}}
#define blox_DS2408IoPin_init_zero               {0, {blox_IoChannel_init_zero}}
#define blox_DS2408_init_zero                    {0, 0, _blox_DS2408_PinConnectMode_MIN, 0, 0, {blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero, blox_IoChannel_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_DS2408_address_tag                  1
#define blox_DS2408_connected_tag                6
#define blox_DS2408_connectMode_tag              9
#define blox_DS2408_oneWireBusId_tag             10
#define blox_DS2408_channels_tag                 11
#define blox_DS2408IoPin_A_tag                   1
#define blox_DS2408IoPin_B_tag                   2
#define blox_DS2408IoPin_C_tag                   3
#define blox_DS2408IoPin_D_tag                   4
#define blox_DS2408IoPin_E_tag                   5
#define blox_DS2408IoPin_F_tag                   6
#define blox_DS2408IoPin_G_tag                   7
#define blox_DS2408IoPin_H_tag                   8

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_DS2408IoPin_fields[9];
extern const pb_field_t blox_DS2408_fields[6];

/* Maximum encoded size of messages (where known) */
#define blox_DS2408IoPin_size                    8
#define blox_DS2408_size                         83

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DS2408_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
