#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace logger {

extern std::vector<std::string> logs;

inline void clear()
{
    logs.clear();
}

inline bool contains(const std::string& s)
{
    return std::any_of(std::begin(logs), std::end(logs), s);
}

inline uint32_t count(const std::string& s)
{
    uint32_t count = 0;
    for (const auto& log : logs) {
        if (s == log) {
            count++;
        }
    }
    return count;
}

inline void info(const std::string& message)
{
    logs.push_back("LOG(I): " + message);
}

inline void warn(const std::string& message)
{
    logs.push_back("LOG(W): " + message);
}

inline void error(const std::string& message)
{
    logs.push_back("LOG(E): " + message);
}

} // end namespace logger
