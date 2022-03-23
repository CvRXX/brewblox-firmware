## -*- Makefile -*-

CCFLAGS = $(CFLAGS)
CXXFLAGS = $(CFLAGS)

ROOT_DIR = $(shell git rev-parse --show-toplevel)

# include ../checkers.mk # sanitizer and gcov

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

# test/shared (only include what is needed)
INCLUDE_DIRS += $(ROOT_DIR)/test/shared
CPPSRC += test/shared/AppLogger.cpp

# test/control
CPPSRC += $(wildcard $(ROOT_DIR)/test/control/*.cpp)

CFLAGS += -DPLATFORM_ID=3

# include boost
CPPFLAGS += -isystem $(BOOST_ROOT)

# Generate dependency files automatically.
CFLAGS += -MD -MP -MF $@.d
CFLAGS += -DDEBUG_BUILD

CFLAGS += -ffunction-sections -Wall
CFLAGS += -Werror=deprecated-declarations

CPPFLAGS += -std=gnu++17
CFLAGS += -pthread

CPPFLAGS += -Wsuggest-override
CPPFLAGS += -Wsuggest-final-types
CPPFLAGS += -Wsuggest-final-methods

# don't generate warnings for system headers
CFLAGS += -Wno-system-headers

# handles building the target from declared sources
include ../targets.mk
