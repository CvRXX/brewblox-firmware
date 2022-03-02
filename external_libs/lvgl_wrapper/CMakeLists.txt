# lvgl sources are included as glob to avoid LVGL component settings to be added to menuconfig
# settings are defined in lv_conf.h instead

file(GLOB_RECURSE lvgl_srcs lvgl/src/*.c)

idf_component_register(
  SRCS
    ${lvgl_srcs}
  INCLUDE_DIRS
    lvgl/src
  REQUIRES
    main
)

add_compile_definitions(LV_LVGL_H_INCLUDE_SIMPLE)
