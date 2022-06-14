#pragma once

#include <cstdint>
#include <string>

class OneWire;

namespace platform::particle {
class BuzzerClass;
class ConnectionPool;

// Create and return a static ConnectionPool
ConnectionPool& getConnectionPool();

// Create and return a static OneWire
OneWire& getOneWire();

// Create and return a static Buzzer
BuzzerClass& getBuzzer();

const std::string& deviceIdString();

const std::string& versionCsv();

int resetReason();

int resetReasonData();

void setupSystemBlocks();

} // end namespace platform::particle
