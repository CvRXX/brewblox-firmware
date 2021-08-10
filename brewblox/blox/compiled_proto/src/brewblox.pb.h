/* Automatically generated nanopb header */

#ifndef PB_BREWBLOX_PB_H_INCLUDED
#define PB_BREWBLOX_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _BrewBloxTypes_UnitType {
    BrewBloxTypes_UnitType_NotSet = 0,
    BrewBloxTypes_UnitType_Celsius = 1,
    BrewBloxTypes_UnitType_InverseCelsius = 2,
    BrewBloxTypes_UnitType_Second = 3,
    BrewBloxTypes_UnitType_Minute = 4,
    BrewBloxTypes_UnitType_Hour = 5,
    BrewBloxTypes_UnitType_DeltaCelsius = 6,
    BrewBloxTypes_UnitType_DeltaCelsiusPerSecond = 7,
    BrewBloxTypes_UnitType_DeltaCelsiusPerMinute = 8,
    BrewBloxTypes_UnitType_DeltaCelsiusPerHour = 9,
    BrewBloxTypes_UnitType_DeltaCelsiusMultSecond = 10,
    BrewBloxTypes_UnitType_DeltaCelsiusMultMinute = 11,
    BrewBloxTypes_UnitType_DeltaCelsiusMultHour = 12
} BrewBloxTypes_UnitType;
#define _BrewBloxTypes_UnitType_MIN BrewBloxTypes_UnitType_NotSet
#define _BrewBloxTypes_UnitType_MAX BrewBloxTypes_UnitType_DeltaCelsiusMultHour
#define _BrewBloxTypes_UnitType_ARRAYSIZE ((BrewBloxTypes_UnitType)(BrewBloxTypes_UnitType_DeltaCelsiusMultHour+1))

typedef enum _BrewBloxTypes_BlockType {
    BrewBloxTypes_BlockType_Invalid = 0,
    BrewBloxTypes_BlockType_ProcessValueInterface = 1,
    BrewBloxTypes_BlockType_TempSensorInterface = 2,
    BrewBloxTypes_BlockType_SetpointSensorPairInterface = 4,
    BrewBloxTypes_BlockType_ActuatorAnalogInterface = 5,
    BrewBloxTypes_BlockType_ActuatorDigitalInterface = 6,
    BrewBloxTypes_BlockType_BalancerInterface = 7,
    BrewBloxTypes_BlockType_MutexInterface = 8,
    BrewBloxTypes_BlockType_OneWireDeviceInterface = 9,
    BrewBloxTypes_BlockType_IoArrayInterface = 10,
    BrewBloxTypes_BlockType_DS2408Interface = 11,
    BrewBloxTypes_BlockType_OneWireBusInterface = 12,
    BrewBloxTypes_BlockType_IoModuleInterface = 13,
    BrewBloxTypes_BlockType_OneWireDeviceBlockInterface = 14,
    BrewBloxTypes_BlockType_Any = 255,
    BrewBloxTypes_BlockType_SysInfo = 256,
    BrewBloxTypes_BlockType_Ticks = 257,
    BrewBloxTypes_BlockType_OneWireBus = 258,
    BrewBloxTypes_BlockType_BoardPins = 259,
    BrewBloxTypes_BlockType_TempSensorMock = 301,
    BrewBloxTypes_BlockType_TempSensorOneWire = 302,
    BrewBloxTypes_BlockType_SetpointSensorPair = 303,
    BrewBloxTypes_BlockType_Pid = 304,
    BrewBloxTypes_BlockType_ActuatorAnalogMock = 305,
    BrewBloxTypes_BlockType_ActuatorPin = 306,
    BrewBloxTypes_BlockType_ActuatorPwm = 307,
    BrewBloxTypes_BlockType_ActuatorOffset = 308,
    BrewBloxTypes_BlockType_Balancer = 309,
    BrewBloxTypes_BlockType_Mutex = 310,
    BrewBloxTypes_BlockType_SetpointProfile = 311,
    BrewBloxTypes_BlockType_WiFiSettings = 312,
    BrewBloxTypes_BlockType_TouchSettings = 313,
    BrewBloxTypes_BlockType_DisplaySettings = 314,
    BrewBloxTypes_BlockType_DS2413 = 315,
    BrewBloxTypes_BlockType_ActuatorOneWire = 316,
    BrewBloxTypes_BlockType_DS2408 = 317,
    BrewBloxTypes_BlockType_DigitalActuator = 318,
    BrewBloxTypes_BlockType_Spark3Pins = 319,
    BrewBloxTypes_BlockType_Spark2Pins = 320,
    BrewBloxTypes_BlockType_MotorValve = 321,
    BrewBloxTypes_BlockType_ActuatorLogic = 322,
    BrewBloxTypes_BlockType_MockPins = 323,
    BrewBloxTypes_BlockType_TempSensorCombi = 324,
    BrewBloxTypes_BlockType_OneWireGpioModule = 325
} BrewBloxTypes_BlockType;
#define _BrewBloxTypes_BlockType_MIN BrewBloxTypes_BlockType_Invalid
#define _BrewBloxTypes_BlockType_MAX BrewBloxTypes_BlockType_OneWireGpioModule
#define _BrewBloxTypes_BlockType_ARRAYSIZE ((BrewBloxTypes_BlockType)(BrewBloxTypes_BlockType_OneWireGpioModule+1))

/* Struct definitions */
typedef struct _BrewBloxTypes {
    char dummy_field;
/* @@protoc_insertion_point(struct:BrewBloxTypes) */
} BrewBloxTypes;

/* Default values for struct fields */

/* Initializer values for message structs */
#define BrewBloxTypes_init_default               {0}
#define BrewBloxTypes_init_zero                  {0}

/* Field tags (for use in manual encoding/decoding) */

/* Struct field encoding specification for nanopb */
extern const pb_field_t BrewBloxTypes_fields[1];

/* Maximum encoded size of messages (where known) */
#define BrewBloxTypes_size                       0

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define BREWBLOX_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
