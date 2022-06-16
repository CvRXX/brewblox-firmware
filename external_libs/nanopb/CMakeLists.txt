file(GLOB nanopb_srcs nanopb/*.c)

if(ESP_PLATFORM)
  idf_component_register(
    SRCS
      ${nanopb_srcs}
    INCLUDE_DIRS
      nanopb
    REQUIRES
      main
  )

else()
  target_sources(brewblox PRIVATE
    ${nanopb_srcs}
  )

  target_include_directories(brewblox PRIVATE
    nanopb
  )

endif()
