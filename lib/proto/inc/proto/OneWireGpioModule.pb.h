/* Automatically generated nanopb header */

#ifndef PB_BLOX_ONEWIREGPIOMODULE_ONEWIREGPIOMODULE_PB_H_INCLUDED
#define PB_BLOX_ONEWIREGPIOMODULE_ONEWIREGPIOMODULE_PB_H_INCLUDED
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
typedef enum _blox_OneWireGpioModule_GpioDeviceType {
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_NONE = 0,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_2P = 1,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_SSR_1P = 2,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MECHANICAL_RELAY_2P = 3,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MECHANICAL_RELAY_1P_HIGH_SIDE = 4,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MECHANICAL_RELAY_1P_LOW_SIDE = 5,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_2P = 6,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_2P_BIDIRECTIONAL = 7,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_1P_HIGH_SIDE = 8,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_COIL_1P_LOW_SIDE = 9,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_2P = 10,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_2P_BIDIRECTIONAL = 11,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_1P_HIGH_SIDE = 12,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_MOTOR_1P_LOW_SIDE = 13,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_LOAD_DETECT_2P = 14,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_LOAD_DETECT_1P_PULL_DOWN = 15,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_LOAD_DETECT_1P_PULL_UP = 16,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_POWER_1P = 17,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_POWER_1P_LOAD_DETECT = 18,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_GND_1P = 19,
    blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_GND_1P_LOAD_DETECT = 20
} blox_OneWireGpioModule_GpioDeviceType;
#define _blox_OneWireGpioModule_GpioDeviceType_MIN blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_NONE
#define _blox_OneWireGpioModule_GpioDeviceType_MAX blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_GND_1P_LOAD_DETECT
#define _blox_OneWireGpioModule_GpioDeviceType_ARRAYSIZE ((blox_OneWireGpioModule_GpioDeviceType)(blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_GND_1P_LOAD_DETECT+1))

typedef enum _blox_OneWireGpioModule_GpioErrorFlags {
    blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_NONE = 0,
    blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_POWER_ON_RESET = 1,
    blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_OVERVOLTAGE = 2,
    blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_UNDERVOLTAGE = 4,
    blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_OVERCURRENT = 8,
    blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_OPEN_LOAD = 16,
    blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_OVERTEMPERATURE_WARNING = 32,
    blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_OVERTEMPERATURE_ERROR = 64,
    blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_SPI_ERROR = 128
} blox_OneWireGpioModule_GpioErrorFlags;
#define _blox_OneWireGpioModule_GpioErrorFlags_MIN blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_NONE
#define _blox_OneWireGpioModule_GpioErrorFlags_MAX blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_SPI_ERROR
#define _blox_OneWireGpioModule_GpioErrorFlags_ARRAYSIZE ((blox_OneWireGpioModule_GpioErrorFlags)(blox_OneWireGpioModule_GpioErrorFlags_GPIO_ERR_SPI_ERROR+1))

/* Struct definitions */
typedef struct _blox_OneWireGpioModule_GpioModuleChannel {
    uint8_t id;
    blox_OneWireGpioModule_GpioDeviceType deviceType;
    uint8_t pinsMask;
    uint8_t width;
    char name[32];
    uint16_t capabilities;
/* @@protoc_insertion_point(struct:blox_OneWireGpioModule_GpioModuleChannel) */
} blox_OneWireGpioModule_GpioModuleChannel;

