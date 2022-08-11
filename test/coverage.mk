CFLAGS += -fprofile-arcs -ftest-coverage
# to use with particle makefiles, temporarily add flags below to module.mk
# to break on asan errors, run this in the gdb console: -exec break *__asan_on_error
LDFLAGS += --coverage
