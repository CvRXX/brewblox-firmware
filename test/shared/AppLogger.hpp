#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace logger {

void clear();

bool contains(const std::string& s);

uint32_t count(const std::string& s);

void info(const std::string& message);

void warn(const std::string& message);

void error(const std::string& message);

} // end namespace logger
