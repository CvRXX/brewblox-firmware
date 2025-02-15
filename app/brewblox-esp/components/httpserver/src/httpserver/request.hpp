//
// request.hpp
// ~~~~~~~~~~~
//
// Copyright (c) 2003-2019 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include "header.hpp"
#include <string>
#include <vector>

namespace http {
namespace server {

    /// A request received from a client.
    struct request {
        std::string method;
        std::string uri;
        int http_version_major;
        int http_version_minor;
        std::vector<header> headers;
        std::string content;

        size_t content_length() const
        {
            for (auto& h : headers) {
                if (h.name == "Content-Length") {
                    return std::stoul(h.value);
                }
            }
            return 0;
        }
        bool parsed = false;
    };

} // namespace server
} // namespace http
