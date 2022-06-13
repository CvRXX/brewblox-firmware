#pragma once
#include "intellisense.hpp"

#include "network/cbox_connection.hpp"
#include <boost/asio.hpp>

class CboxTcpConnection : public CboxConnection {
public:
    explicit CboxTcpConnection(
        asio::ip::tcp::socket socket_,
        CboxConnectionManager& connection_manager_);
    virtual ~CboxTcpConnection() = default;

    // virtual void start();
    virtual void stop() override;

    virtual void async_read_impl(asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self) override;
    virtual void async_write_impl(asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self) override;

private:
    asio::ip::tcp::socket socket;
};
