#include "AppLogger.hpp"

namespace logger {

std::vector<std::string> logs;

void clear()
{
    logs.clear();
}

bool contains(const std::string& s)
{
    return std::any_of(std::begin(logs), std::end(logs), [&s](const std::string& entry) {
        return entry == s;
    });
}

uint32_t count(const std::string& s)
{
    uint32_t count = 0;
    for (const auto& log : logs) {
        if (s == log) {
            count++;
        }
    }
    return count;
}

void info(const std::string& message)
{
    logs.push_back("LOG(I): " + message);
}

void warn(const std::string& message)
{
    logs.push_back("LOG(W): " + message);
}

void error(const std::string& message)
{
    logs.push_back("LOG(E): " + message);
}

} // end namespace logger
