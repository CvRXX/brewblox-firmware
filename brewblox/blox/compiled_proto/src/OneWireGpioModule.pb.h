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
    blox_GpioDeviceType_NONE = 0,
    blox_GpioDeviceType_TWO_PIN_SSR = 1,
    blox_GpioDeviceType_ONE_PIN_SSR = 2,
    blox_GpioDeviceType_SINGLE_PIN_COIL_TO_EXTERNAL_GND = 3,
    blox_GpioDeviceType_SINGLE_PIN_COIL_TO_EXTERNAL_PWR = 4,
    blox_GpioDeviceType_TWO_PIN_COIL = 5,
    blox_GpioDeviceType_TWO_PIN_COIL_PUSH_PULL = 6,
    blox_GpioDeviceType_TWO_PIN_MOTOR_UNIDIRECTIONAL = 7,
    blox_GpioDeviceType_SINGLE_PIN_MOTOR_HIGH_SIDE = 8,
    blox_GpioDeviceType_SINGLE_PIN_MOTOR_LOW_SIDE = 9,
    blox_GpioDeviceType_TWO_PIN_MOTOR_BIDIRECTIONAL = 10,
    blox_GpioDeviceType_TWO_PIN_SWITCH_INPUT = 11,
    blox_GpioDeviceType_SWITCH_TO_EXTERNAL_GND = 12,
    blox_GpioDeviceType_SWITCH_TO_PWR = 13,
    blox_GpioDeviceType_POWERED_SWITCH_TO_EXTERNAL_GND = 14,
    blox_GpioDeviceType_POWERED_SWITCH_TO_EXTERNAL_PWR = 15
} blox_GpioDeviceType;
#define _blox_GpioDeviceType_MIN blox_GpioDeviceType_NONE
#define _blox_GpioDeviceType_MAX blox_GpioDeviceType_POWERED_SWITCH_TO_EXTERNAL_PWR
#define _blox_GpioDeviceType_ARRAYSIZE ((blox_GpioDeviceType)(blox_GpioDeviceType_POWERED_SWITCH_TO_EXTERNAL_PWR+1))

typedef enum _blox_ChannelStatus {
    blox_ChannelStatus_UNKNOWN = 0,
    blox_ChannelStatus_OPERATIONAL = 1,
    blox_ChannelStatus_OVERCURRENT = 2,
    blox_ChannelStatus_OPEN_LOAD = 3,
    blox_ChannelStatus_UNDERVOLTAGE = 4,
    blox_ChannelStatus_OVERVOLTAGE = 5,
    blox_ChannelStatus_OVERTEMPERATURE_SHUTDOWN = 6,
    blox_ChannelStatus_OVERTEMPERATURE_WARNING = 7,
    blox_ChannelStatus_POWER_ON_RESET = 8,
    blox_ChannelStatus_SPI_ERROR = 9
} blox_ChannelStatus;
#define _blox_ChannelStatus_MIN blox_ChannelStatus_UNKNOWN
#define _blox_ChannelStatus_MAX blox_ChannelStatus_SPI_ERROR
#define _blox_ChannelStatus_ARRAYSIZE ((blox_ChannelStatus)(blox_ChannelStatus_SPI_ERROR+1))

/* Struct definitions */
typedef struct _blox_GpioModuleChannel {
    uint8_t id;
    blox_GpioDeviceType deviceType;
    uint8_t pinsMask;
    blox_ChannelStatus status;
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
    uint8_t pullUpOverCurrent;
    uint8_t pullDownOverCurrent;
    uint8_t pullUpOpenLoad;
    uint8_t pullDownOpenLoad;
    uint8_t moduleStatusClear;
/* @@protoc_insertion_point(struct:blox_OneWireGpioModule) */
} blox_OneWireGpioModule;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_GpioModuleChannel_init_default      {0, _blox_GpioDeviceType_MIN, 0, _blox_ChannelStatus_MIN, _blox_ChannelConfig_MIN, _blox_DigitalState_MIN, 0}
#define blox_OneWireGpioModule_init_default      {0, {blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default, blox_GpioModuleChannel_init_default}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define blox_GpioModuleChannel_init_zero         {0, _blox_GpioDeviceType_MIN, 0, _blox_ChannelStatus_MIN, _blox_ChannelConfig_MIN, _blox_DigitalState_MIN, 0}
#define blox_OneWireGpioModule_init_zero         {0, {blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero, blox_GpioModuleChannel_init_zero}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_GpioModuleChannel_id_tag            1
#define blox_GpioModuleChannel_deviceType_tag    2
#define blox_GpioModuleChannel_pinsMask_tag      3
#define blox_GpioModuleChannel_status_tag        4
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
#define blox_OneWireGpioModule_pullUpOverCurrent_tag 12
#define blox_OneWireGpioModule_pullDownOverCurrent_tag 13
#define blox_OneWireGpioModule_pullUpOpenLoad_tag 14
#define blox_OneWireGpioModule_pullDownOpenLoad_tag 15
#define blox_OneWireGpioModule_moduleStatusClear_tag 16

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_GpioModuleChannel_fields[8];
extern const pb_field_t blox_OneWireGpioModule_fields[17];

/* Maximum encoded size of messages (where known) */
#define blox_GpioModuleChannel_size              32
#define blox_OneWireGpioModule_size              363

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ONEWIREGPIOMODULE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
