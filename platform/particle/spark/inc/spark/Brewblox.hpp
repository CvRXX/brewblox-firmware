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

void setupSystemBlocks();

const std::string& deviceIdString();

// write device id as raw bytes to destination buffer
// returns actual bytes written
unsigned get_device_id(uint8_t* dest, unsigned max_len);

const std::string& versionCsv();

int resetReason();

int resetReasonData();

} // end namespace platform::particle
