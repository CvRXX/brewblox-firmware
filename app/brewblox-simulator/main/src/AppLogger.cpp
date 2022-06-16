#include "AppLogger.hpp"
#include <iostream>
#include <string>

namespace logger {

void info(const std::string& message)
{
    std::cout << "I: " << message << std::endl;
}

void warn(const std::string& message)
{
    std::cout << "W: " << message << std::endl;
}

void error(const std::string& message)
{
    std::cout << "E: " << message << std::endl;
}

} // end namespace logger
