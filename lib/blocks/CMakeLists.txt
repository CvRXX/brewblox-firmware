
set(blocks_srcs
  src/ConstraintsProto.cpp
  src/ActuatorAnalogMockBlock.cpp
  src/ActuatorLogicBlock.cpp
  src/ActuatorOffsetBlock.cpp
  src/ActuatorPwmBlock.cpp
  src/BalancerBlock.cpp
  src/BlockFactory.cpp
  src/BlockInterfaces.cpp
  src/DigitalActuatorBlock.cpp
  src/DisplaySettingsBlock.cpp
  src/DS2408Block.cpp
  src/DS2413Block.cpp
  src/FastPwmBlock.cpp
  src/MockPinsBlock.cpp
  src/MotorValveBlock.cpp
  src/MutexBlock.cpp
  src/OneWireBusBlock.cpp
  src/OneWireScanningFactory.cpp
  src/PidBlock.cpp
  src/SequenceBlock.cpp
  src/SetpointProfileBlock.cpp
  src/SetpointSensorPairBlock.cpp
  src/SysInfoBlock.cpp
  src/TempSensorCombiBlock.cpp
  src/TempSensorExternalBlock.cpp
  src/TempSensorMockBlock.cpp
  src/TempSensorOneWireBlock.cpp
)

if(ESP_PLATFORM)
  idf_component_register(
    SRCS
      ${blocks_srcs}
    INCLUDE_DIRS
      inc
    REQUIRES
      main
  )

else()
  target_sources(brewblox PRIVATE
    ${blocks_srcs}
  )

  target_include_directories(brewblox PRIVATE
    inc
  )

endif()
