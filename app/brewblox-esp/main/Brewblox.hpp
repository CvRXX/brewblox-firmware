#pragma once
#include "intellisense.hpp"

#include <string>

const std::string& deviceIdString();

const std::string& versionCsv();

int resetReason();

int resetReasonData();

void setupSystemBlocks();
