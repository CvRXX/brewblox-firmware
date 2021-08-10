/* Automatically generated nanopb header */

#ifndef PB_BLOX_ONEWIREGPIOMODULE_PB_H_INCLUDED
#define PB_BLOX_ONEWIREGPIOMODULE_PB_H_INCLUDED
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
typedef struct _blox_GpioChannel {
    uint8_t id;
    blox_ChannelConfig config;
    uint16_t pins;
    uint16_t whenActive;
    uint16_t whenInactive;
    uint8_t pwmDuty;
/* @@protoc_insertion_point(struct:blox_GpioChannel) */
} blox_GpioChannel;

typedef struct _blox_OneWireGpioModule {
    pb_size_t channels_count;
    blox_GpioChannel channels[8];
    uint8_t modulePosition;
    uint8_t status;
    uint16_t drive;
    uint16_t overCurrent;
    uint16_t openLoad;
/* @@protoc_insertion_point(struct:blox_OneWireGpioModule) */
} blox_OneWireGpioModule;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_GpioChannel_init_default            {0, _blox_ChannelConfig_MIN, 0, 0, 0, 0}
#define blox_OneWireGpioModule_init_default      {0, {blox_GpioChannel_init_default, blox_GpioChannel_init_default, blox_GpioChannel_init_default, blox_GpioChannel_init_default, blox_GpioChannel_init_default, blox_GpioChannel_init_default, blox_GpioChannel_init_default, blox_GpioChannel_init_default}, 0, 0, 0, 0, 0}
#define blox_GpioChannel_init_zero               {0, _blox_ChannelConfig_MIN, 0, 0, 0, 0}
#define blox_OneWireGpioModule_init_zero         {0, {blox_GpioChannel_init_zero, blox_GpioChannel_init_zero, blox_GpioChannel_init_zero, blox_GpioChannel_init_zero, blox_GpioChannel_init_zero, blox_GpioChannel_init_zero, blox_GpioChannel_init_zero, blox_GpioChannel_init_zero}, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_GpioChannel_id_tag                  1
#define blox_GpioChannel_config_tag              2
#define blox_GpioChannel_pins_tag                3
#define blox_GpioChannel_whenActive_tag          4
#define blox_GpioChannel_whenInactive_tag        5
#define blox_GpioChannel_pwmDuty_tag             6
#define blox_OneWireGpioModule_channels_tag      1
#define blox_OneWireGpioModule_modulePosition_tag 2
#define blox_OneWireGpioModule_status_tag        3
#define blox_OneWireGpioModule_drive_tag         4
#define blox_OneWireGpioModule_overCurrent_tag   5
#define blox_OneWireGpioModule_openLoad_tag      6

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_GpioChannel_fields[7];
extern const pb_field_t blox_OneWireGpioModule_fields[7];

/* Maximum encoded size of messages (where known) */
#define blox_GpioChannel_size                    33
#define blox_OneWireGpioModule_size              310

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ONEWIREGPIOMODULE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
