/* Automatically generated nanopb header */

#ifndef PB_BLOX_TEMPSENSORMOCK_TEMPSENSORMOCK_PB_H_INCLUDED
#define PB_BLOX_TEMPSENSORMOCK_TEMPSENSORMOCK_PB_H_INCLUDED
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
typedef struct _blox_TempSensorMock_Block {
    int32_t value;
    bool connected;
    int32_t setting;
    pb_callback_t fluctuations;
/* @@protoc_insertion_point(struct:blox_TempSensorMock_Block) */
} blox_TempSensorMock_Block;

typedef struct _blox_TempSensorMock_Fluctuation {
    int32_t amplitude;
    uint32_t period;
/* @@protoc_insertion_point(struct:blox_TempSensorMock_Fluctuation) */
} blox_TempSensorMock_Fluctuation;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_TempSensorMock_Fluctuation_init_default {0, 0}
#define blox_TempSensorMock_Block_init_default   {0, 0, 0, {{NULL}, NULL}}
#define blox_TempSensorMock_Fluctuation_init_zero {0, 0}
#define blox_TempSensorMock_Block_init_zero      {0, 0, 0, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define blox_TempSensorMock_Block_value_tag      1
#define blox_TempSensorMock_Block_connected_tag  3
#define blox_TempSensorMock_Block_setting_tag    4
#define blox_TempSensorMock_Block_fluctuations_tag 5
#define blox_TempSensorMock_Fluctuation_amplitude_tag 1
#define blox_TempSensorMock_Fluctuation_period_tag 2

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_TempSensorMock_Fluctuation_fields[3];
extern const pb_field_t blox_TempSensorMock_Block_fields[5];

/* Maximum encoded size of messages (where known) */
#define blox_TempSensorMock_Fluctuation_size     12
/* blox_TempSensorMock_Block_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TEMPSENSORMOCK_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
