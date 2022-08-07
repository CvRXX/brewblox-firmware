## -*- Makefile -*-
ROOT_DIR = $(shell git rev-parse --show-toplevel)

include ../coverage.mk
include ../sanitize.mk

# expected
INCLUDE_DIRS += $(ROOT_DIR)/external_libs/expected/expected/include

# catch test
INCLUDE_DIRS += $(ROOT_DIR)/external_libs/device-os/third_party/catch2/catch2/single_include/catch2

# lib/control (headers only)
INCLUDE_DIRS += $(ROOT_DIR)/lib/control/inc

# lib/cbox
INCLUDE_DIRS += $(ROOT_DIR)/lib/cbox/inc
CPPSRC += $(wildcard $(ROOT_DIR)/lib/cbox/src/*.cpp)

# lib/proto
INCLUDE_DIRS += $(ROOT_DIR)/lib/proto/inc
CSRC += $(wildcard $(ROOT_DIR)/lib/proto/inc/proto/*.pb.c)

# device-os nanopb
INCLUDE_DIRS += $(ROOT_DIR)/external_libs/device-os/third_party/nanopb/nanopb
CSRC += $(wildcard $(ROOT_DIR)/external_libs/device-os/third_party/nanopb/nanopb/*.c)

# platform/particle/spark (add as needed)
INCLUDE_DIRS += $(ROOT_DIR)/platform/particle/spark/inc
CPPSRC += platform/particle/spark/src/ConnectionPool.cpp

# test/shared
# only add the files we need
INCLUDE_DIRS += $(ROOT_DIR)/test/shared
CPPSRC += test/shared/TestHelpers.cpp
CPPSRC += test/shared/AppLogger.cpp

# test/cbox
# listed individually to help with refactoring
CPPSRC += $(ROOT_DIR)/test/cbox/runner.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/TestApplication.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/Base64_test.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/Box_test.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/CboxPtr_test.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/CboxClaimingPtr_test.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/Connection_test.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/EepromObjectStorage_test.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/FileObjectStorage_test.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/ObjectContainer_test.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/ObjectFactory_test.cpp
CPPSRC += $(ROOT_DIR)/test/cbox/TestObjectInterfaceIds.cpp

# include google protobuf dependencies
CPPFLAGS += $(shell pkg-config --cflags protobuf)
LDFLAGS += $(shell pkg-config --libs protobuf)
CFLAGS += -DPB_MSGID=1

CFLAGS += -ffunction-sections -Wall

# Flag compiler error for [-Wdeprecated-declarations]
CFLAGS += -Werror=deprecated-declarations

# stop on first error
# CFLAGS += -Wfatal-errors

# Generate dependency files automatically.
CFLAGS += -g -Og
CFLAGS += -MD -MP -MF $@.d
CFLAGS += -DDEBUG_BUILD

CPPFLAGS += -std=gnu++17
CFLAGS += -pthread

# the following warnings can help find opportunities for improvement in virtual functions
# Warn when virtual functions are overriden without override/final specifier (requires gcc 5.1)
CPPFLAGS += -Wsuggest-override
# Warn when functions and classes can be marked final
CPPFLAGS += -Wsuggest-final-types
CPPFLAGS += -Wsuggest-final-methods

# handles building the target from declared sources
include ../targets.mk
