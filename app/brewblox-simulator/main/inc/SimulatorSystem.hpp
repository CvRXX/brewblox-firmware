#pragma once
#include "intellisense.hpp"

#include <string>
#include <vector>

const std::string& getDeviceId();

void setDeviceId(const std::string& id);

const std::string& versionCsv();

int resetReason();

int resetReasonData();

void setupSystemBlocks();
