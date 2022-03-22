#pragma once
#include "intellisense.hpp"

#include "cbox/Connection.hpp"
#include <asio.hpp>

class BufferConnectionOut : public cbox::ConnectionOut {
private:
    asio::streambuf& buf;

public:
    BufferConnectionOut(asio::streambuf& buf_)
        : buf(buf_)
    {
    }
    virtual ~BufferConnectionOut() = default;
    BufferConnectionOut(const BufferConnectionOut&) = delete;
    BufferConnectionOut& operator=(const BufferConnectionOut&) = delete;

    virtual cbox::StreamType streamType() const override final
    {
        return cbox::StreamType::Tcp;
    }

    virtual bool write(const std::string& message)
    {
        if (buf.size() + message.size() < buf.max_size()) {
            buf.sputn(message.c_str(), message.size());
            return true;
        }
        return false;
    }

    virtual void commit() override final
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
