#pragma once

#include "cbox/ConnectionPool.h"
#include "cbox/DataStream.h"
#include "control/Logger.h"

class OneWire;

// Create and return a static ConnectionPool
cbox::ConnectionPool& getConnectionPool();

// Create and return a static OneWire
OneWire& getOneWire();

// Create and return a static Logger
// Implements extern function in lib/control/Logger.h
Logger& getLogger();

void setupSystemBlocks();

void logEvent(const std::string& event);

const std::string& deviceIdString();

// write device id as raw bytes to destination buffer
// returns actual bytes written
unsigned get_device_id(uint8_t* dest, unsigned max_len);

const std::string& versionCsv();

int resetReason();

int resetReasonData();
