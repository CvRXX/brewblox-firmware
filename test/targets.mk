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
	@$(CCC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

# CPP compiler to build .o from .cpp in $(BUILD_DIR)
# Note: Calls standard $(CC) - gcc will invoke g++ as appropriate
$(BUILD_DIR)/%.o : $(ROOT_DIR)/%.cpp
	@echo Building file: $<
	@$(MKDIR) $(dir $@)
	@$(CXX) $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

# CPP compiler to build .pb.o from .pb.cc in $(BUILD_DIR)
# Note: Calls standard $(CC) - gcc will invoke g++ as appropriate
$(BUILD_DIR)/%.pb.o : $(ROOT_DIR)/%.pb.cc
	@echo Building file: $<
	@$(MKDIR) $(dir $@)
	@$(CXX) $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -s -c -o $@ $<

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
