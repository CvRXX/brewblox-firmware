#pragma once

#include "control/Logger.h"
#include <string>

// Create and return a static Logger
// Implements extern function in lib/control/Logger.h
Logger& getLogger();

void setupSystemBlocks();

const std::string& deviceIdString();

// write device id as raw bytes to destination buffer
// returns actual bytes written
unsigned get_device_id(uint8_t* dest, unsigned max_len);

const std::string& versionCsv();

int resetReason();

int resetReasonData();
