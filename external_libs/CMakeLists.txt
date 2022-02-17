file(GLOB nanopb_srcs nanopb/*.c)

idf_component_register(
  SRCS
    ${nanopb_srcs}
  INCLUDE_DIRS
    nanopb
    cnl/include
)
