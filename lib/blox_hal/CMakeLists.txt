set(blox_hal_srcs
  src/hal_spi.cpp
)

if(ESP_PLATFORM)
  idf_component_register(
    SRCS
      ${blox_hal_srcs}
    INCLUDE_DIRS
      inc
    REQUIRES
      main
  )

else()
  target_sources(brewblox PRIVATE
    ${blox_hal_srcs}
  )

  target_include_directories(brewblox PRIVATE
    inc
  )

endif()
