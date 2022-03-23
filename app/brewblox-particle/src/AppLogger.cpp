#include "AppLogger.hpp"
#include "spark/Brewblox.hpp"

namespace logger {

void _write(char category, const std::string& message)
{
    std::string combined;
    combined.reserve(message.size() + 3);
    combined.insert(0, 1, category);
    combined.insert(1, ": ");
    combined.insert(3, message);
    getConnectionPool().writeLog(combined);
}

void info(const std::string& message)
{
    _write('I', message);
}

void warn(const std::string& message)
{
    _write('W', message);
}

void error(const std::string& message)
{
    _write('E', message);
}

} // end namespace logger
