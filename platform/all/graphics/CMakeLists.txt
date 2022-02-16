if(NOT CMAKE_BUILD_EARLY_EXPANSION)
  add_custom_command(OUTPUT font_main_small.c font_main.c font_numbers_large.c font_numbers_medium.c
      COMMAND python3 generate_fonts.py
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/fonts
      VERBATIM)

  add_custom_target(fonts DEPENDS font_main_small.c font_main.c font_numbers_large.c font_numbers_medium.c)
endif()
add_dependencies(${COMPONENT_LIB} fonts)



idf_component_register(
  SRCS
   graphics.cpp
   layout.cpp
   styles.cpp
   widgets/BaseWidget.cpp
   fonts/font_main.c
   fonts/font_main_small.c
   fonts/font_numbers_large.c
   fonts/font_numbers_medium.c
  INCLUDE_DIRS
    ../
  REQUIRES
    main
    esp
    external_libs
)
