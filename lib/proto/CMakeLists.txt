set(proto_srcs
  inc/proto/Screen.pb.c
  inc/proto/MockPins.pb.c
  inc/proto/Balancer.pb.c
  inc/proto/Constraints.pb.c
  inc/proto/WiFiSettings.pb.c
  inc/proto/Pid.pb.c
  inc/proto/Mutex.pb.c
  inc/proto/DisplaySettings.pb.c
  inc/proto/SetpointProfile.pb.c
  inc/proto/DS2413.pb.c
  inc/proto/TempSensorCombi.pb.c
  inc/proto/Ticks.pb.c
  inc/proto/ActuatorAnalogMock.pb.c
  inc/proto/brewblox.pb.c
  inc/proto/DS2408.pb.c
  inc/proto/ActuatorPwm.pb.c
  inc/proto/TempSensorOneWire.pb.c
  inc/proto/DigitalActuator.pb.c
  inc/proto/TouchSettings.pb.c
  inc/proto/OneWireBus.pb.c
  inc/proto/ActuatorOffset.pb.c
  inc/proto/TempSensorMock.pb.c
  inc/proto/command.pb.c
  inc/proto/SysInfo.pb.c
  inc/proto/ActuatorLogic.pb.c
  inc/proto/SetpointSensorPair.pb.c
  inc/proto/Spark2Pins.pb.c
  inc/proto/EdgeCase.pb.c
  inc/proto/OneWireGpioModule.pb.c
  inc/proto/MotorValve.pb.c
  inc/proto/IoArray.pb.c
  inc/proto/Sequence.pb.c
  inc/proto/Spark3Pins.pb.c
  inc/proto/TempSensorExternal.pb.c
)

if(ESP_PLATFORM)
  idf_component_register(
    SRCS
      ${proto_srcs}
    INCLUDE_DIRS
      inc
    REQUIRES
      main
  )

else()
  target_sources(brewblox PRIVATE
    ${proto_srcs}
  )

  target_include_directories(brewblox PRIVATE
    inc
  )

endif()
