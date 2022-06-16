#pragma once
#include "intellisense.hpp"

#include <string>
#include <vector>

std::string_view getDeviceId();

void setDeviceId(const std::string& id);

std::string_view versionCsv();

int resetReason();

int resetReasonData();

void setupSystemBlocks();
