idf_component_register(
  SRCS
   graphics.cpp
   layout.cpp
   styles.cpp
   widgets/BaseWidget.cpp
  INCLUDE_DIRS
    ../
  REQUIRES
    main
    esp
    external_libs
)

# Generate fonts
add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/fonts/font_main_small.c ${CMAKE_CURRENT_LIST_DIR}/fonts/font_main.c ${CMAKE_CURRENT_LIST_DIR}/fonts/font_numbers_large.c ${CMAKE_CURRENT_LIST_DIR}/fonts/font_numbers_medium.c
                    COMMAND python3 generate_fonts.py
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/fonts
                    VERBATIM)

add_custom_target(fonts DEPENDS ${CMAKE_CURRENT_LIST_DIR}/fonts/font_main_small.c ${CMAKE_CURRENT_LIST_DIR}/fonts/font_main.c ${CMAKE_CURRENT_LIST_DIR}/fonts/font_numbers_large.c ${CMAKE_CURRENT_LIST_DIR}/fonts/font_numbers_medium.c)
add_dependencies(${COMPONENT_LIB} fonts)
target_sources(${COMPONENT_LIB} PRIVATE
   ${CMAKE_CURRENT_LIST_DIR}/fonts/font_main.c
   ${CMAKE_CURRENT_LIST_DIR}/fonts/font_main_small.c
   ${CMAKE_CURRENT_LIST_DIR}/fonts/font_numbers_large.c
   ${CMAKE_CURRENT_LIST_DIR}/fonts/font_numbers_medium.c)