typedef struct _blox_OneWireGpioModule_Block {
    pb_size_t channels_count;
    blox_OneWireGpioModule_GpioModuleChannel channels[8];
    uint8_t modulePosition;
    uint8_t moduleStatus;
    uint8_t pullUpDesired;
    uint8_t pullUpStatus;
    uint8_t pullUpWhenActive;
    uint8_t pullUpWhenInactive;
    uint8_t pullDownDesired;
    uint8_t pullDownStatus;
    uint8_t pullDownWhenActive;
    uint8_t pullDownWhenInactive;
    uint8_t overCurrent;
    uint8_t openLoad;
    bool useExternalPower;
    uint8_t moduleStatusClear;
/* @@protoc_insertion_point(struct:blox_OneWireGpioModule_Block) */
} blox_OneWireGpioModule_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_OneWireGpioModule_GpioModuleChannel_init_default {0, _blox_OneWireGpioModule_GpioDeviceType_MIN, 0, 0, "", 0}
#define blox_OneWireGpioModule_Block_init_default {0, {blox_OneWireGpioModule_GpioModuleChannel_init_default, blox_OneWireGpioModule_GpioModuleChannel_init_default, blox_OneWireGpioModule_GpioModuleChannel_init_default, blox_OneWireGpioModule_GpioModuleChannel_init_default, blox_OneWireGpioModule_GpioModuleChannel_init_default, blox_OneWireGpioModule_GpioModuleChannel_init_default, blox_OneWireGpioModule_GpioModuleChannel_init_default, blox_OneWireGpioModule_GpioModuleChannel_init_default}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define blox_OneWireGpioModule_GpioModuleChannel_init_zero {0, _blox_OneWireGpioModule_GpioDeviceType_MIN, 0, 0, "", 0}
#define blox_OneWireGpioModule_Block_init_zero   {0, {blox_OneWireGpioModule_GpioModuleChannel_init_zero, blox_OneWireGpioModule_GpioModuleChannel_init_zero, blox_OneWireGpioModule_GpioModuleChannel_init_zero, blox_OneWireGpioModule_GpioModuleChannel_init_zero, blox_OneWireGpioModule_GpioModuleChannel_init_zero, blox_OneWireGpioModule_GpioModuleChannel_init_zero, blox_OneWireGpioModule_GpioModuleChannel_init_zero, blox_OneWireGpioModule_GpioModuleChannel_init_zero}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_OneWireGpioModule_GpioModuleChannel_id_tag 1
#define blox_OneWireGpioModule_GpioModuleChannel_deviceType_tag 2
#define blox_OneWireGpioModule_GpioModuleChannel_pinsMask_tag 3
#define blox_OneWireGpioModule_GpioModuleChannel_width_tag 4
#define blox_OneWireGpioModule_GpioModuleChannel_name_tag 5
#define blox_OneWireGpioModule_GpioModuleChannel_capabilities_tag 6
#define blox_OneWireGpioModule_Block_channels_tag 1
#define blox_OneWireGpioModule_Block_modulePosition_tag 2
#define blox_OneWireGpioModule_Block_moduleStatus_tag 3
#define blox_OneWireGpioModule_Block_pullUpDesired_tag 4
#define blox_OneWireGpioModule_Block_pullUpStatus_tag 5
#define blox_OneWireGpioModule_Block_pullUpWhenActive_tag 6
#define blox_OneWireGpioModule_Block_pullUpWhenInactive_tag 7
#define blox_OneWireGpioModule_Block_pullDownDesired_tag 8
#define blox_OneWireGpioModule_Block_pullDownStatus_tag 9
#define blox_OneWireGpioModule_Block_pullDownWhenActive_tag 10
#define blox_OneWireGpioModule_Block_pullDownWhenInactive_tag 11
#define blox_OneWireGpioModule_Block_overCurrent_tag 12
#define blox_OneWireGpioModule_Block_openLoad_tag 13
#define blox_OneWireGpioModule_Block_useExternalPower_tag 14
#define blox_OneWireGpioModule_Block_moduleStatusClear_tag 32

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_OneWireGpioModule_GpioModuleChannel_fields[7];
extern const pb_field_t blox_OneWireGpioModule_Block_fields[16];

/* Maximum encoded size of messages (where known) */
#define blox_OneWireGpioModule_GpioModuleChannel_size 60
#define blox_OneWireGpioModule_Block_size        577

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ONEWIREGPIOMODULE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
