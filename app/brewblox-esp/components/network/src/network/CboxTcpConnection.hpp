#pragma once
#include "intellisense.hpp"

#include "CboxConnection.hpp"
#include <asio.hpp>

class CboxTcpConnection final : public CboxConnection {
public:
    explicit CboxTcpConnection(asio::ip::tcp::socket socket_,
                               CboxConnectionManager& connection_manager_);

    void stop() override;

    void async_read_impl(asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self) override;
    void async_write_impl(asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self) override;

private:
    asio::ip::tcp::socket socket;
};
