file(GLOB_RECURSE lvgl_srcs lvgl/src/*.c)

if(ESP_PLATFORM)
  idf_component_register(
    SRCS
      ${lvgl_srcs}
    INCLUDE_DIRS
      .
      lvgl/src
    REQUIRES
      main
  )

else()
  target_sources(brewblox PRIVATE
    ${lvgl_srcs}
  )

  target_include_directories(brewblox PRIVATE
    .
    lvgl/src
  )


endif()

add_compile_definitions(LV_LVGL_H_INCLUDE_SIMPLE)
