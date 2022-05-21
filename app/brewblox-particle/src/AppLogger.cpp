#include "AppLogger.hpp"
#include "spark/Brewblox.hpp"
#include "spark/ConnectionPool.hpp"

namespace logger {

void _write(char category, const std::string& message)
{
    auto combined = std::string("LOG(I): ");
    combined[4] = category;
    combined.append(message);

    platform::particle::getConnectionPool().writeLog(combined);
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
