if(ESP_PLATFORM)
  idf_component_register(
    INCLUDE_DIRS
      expected/include
    REQUIRES
      main
  )

else()
  target_include_directories(brewblox PRIVATE
    expected/include
  )

endif()
