set(cbox_srcs
  src/Base64.cpp
  src/Box.cpp
  src/Crc.cpp
  src/EepromObjectStorage.cpp
  src/FileObjectStorage.cpp
  src/ObjectBase.cpp
  src/ObjectContainer.cpp
  src/ObjectFactory.cpp
  src/Serialization.cpp
)

if(ESP_PLATFORM)
  idf_component_register(
    SRCS
      ${cbox_srcs}
    INCLUDE_DIRS
      inc
    REQUIRES
      main
  )

else()
  target_sources(brewblox PRIVATE
    ${cbox_srcs}
  )

  target_include_directories(brewblox PRIVATE
    inc
  )

endif()
