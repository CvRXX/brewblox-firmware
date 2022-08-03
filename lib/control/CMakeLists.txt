set(control_srcs
  src/ActuatorAnalogConstrained.cpp
  src/ActuatorDigitalChangeLogged.cpp
  src/ActuatorDigitalConstrained.cpp
  src/ActuatorDigital.cpp
  src/ActuatorPwm.cpp
  src/Balancer.cpp
  src/DS18B20.cpp
  src/DS2408.cpp
  src/DS2413.cpp
  src/DS248x.cpp
  src/FastPwm.cpp
  src/FilterChain.cpp
  src/FixedPoint.cpp
  src/IirFilter.cpp
  src/MotorValve.cpp
  src/OneWireAddress.cpp
  src/OneWire.cpp
  src/OneWireCrc.cpp
  src/OneWireDevice.cpp
  src/OneWireMockDevice.cpp
  src/OneWireMockDriver.cpp
  src/Pid.cpp
  src/SetpointProfile.cpp
  src/SX1508.cpp
  src/Temperature.cpp
  src/TempSensorCombi.cpp
  src/TempSensorMock.cpp
)

if(ESP_PLATFORM)
  idf_component_register(
    SRCS
      ${control_srcs}
      src/esp/ChemSense.cpp
    INCLUDE_DIRS
      inc
    REQUIRES
      main
  )

else()
  target_sources(brewblox PRIVATE
    ${control_srcs}
  )

  target_include_directories(brewblox PRIVATE
    inc
  )

endif()
