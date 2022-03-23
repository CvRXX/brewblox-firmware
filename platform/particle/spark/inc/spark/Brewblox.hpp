#pragma once

#include "cbox/ConnectionPool.hpp"
#include "cbox/DataStream.hpp"

class OneWire;

// Create and return a static ConnectionPool
cbox::ConnectionPool& getConnectionPool();

// Create and return a static OneWire
OneWire& getOneWire();

void setupSystemBlocks();

const std::string& deviceIdString();

// write device id as raw bytes to destination buffer
// returns actual bytes written
unsigned get_device_id(uint8_t* dest, unsigned max_len);

const std::string& versionCsv();

int resetReason();

int resetReasonData();
