/* Automatically generated nanopb header */

#ifndef PB_BREWBLOX_BREWBLOX_PB_H_INCLUDED
#define PB_BREWBLOX_BREWBLOX_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _brewblox_UnitType {
    brewblox_UnitType_NotSet = 0,
    brewblox_UnitType_Celsius = 1,
    brewblox_UnitType_InverseCelsius = 2,
    brewblox_UnitType_Second = 3,
    brewblox_UnitType_Minute = 4,
    brewblox_UnitType_Hour = 5,
    brewblox_UnitType_DeltaCelsius = 6,
    brewblox_UnitType_DeltaCelsiusPerSecond = 7,
    brewblox_UnitType_DeltaCelsiusPerMinute = 8,
    brewblox_UnitType_DeltaCelsiusPerHour = 9,
    brewblox_UnitType_DeltaCelsiusMultSecond = 10,
    brewblox_UnitType_DeltaCelsiusMultMinute = 11,
    brewblox_UnitType_DeltaCelsiusMultHour = 12
} brewblox_UnitType;
#define _brewblox_UnitType_MIN brewblox_UnitType_NotSet
#define _brewblox_UnitType_MAX brewblox_UnitType_DeltaCelsiusMultHour
#define _brewblox_UnitType_ARRAYSIZE ((brewblox_UnitType)(brewblox_UnitType_DeltaCelsiusMultHour+1))

typedef enum _brewblox_BlockType {
    brewblox_BlockType_Invalid = 0,
    brewblox_BlockType_ProcessValueInterface = 1,
    brewblox_BlockType_TempSensorInterface = 2,
    brewblox_BlockType_SetpointSensorPairInterface = 4,
    brewblox_BlockType_ActuatorAnalogInterface = 5,
    brewblox_BlockType_ActuatorDigitalInterface = 6,
    brewblox_BlockType_BalancerInterface = 7,
    brewblox_BlockType_MutexInterface = 8,
    brewblox_BlockType_OneWireDeviceInterface = 9,
    brewblox_BlockType_IoArrayInterface = 10,
    brewblox_BlockType_DS2408Interface = 11,
    brewblox_BlockType_OneWireBusInterface = 12,
    brewblox_BlockType_IoModuleInterface = 13,
    brewblox_BlockType_OneWireDeviceBlockInterface = 14,
    brewblox_BlockType_EnablerInterface = 15,
    brewblox_BlockType_Any = 255,
    brewblox_BlockType_SysInfo = 256,
    brewblox_BlockType_Ticks = 257,
    brewblox_BlockType_OneWireBus = 258,
    brewblox_BlockType_BoardPins = 259,
    brewblox_BlockType_TempSensorMock = 301,
    brewblox_BlockType_TempSensorOneWire = 302,
    brewblox_BlockType_SetpointSensorPair = 303,
    brewblox_BlockType_Pid = 304,
    brewblox_BlockType_ActuatorAnalogMock = 305,
    brewblox_BlockType_ActuatorPin = 306,
    brewblox_BlockType_ActuatorPwm = 307,
    brewblox_BlockType_ActuatorOffset = 308,
    brewblox_BlockType_Balancer = 309,
    brewblox_BlockType_Mutex = 310,
    brewblox_BlockType_SetpointProfile = 311,
    brewblox_BlockType_WiFiSettings = 312,
    brewblox_BlockType_TouchSettings = 313,
    brewblox_BlockType_DisplaySettings = 314,
    brewblox_BlockType_DS2413 = 315,
    brewblox_BlockType_ActuatorOneWire = 316,
    brewblox_BlockType_DS2408 = 317,
    brewblox_BlockType_DigitalActuator = 318,
    brewblox_BlockType_Spark3Pins = 319,
    brewblox_BlockType_Spark2Pins = 320,
    brewblox_BlockType_MotorValve = 321,
    brewblox_BlockType_ActuatorLogic = 322,
    brewblox_BlockType_MockPins = 323,
    brewblox_BlockType_TempSensorCombi = 324,
    brewblox_BlockType_OneWireGpioModule = 325,
    brewblox_BlockType_Sequence = 326,
    brewblox_BlockType_TempSensorExternal = 328
} brewblox_BlockType;
#define _brewblox_BlockType_MIN brewblox_BlockType_Invalid
#define _brewblox_BlockType_MAX brewblox_BlockType_TempSensorExternal
#define _brewblox_BlockType_ARRAYSIZE ((brewblox_BlockType)(brewblox_BlockType_TempSensorExternal+1))

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
