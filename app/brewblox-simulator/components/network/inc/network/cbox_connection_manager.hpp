#pragma once

#include "network/cbox_connection.hpp"
#include <set>

/// Manages open connections so that they may be cleanly stopped when the server
/// needs to shut down.
class CboxConnectionManager {
public:
    CboxConnectionManager(const CboxConnectionManager&) = delete;
    CboxConnectionManager& operator=(const CboxConnectionManager&) = delete;

    /// Construct a connection manager.
    CboxConnectionManager();

    /// Add the specified connection to the manager and start it.
    void start(CboxConnectionPtr c);

    /// Stop the specified connection.
    void stop(CboxConnectionPtr c);

    /// Stop all connections.
    void stop_all();

private:
    /// The managed connections.
    std::set<CboxConnectionPtr> connections;
};
