#include "AppLogger.hpp"
#include "spark/Brewblox.hpp"
#include "spark/ConnectionPool.hpp"

namespace logger {

void _write(char category, const std::string& message)
{
    std::string combined;
    combined.reserve(message.size() + 3);
    combined.push_back(category);
    combined.push_back(':');
    combined.push_back(' ');
    combined.append(message);
    platform::particle::getConnectionPool().writeLog(combined);
}

} // end namespace logger
