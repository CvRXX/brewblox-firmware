#pragma once

#include "httpserver/connection.hpp"
#include "httpserver/server.hpp"
#include "network/CboxServer.hpp"
#include "network/wifi.hpp"
#include "ota.hpp"

class HttpHandler {

public:
    HttpHandler(asio::io_context& io, const uint16_t& port, CboxServer& cboxServer)
        : server{io, 80}
        , cboxServer(cboxServer)
    {
        server.add_uri_handler("/", "text/html", [](const http::server::request& req, http::server::reply& rep) {
            rep.status = http::server::reply::ok;
            rep.content.append(
                R"(<!doctype html>)"
                R"(<html lang=en>)"
                R"(<head>)"
                R"(<meta charset=utf-8>)"
                R"(<title>This is the Spark 4 status page. For now it only contains a link for WiFi setup.</title>)"
                R"(</head>)"
                R"(<body>)"
                R"(<p>)"
                R"(Spark 4 status page)"
                R"(</p><p>)"
                R"(<a href=')");

            wifi::append_qr_url(rep.content);
            rep.content.append(R"('>Click here to generate a QR code for WiFi setup</a>)");
            // ending tags are implicit
        });

        server.add_uri_handler("/firmware_update", "text/html", [&cboxServer](const http::server::request& req, http::server::reply& rep) {
            if (req.method != "POST") {
                rep = http::server::reply::stock_reply(http::server::reply::method_not_allowed);
                rep.headers.push_back({"Allow", "POST"});
            } else {
                rep.status = http::server::reply::ok;
                rep.content.append("Received firmware update url: ");
                rep.content.append(req.content);
                cboxServer.do_await_stop();
                start_ota(req.content, true);
            }
        });
    }

private:
    http::server::server server;
    CboxServer& cboxServer;
};
