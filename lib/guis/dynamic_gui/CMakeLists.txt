set(dynamic_gui_srcs
  src/styles/styles.cpp
  src/styles/sizing.cpp

  src/decode.cpp
  src/encode.cpp

  src/fonts/font_main.c
  src/fonts/font_main_small.c
  src/fonts/font_numbers_large.c
  src/fonts/font_numbers_medium.c
  src/fonts/font_numbers_huge.c
  src/fonts/font_numbers_small.c

  src/elements/layout/content.cpp
  src/elements/layout/horizontal_split.cpp


)

if(ESP_PLATFORM)
  idf_component_register(
    SRCS
      ${dynamic_gui_srcs}

    INCLUDE_DIRS
      inc
      ../
    REQUIRES
      main
  )

else()
  target_sources(brewblox PRIVATE
    ${dynamic_gui_srcs}
  )

  target_include_directories(brewblox PRIVATE
    inc
    ../
  )

endif()
