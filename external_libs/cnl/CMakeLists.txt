if(ESP_PLATFORM)
  idf_component_register(
    INCLUDE_DIRS
      cnl/include
    REQUIRES
      main
  )

else()
  target_include_directories(brewblox PRIVATE
    cnl/include
  )

endif()
