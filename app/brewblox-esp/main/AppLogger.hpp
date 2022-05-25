#pragma once
#include <string>

namespace logger {

void info(const std::string& message);
void warn(const std::string& message);
void error(const std::string& message);

} // end namespace logger
