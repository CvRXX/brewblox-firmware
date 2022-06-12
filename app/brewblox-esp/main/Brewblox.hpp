#pragma once
#include "intellisense.hpp"

#include <string>

void setupSystemBlocks();

const std::string& deviceIdString();

size_t get_device_id(uint8_t* dest, size_t max_len);

const std::string& versionCsv();

int resetReason();

int resetReasonData();
