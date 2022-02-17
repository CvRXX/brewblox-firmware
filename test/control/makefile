## -*- Makefile -*-

CFLAGS = -Og -Wfatal-errors
CCFLAGS = $(CFLAGS)
CXXFLAGS = $(CFLAGS)

ROOT_DIR = $(shell git rev-parse --show-toplevel)

# lib/control
INCLUDE_DIRS += $(ROOT_DIR)/lib/control/inc
CPPSRC += $(wildcard $(ROOT_DIR)/lib/control/src/*.cpp)

# lib/blox_hal
# only build the stubs
INCLUDE_DIRS += $(ROOT_DIR)/lib/blox_hal/inc
CPPSRC += $(wildcard $(ROOT_DIR)/platform/stub/*.cpp)

# set cnl as system includes to suppress warnings
CPPFLAGS += -isystem $(ROOT_DIR)/external_libs/cnl/include

# catch2
INCLUDE_DIRS += $(ROOT_DIR)/external_libs/device-os/third_party/catch2/catch2/single_include/catch2

# add all tests
CPPSRC += $(wildcard $(ROOT_DIR)/test/control/*.cpp)

# include boost
CPPFLAGS += -isystem $(BOOST_ROOT)

CFLAGS += $(patsubst %,-I%,$(INCLUDE_DIRS)) -I.
CFLAGS += -ffunction-sections -Wall
CFLAGS += -Wno-deprecated
CFLAGS += -Wnull-dereference
CPPFLAGS += -fdiagnostics-show-template-tree -fno-elide-type # GCC8 required
CFLAGS += -Wextra
CPPFLAGS += -Wextra-semi
CFLAGS += -Wpedantic -Wvla -Wswitch-enum -fvar-tracking-assignments
CFLAGS += -Wduplicated-cond -Wduplicated-branches -rdynamic

# Flag compiler error for [-Wdeprecated-declarations]
CFLAGS += -Werror=deprecated-declarations

# the following warnings can help find opportunities for impromevent in virtual functions
# Warn when virtual functions are overriden without override/override final specifier (requires gcc 5.1)
CPPFLAGS += -Wsuggest-override
# Warn when functions and classes can be marked final
CPPFLAGS += -Wsuggest-final-types
CPPFLAGS += -Wsuggest-final-methods

# Generate dependency files automatically.
CFLAGS += -MD -MP -MF $@.d
CFLAGS += -DDEBUG_BUILD
# OSX includes sys/wait.h which defines "wait"
CFLAGS += -D_SYS_WAIT_H_ -D_SYS_WAIT_H

CPPFLAGS += -std=gnu++17
CFLAGS += -pthread

# compile with coverage
CFLAGS += -g -fprofile-arcs -ftest-coverage
LDFLAGS += -lgcov

# compile with coverage and sanitizer (uncommented because cnl doesn't work well with it)
# include $(ROOT_DIR)/test/checkers.mk # sanitizer and gcov

# generate map file
LDFLAGS += -Xlinker -Map=build/libtest.map

# don't generate warnings for system headers
CFLAGS += -Wno-system-headers

# set platform flag
CFLAGS += -DPLATFORM_ID=3

# handles building the target from declared sources
include ../targets.mk
