#pragma once
#include "intellisense.hpp"

#include "EspBox.hpp"
#include <asio.hpp>

class BufferResponseWriter final : public ResponseWriter {
private:
    asio::streambuf& buf;

public:
    BufferResponseWriter(asio::streambuf& buf_)
        : buf(buf_)
    {
    }

    BufferResponseWriter(const BufferResponseWriter&) = delete;
    BufferResponseWriter& operator=(const BufferResponseWriter&) = delete;

    BufferResponseWriter(BufferResponseWriter&&) = default;
    BufferResponseWriter& operator=(BufferResponseWriter&&) = default;

    ~BufferResponseWriter() = default;

    bool write(const std::string& message) final
    {
        if (buf.size() + message.size() <= buf.max_size()) {
            buf.sputn(message.c_str(), message.size());
            return true;
        }
        return false;
    }

    bool write(char c) final
    {
        if (buf.size() + 1 <= buf.max_size()) {
            buf.sputc(c);
            return true;
        }
        return false;
    }

    bool writeLog(const std::string& message) final
    {
        if (buf.size() + message.size() + 2 <= buf.max_size()) {
            buf.sputc('<');
            buf.sputn(message.c_str(), message.size());
            buf.sputc('>');
            return true;
        }
        return false;
    }

    void commit() final
    {
        buf.pubsync();
    }
};

class CboxConnectionManager;

class CboxConnection : public std::enable_shared_from_this<CboxConnection> {
public:
    CboxConnection(const CboxConnection&) = delete;
    CboxConnection& operator=(const CboxConnection&) = delete;

    explicit CboxConnection(
        CboxConnectionManager& connection_manager_);
    virtual ~CboxConnection() = default;

    virtual void start();
    virtual void stop();
    // virtual dispatch because only derived class knows stream type to pass to templated async read/write
    virtual void async_write_impl(asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self) = 0;
    virtual void async_read_impl(asio::streambuf& buffer_in, std::shared_ptr<CboxConnection> self) = 0;

    void start_read();
    void start_write();
    void finish_write(std::error_code ec, std::size_t bytes_transferred);
    void finish_read(std::error_code ec, std::size_t bytes_transferred);

protected:
    void handle_read(std::error_code ec, std::size_t bytes_transferred);
    void handle_write(std::error_code ec, std::size_t bytes_transferred);

    asio::streambuf buffer_in;
    asio::streambuf buffer_out;
    CboxConnectionManager& connection_manager;
    bool writing = false;
};

using CboxConnectionPtr = std::shared_ptr<CboxConnection>;
