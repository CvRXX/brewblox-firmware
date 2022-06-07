set(dynamic_gui_srcs
  styles/styles.cpp
  fonts/font_main.c
  fonts/font_main_small.c
  fonts/font_numbers_large.c
  fonts/font_numbers_medium.c
  fonts/font_numbers_huge.c
  fonts/font_numbers_small.c
)

if(ESP_PLATFORM)
  idf_component_register(
    SRCS
      ${dynamic_gui_srcs}

    INCLUDE_DIRS
      ../
    REQUIRES
      main
  )

else()
  target_sources(brewblox PRIVATE
    ${dynamic_gui_srcs}
  )

  target_include_directories(brewblox PRIVATE
    ../
  )

endif()
