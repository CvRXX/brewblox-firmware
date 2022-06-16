#pragma once

#include "network/cbox_connection.hpp"
#include <set>

/// Manages open connections so that they may be cleanly stopped when the server
/// needs to shut down.
class CboxConnectionManager final {
public:
    CboxConnectionManager() = default;
    CboxConnectionManager(const CboxConnectionManager&) = delete;
    CboxConnectionManager& operator=(const CboxConnectionManager&) = delete;
    CboxConnectionManager(CboxConnectionManager&&) = default;
    CboxConnectionManager& operator=(CboxConnectionManager&&) = default;
    ~CboxConnectionManager() = default;

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
