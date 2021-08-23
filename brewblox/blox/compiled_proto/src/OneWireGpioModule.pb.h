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

/* Enum definitions */
typedef enum _blox_GpioDeviceType {
    blox_GpioDeviceType_GPIO_DEV_NONE = 0,
    blox_GpioDeviceType_GPIO_DEV_SSR_2P = 1,
    blox_GpioDeviceType_GPIO_DEV_SSR_1P = 2,
    blox_GpioDeviceType_GPIO_DEV_COIL_UNIDIRECTIONAL_2P = 3,
    blox_GpioDeviceType_GPIO_DEV_COIL_BIDIRECTIONAL_2P = 4,
    blox_GpioDeviceType_GPIO_DEV_COIL_HIGH_SIDE_1P = 5,
    blox_GpioDeviceType_GPIO_DEV_COIL_LOW_SIDE_1P = 6,
    blox_GpioDeviceType_GPIO_DEV_MOTOR_UNIDIRECTIONAL_2P = 7,
    blox_GpioDeviceType_GPIO_DEV_MOTOR_BIDIRECTIONAL_2P = 8,
    blox_GpioDeviceType_GPIO_DEV_MOTOR_HIGH_SIDE_1P = 9,
    blox_GpioDeviceType_GPIO_DEV_MOTOR_LOW_SIDE_1P = 10,
    blox_GpioDeviceType_GPIO_DEV_LOAD_DETECT_2P = 11,
    blox_GpioDeviceType_GPIO_DEV_LOAD_DETECT_PULL_DOWN_1P = 12,
    blox_GpioDeviceType_GPIO_DEV_LOAD_DETECT_PULL_UP_1P = 13,
    blox_GpioDeviceType_GPIO_DEV_POWER_LOAD_DETECT_1P = 14,
    blox_GpioDeviceType_GPIO_DEV_GND_LOAD_DETECT_1P = 15,
    blox_GpioDeviceType_GPIO_DEV_POWER_1P = 16,
    blox_GpioDeviceType_GPIO_DEV_GND_1P = 17
} blox_GpioDeviceType;
#define _blox_GpioDeviceType_MIN blox_GpioDeviceType_GPIO_DEV_NONE
#define _blox_GpioDeviceType_MAX blox_GpioDeviceType_GPIO_DEV_GND_1P
#define _blox_GpioDeviceType_ARRAYSIZE ((blox_GpioDeviceType)(blox_GpioDeviceType_GPIO_DEV_GND_1P+1))

typedef enum _blox_GpioErrorFlags {
    blox_GpioErrorFlags_GPIO_ERR_NONE = 0,
    blox_GpioErrorFlags_GPIO_ERR_POWER_ON_RESET = 1,
    blox_GpioErrorFlags_GPIO_ERR_OVERVOLTAGE = 2,
    blox_GpioErrorFlags_GPIO_ERR_UNDERVOLTAGE = 4,
    blox_GpioErrorFlags_GPIO_ERR_OVERCURRENT = 8,
    blox_GpioErrorFlags_GPIO_ERR_OPEN_LOAD = 16,
    blox_GpioErrorFlags_GPIO_ERR_OVERTEMPERATURE_WARNING = 32,
    blox_GpioErrorFlags_GPIO_ERR_OVERTEMPERATURE_ERROR = 64,
    blox_GpioErrorFlags_GPIO_ERR_SPI_ERROR = 128
} blox_GpioErrorFlags;
#define _blox_GpioErrorFlags_MIN blox_GpioErrorFlags_GPIO_ERR_NONE
#define _blox_GpioErrorFlags_MAX blox_GpioErrorFlags_GPIO_ERR_SPI_ERROR
#define _blox_GpioErrorFlags_ARRAYSIZE ((blox_GpioErrorFlags)(blox_GpioErrorFlags_GPIO_ERR_SPI_ERROR+1))

/* Struct definitions */
typedef struct _blox_GpioModuleChannel {
    uint8_t id;
    blox_GpioDeviceType deviceType;
    uint8_t pinsMask;
    blox_ChannelConfig config;
    blox_DigitalState state;
    int16_t pwmDuty;
/* @@protoc_insertion_point(struct:blox_GpioModuleChannel) */
} blox_GpioModuleChannel;

typedef struct _blox_OneWireGpioModule {
    pb_size_t channels_count;
    blox_GpioModuleChannel channels[8];
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
    uint8_t moduleStatusClear;
/* @@protoc_insertion_point(struct:blox_OneWireGpioModule) */
} blox_OneWireGpioModule;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_GpioModuleChannel_init_default      {0, _blox_GpioDeviceType_MIN, 0, _blox_ChannelConfig_MIN, _blox_DigitalState_MIN, 0}
#define blox_OneWireGpioModule_init_default      {0, {blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define blox_GpioModuleChannel_init_zero         {0, _blox_GpioDeviceType_MIN, 0, _blox_ChannelConfig_MIN, _blox_DigitalState_MIN, 0}
#define blox_OneWireGpioModule_init_zero         {0, {blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_GpioModuleChannel_id_tag            1
#define blox_GpioModuleChannel_deviceType_tag    2
#define blox_GpioModuleChannel_pinsMask_tag      3
#define blox_GpioModuleChannel_config_tag        5
#define blox_GpioModuleChannel_state_tag         6
#define blox_GpioModuleChannel_pwmDuty_tag       7
#define blox_OneWireGpioModule_channels_tag      1
#define blox_OneWireGpioModule_modulePosition_tag 2
#define blox_OneWireGpioModule_moduleStatus_tag  3
#define blox_OneWireGpioModule_pullUpDesired_tag 4
#define blox_OneWireGpioModule_pullUpStatus_tag  5
#define blox_OneWireGpioModule_pullUpWhenActive_tag 6
#define blox_OneWireGpioModule_pullUpWhenInactive_tag 7
#define blox_OneWireGpioModule_pullDownDesired_tag 8
#define blox_OneWireGpioModule_pullDownStatus_tag 9
#define blox_OneWireGpioModule_pullDownWhenActive_tag 10
#define blox_OneWireGpioModule_pullDownWhenInactive_tag 11
#define blox_OneWireGpioModule_overCurrent_tag   12
#define blox_OneWireGpioModule_openLoad_tag      13
#define blox_OneWireGpioModule_moduleStatusClear_tag 16

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_GpioModuleChannel_fields[7];
extern const pb_field_t blox_OneWireGpioModule_fields[15];

/* Maximum encoded size of messages (where known) */
#define blox_GpioModuleChannel_size              30
#define blox_OneWireGpioModule_size              335

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ONEWIREGPIOMODULE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
