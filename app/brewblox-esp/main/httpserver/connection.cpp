//
// connection.cpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2019 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "connection.hpp"
#include "connection_manager.hpp"
#include "request_handler.hpp"
#include <utility>
#include <vector>

namespace http {
namespace server {

    connection::connection(asio::ip::tcp::socket socket,
                           connection_manager& manager, request_handler& handler)
        : socket_(std::move(socket))
        , connection_manager_(manager)
        , request_handler_(handler)
    {
    }

    void connection::start()
    {
        do_read();
    }

    void connection::stop()
    {
        socket_.close();
    }

    void connection::do_read()
    {
        auto self(shared_from_this());
        socket_.async_read_some(asio::buffer(buffer_),
                                [this, self](std::error_code ec, std::size_t bytes_transferred) {
                                    if (!ec) {
                                        auto begin = buffer_.data();
                                        auto end = buffer_.data() + bytes_transferred;
                                        char* data_remaining = begin;
                                        if (!request_.parsed) {
                                            request_parser::result_type result;
                                            std::tie(result, data_remaining) = request_parser_.parse(
                                                request_, begin, end);
                                            if (result == request_parser::good) {
                                                request_.parsed = true;
                                            } else if (result == request_parser::bad) {
                                                reply_ = reply::stock_reply(reply::bad_request);
                                                do_write();
                                            }
                                        }
                                        if (request_.parsed) {
                                            // read body and append to request content
                                            auto content_len = request_.content_length();
                                            auto content_end = std::min(data_remaining + content_len, end);
                                            request_.content.append(data_remaining, content_end);
                                            if (request_.content.size() >= content_len) {
                                                // request parsed and content fully received
                                                request_handler_.handle_request(request_, reply_);
                                                do_write();
                                            }
                                        }
                                        do_read(); // read remainder of message

                                    } else if (ec != asio::error::operation_aborted) {
                                        connection_manager_.stop(shared_from_this());
                                    }
                                });
    }

    void connection::do_write()
    {
        auto self(shared_from_this());
        asio::async_write(socket_, reply_.to_buffers(),
                          [this, self](std::error_code ec, std::size_t) {
                              if (!ec) {
                                  // Initiate graceful connection closure.
                                  asio::error_code ignored_ec;
                                  socket_.shutdown(asio::ip::tcp::socket::shutdown_both,
                                                   ignored_ec);
                              }

                              if (ec != asio::error::operation_aborted) {
                                  connection_manager_.stop(shared_from_this());
                              }
                          });
    }

} // namespace server
} // namespace http
