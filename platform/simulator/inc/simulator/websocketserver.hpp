//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: WebSocket server, asynchronous
//
//------------------------------------------------------------------------------
#pragma once

#include <algorithm>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
extern std::array<uint64_t, 320 * 480> graphicsBuffer;

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

//------------------------------------------------------------------------------
struct Touch {
    uint16_t x = 0;
    uint16_t y = 0;
    std::atomic_bool touchAvailable;
};

// Report a failure
static void fail(beast::error_code ec, char const* what)
{
    std::cerr << what << ": " << ec.message() << "\n";
}

// Echoes back all received WebSocket messages
class session : public std::enable_shared_from_this<session> {
    websocket::stream<beast::tcp_stream> ws_;
    beast::flat_buffer buffer_;
    net::io_context& ioc;
    boost::asio::steady_timer timer_;
    std::vector<std::shared_ptr<session>>& sessions;
    Touch& touch;

public:
    // Take ownership of the socket
    explicit session(tcp::socket&& socket, net::io_context& ioc, std::vector<std::shared_ptr<session>>& sessions, Touch& touch)
        : ws_(std::move(socket))
        , ioc(ioc)
        , timer_(ioc,
                 (std::chrono::steady_clock::time_point::max)())
        , sessions(sessions)
        , touch(touch)
    {
    }

    // Get on the correct executor
    void run()
    {
        // We need to be executing within a strand to perform async operations
        // on the I/O objects in this session. Although not strictly necessary
        // for single-threaded contexts, this example code is written to be
        // thread-safe by default.
        net::dispatch(
            ws_.get_executor(),
            beast::bind_front_handler(&session::on_run, shared_from_this()));
    }

    // Start the asynchronous operation
    void on_run()
    {
        // Set suggested timeout settings for the websocket
        ws_.set_option(
            websocket::stream_base::timeout::suggested(beast::role_type::server));

        // Set a decorator to change the Server of the handshake
        ws_.set_option(
            websocket::stream_base::decorator([](websocket::response_type& res) {
                res.set(http::field::server, "Brewblox - simulator interface");
            }));
        // Accept the websocket handshake
        ws_.async_accept(
            beast::bind_front_handler(&session::on_accept, shared_from_this()));
    }

    void on_accept(beast::error_code ec)
    {
        std::cout << "connection\n";

        if (ec)
            return fail(ec, "accept");
        write_pixels();
        do_read();
    }

    void write_pixels1(std::array<uint64_t, 320 * 480> pixels)
    {
        auto buffer = boost::asio::buffer(pixels);
        ws_.text(false);
        try {
            ws_.write(buffer);
        } catch (boost::wrapexcept<boost::system::system_error> error) {
        }
    }
    void write_pixels()
    {
        auto buffer = boost::asio::buffer(graphicsBuffer);
        ws_.text(false);
        ws_.async_write(buffer, beast::bind_front_handler(&session::on_write,
                                                          shared_from_this()));
    }

    void do_read()
    {
        ws_.async_read(buffer_, beast::bind_front_handler(&session::on_read,
                                                          shared_from_this()));
    }

    void on_read(beast::error_code ec, std::size_t bytes_transferred)
    {
        if (bytes_transferred != 5) {
            fail(ec, "read");
            do_read();
            return;
        }
        auto touchString = boost::asio::buffer_cast<char*>(buffer_.data());
        std::int8_t index = *touchString;
        std::uint8_t xl = *(touchString + 1);
        std::uint8_t xh = *(touchString + 2);

        std::uint8_t yl = *(touchString + 3);
        std::uint8_t yh = *(touchString + 4);

        std::uint16_t x = (xh * 256) + xl;
        std::uint16_t y = (yh * 256) + yl;

        if (index == 1) {
            this->touch.x = 320 - y;
            this->touch.y = x;
            this->touch.touchAvailable = true;
        }

        buffer_.consume(5);

        if (ec == websocket::error::closed) {
            sessions.erase(std::remove_if(sessions.begin(), sessions.end(), [this](const std::shared_ptr<session>& s) {
                return s.get() == this;
            }));

            return;
        }
        if (ec)
            fail(ec, "read");
        do_read();
    }

    void on_write(beast::error_code ec, std::size_t bytes_transferred)
    {
    }
};

//------------------------------------------------------------------------------

// Accepts incoming connections and launches the sessions
class listener : public std::enable_shared_from_this<listener> {
    net::io_context& ioc_;
    tcp::acceptor acceptor_;

public:
    Touch touch;
    std::vector<std::shared_ptr<session>> sessions;
    listener(net::io_context& ioc, tcp::endpoint endpoint)
        : ioc_(ioc)
        , acceptor_(ioc)
    {
        beast::error_code ec;

        // Open the acceptor
        acceptor_.open(endpoint.protocol(), ec);
        if (ec) {
            fail(ec, "open");
            return;
        }

        // Allow address reuse
        acceptor_.set_option(net::socket_base::reuse_address(true), ec);
        if (ec) {
            fail(ec, "set_option");
            return;
        }

        // Bind to the server address
        acceptor_.bind(endpoint, ec);
        if (ec) {
            fail(ec, "bind");
            return;
        }

        // Start listening for connections
        acceptor_.listen(net::socket_base::max_listen_connections, ec);
        if (ec) {
            fail(ec, "listen");
            return;
        }
    }
    void flush(std::array<uint64_t, 320 * 480> pixels)
    {
        for (auto currentSession : sessions) {
            currentSession->write_pixels1(pixels);
        }
    }
    // Start accepting incoming connections
    void run() { do_accept(); }

private:
    void do_accept()
    {
        // The new connection gets its own strand
        acceptor_.async_accept(
            net::make_strand(ioc_),
            beast::bind_front_handler(&listener::on_accept, shared_from_this()));
    }

    void on_accept(beast::error_code ec, tcp::socket socket)
    {
        if (ec) {
            fail(ec, "accept");
        } else {
            // Create the session and run it
            auto newSession = sessions.emplace_back(std::make_shared<session>(std::move(socket), ioc_, sessions, touch));
            // std::shared_ptr<session>& placeInVector = newSession);
            newSession->run();
        }

        // Accept another connection
        do_accept();
    }
};
