## -*- Makefile -*-
# This file should be included after setting desired C/CC/CXX/LD flags,
# include dirs, and sources.
# It will build all sources, and generate a runner
#
# IMPORTANT: CSRC/CPPSRC is expected to include paths that are either absolute,
# IMPORTANT: or relative to the root.

CCC = gcc
CXX = g++
LD = g++
RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p

ROOT_DIR = $(shell git rev-parse --show-toplevel)
BUILD_DIR = $(shell pwd)/build
TARGET = runner

GIT_VERSION = $(shell cd $(ROOT_DIR); git rev-parse --short=8 HEAD)
$(info using $(GIT_VERSION) as version)
CFLAGS += -DGIT_VERSION="\"$(GIT_VERSION)\""

GIT_DATE = $(shell cd $(ROOT_DIR); git log -1 --format=%cd --date=short)
$(info using $(GIT_DATE) as release date)
CFLAGS += -DGIT_DATE="\"$(GIT_DATE)\""

PROTO_VERSION = $(shell cd $(ROOT_DIR)/external_libs/brewblox-proto; git rev-parse --short=8 HEAD)
$(info using $(PROTO_VERSION) as protocol version)
CFLAGS += -DPROTO_VERSION="\"$(PROTO_VERSION)\""

PROTO_DATE = $(shell cd $(ROOT_DIR)/external_libs/brewblox-proto; git log -1 --format=%cd --date=short)
$(info using $(GIT_DATE) as protocol date)
CFLAGS += -DPROTO_DATE="\"$(PROTO_DATE)\""

# Check boost availability
# This does not add it to the include path.
# To do that, use `CPPFLAGS += -isystem $(BOOST_ROOT)`
ifeq ($(BOOST_ROOT),)
$(error BOOST_ROOT not set. Download boost and add BOOST_ROOT to your environment variables.)
endif

CFLAGS += $(patsubst %,-I%,$(INCLUDE_DIRS)) -I.

# Filter unwanted files
CSRC := $(filter-out $(CEXCLUDES),$(CSRC))
CPPSRC := $(filter-out $(CPPEXCLUDES),$(CPPSRC))
CCSRC := $(filter-out $(CCEXCLUDES),$(CCSRC))

# Make paths relative to the root dir
CSRC := $(patsubst $(ROOT_DIR)/%,%,$(CSRC))
CPPSRC := $(patsubst $(ROOT_DIR)/%,%,$(CPPSRC))
CCSRC := $(patsubst $(ROOT_DIR)/%,%,$(CCSRC))

# Collect all object and dep files
ALLOBJ += $(addprefix $(BUILD_DIR)/, $(CSRC:.c=.o))
ALLOBJ += $(addprefix $(BUILD_DIR)/, $(CPPSRC:.cpp=.o))
ALLOBJ += $(addprefix $(BUILD_DIR)/, $(CCSRC:.pb.cc=.pb.o))

ALLDEPS += $(addprefix $(BUILD_DIR)/, $(CSRC:.c=.o.d))
ALLDEPS += $(addprefix $(BUILD_DIR)/, $(CPPSRC:.cpp=.o.d))
ALLDEPS += $(addprefix $(BUILD_DIR)/, $(CCSRC:.pb.cc=.pb.o.d))

all: runner

runner: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET) : $(BUILD_DIR) $(ALLOBJ)
	@echo Building target: $@
	@$(MKDIR) $(dir $@)
	@$(LD) $(CFLAGS) $(ALLOBJ) --output $@ $(LDFLAGS)
	@echo

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

# Tool invocations

# C compiler to build .o from .c in $(BUILD_DIR)
$(BUILD_DIR)/%.o : $(ROOT_DIR)/%.c
	@echo Building file: $<
	@$(MKDIR) $(dir $@)
	@$(CCC) $(CFLAGS) -c -o $@ $<

# CPP compiler to build .o from .cpp in $(BUILD_DIR)
# Note: Calls standard $(CC) - gcc will invoke g++ as appropriate
$(BUILD_DIR)/%.o : $(ROOT_DIR)/%.cpp
	@echo Building file: $<
	@$(MKDIR) $(dir $@)
	@$(CXX) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

# CPP compiler to build .pb.o from .pb.cc in $(BUILD_DIR)
# Note: Calls standard $(CC) - gcc will invoke g++ as appropriate
$(BUILD_DIR)/%.pb.o : $(ROOT_DIR)/%.pb.cc
	@echo Building file: $<
	@$(MKDIR) $(dir $@)
	@$(CCC) $(CFLAGS) -s -c -o $@ $<

# Other Targets
clean:
	$(RMDIR) $(BUILD_DIR)
	@echo

# print variable by invoking make print-VARIABLE as VARIABLE = the_value_of_the_variable
print-%  : ; @echo $* = $($*)

.PHONY: all clean runner
.SECONDARY:

# Include auto generated dependency files
-include $(ALLDEPS)
