file(GLOB_RECURSE lvgl_srcs lvgl/src/*.c) 
file(GLOB nanopb_srcs nanopb/*.c) 


idf_component_register(
  SRCS
    ${lvgl_srcs}
    ${nanopb_srcs}
  INCLUDE_DIRS 
    nanopb
    cnl/include
    lvgl/src
  REQUIRES
    main
)