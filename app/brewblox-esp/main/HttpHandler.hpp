#pragma once

#include "httpserver/connection.hpp"
#include "httpserver/server.hpp"

class HttpHandler {

public:
    HttpHandler(asio::io_context& io, const uint16_t& port)
        : server{io, 80}
    {
        server.add_uri_handler("/", "text/html", [](const http::server::request&, http::server::reply& rep) {
            rep.status = http::server::reply::ok;
            rep.content.append(
                R"(<!doctype html>)"
                R"(<html lang=en>)"
                R"(<head>)"
                R"(<meta charset=utf-8>)"
                R"(<title>Spark 4 status page</title>)"
                R"(</head>)"
                R"(<body>)"
                R"(<p>)"
                R"(Spark 4 test page)"
                R"(<br />)");
            // ending tags are implicit
        });

        server.add_uri_handler("/firmware_update", "text/html", [](const http::server::request& req, http::server::reply& rep) {
            if (req.method != "POST") {
                rep = http::server::reply::stock_reply(http::server::reply::method_not_allowed);
                rep.headers.push_back({"Allow", "POST"});
            } else {
                rep.status = http::server::reply::ok;
                rep.content.append("Received firmware update url: ");
                rep.content.append(req.content);
            }
        });
    }

private:
    http::server::server server;
};
