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
typedef enum _UnitType {
    UnitType_NotSet = 0,
    UnitType_Celsius = 1,
    UnitType_InverseCelsius = 2,
    UnitType_Second = 3,
    UnitType_Minute = 4,
    UnitType_Hour = 5,
    UnitType_DeltaCelsius = 6,
    UnitType_DeltaCelsiusPerSecond = 7,
    UnitType_DeltaCelsiusPerMinute = 8,
    UnitType_DeltaCelsiusPerHour = 9,
    UnitType_DeltaCelsiusMultSecond = 10,
    UnitType_DeltaCelsiusMultMinute = 11,
    UnitType_DeltaCelsiusMultHour = 12
} UnitType;
#define _UnitType_MIN UnitType_NotSet
#define _UnitType_MAX UnitType_DeltaCelsiusMultHour
#define _UnitType_ARRAYSIZE ((UnitType)(UnitType_DeltaCelsiusMultHour+1))

typedef enum _BlockType {
    BlockType_Invalid = 0,
    BlockType_ProcessValueInterface = 1,
    BlockType_TempSensorInterface = 2,
    BlockType_SetpointSensorPairInterface = 4,
    BlockType_ActuatorAnalogInterface = 5,
    BlockType_ActuatorDigitalInterface = 6,
    BlockType_BalancerInterface = 7,
    BlockType_MutexInterface = 8,
    BlockType_OneWireDeviceInterface = 9,
    BlockType_IoArrayInterface = 10,
    BlockType_DS2408Interface = 11,
    BlockType_OneWireBusInterface = 12,
    BlockType_IoModuleInterface = 13,
    BlockType_OneWireDeviceBlockInterface = 14,
    BlockType_Any = 255,
    BlockType_SysInfo = 256,
    BlockType_Ticks = 257,
    BlockType_OneWireBus = 258,
    BlockType_BoardPins = 259,
    BlockType_TempSensorMock = 301,
    BlockType_TempSensorOneWire = 302,
    BlockType_SetpointSensorPair = 303,
    BlockType_Pid = 304,
    BlockType_ActuatorAnalogMock = 305,
    BlockType_ActuatorPin = 306,
    BlockType_ActuatorPwm = 307,
    BlockType_ActuatorOffset = 308,
    BlockType_Balancer = 309,
    BlockType_Mutex = 310,
    BlockType_SetpointProfile = 311,
    BlockType_WiFiSettings = 312,
    BlockType_TouchSettings = 313,
    BlockType_DisplaySettings = 314,
    BlockType_DS2413 = 315,
    BlockType_ActuatorOneWire = 316,
    BlockType_DS2408 = 317,
    BlockType_DigitalActuator = 318,
    BlockType_Spark3Pins = 319,
    BlockType_Spark2Pins = 320,
    BlockType_MotorValve = 321,
    BlockType_ActuatorLogic = 322,
    BlockType_MockPins = 323,
    BlockType_TempSensorCombi = 324,
    BlockType_OneWireGpioModule = 325
} BlockType;
#define _BlockType_MIN BlockType_Invalid
#define _BlockType_MAX BlockType_OneWireGpioModule
#define _BlockType_ARRAYSIZE ((BlockType)(BlockType_OneWireGpioModule+1))

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
