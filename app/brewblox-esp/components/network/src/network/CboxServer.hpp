#pragma once
#include "CboxConnectionManager.hpp"
#include "CboxTcpConnection.hpp"
#include "esp_log.h"

class CboxServer final {
public:
    explicit CboxServer(asio::io_context& io_context_,
                        const uint16_t& port_)
        : io_context(io_context_)
        , acceptor(io_context)
        , connection_manager{}
    {
        do_await_stop();

        asio::ip::tcp::endpoint endpoint(asio::ip::address_v4::any(), port_);
        acceptor.open(endpoint.protocol());
        acceptor.set_option(asio::ip::tcp::acceptor::reuse_address(true));
        acceptor.bind(endpoint);
        acceptor.listen();

        do_accept();
    }

    CboxServer(const CboxServer&) = delete;
    CboxServer& operator=(const CboxServer&) = delete;
    CboxServer(CboxServer&&) = delete;
    CboxServer& operator=(CboxServer&&) = delete;
    ~CboxServer() = default;

    void do_accept()
    {
        acceptor.async_accept(
            [this](std::error_code ec, asio::ip::tcp::socket socket) {
                // Check whether the server was stopped by a signal before this
                // completion handler had a chance to run.
                if (!acceptor.is_open()) {
                    return;
                }

                if (!ec) {
                    connection_manager.start(
                        std::make_shared<CboxTcpConnection>(std::move(socket),
                                                            connection_manager));
                }

                do_accept();
            });
    }

    void do_await_stop()
    {
        acceptor.close();
        connection_manager.stop_all();
    }

private:
    asio::io_context& io_context;
    asio::ip::tcp::acceptor acceptor;
    CboxConnectionManager connection_manager;
};
