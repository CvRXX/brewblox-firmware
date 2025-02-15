#pragma once
#include "intellisense.hpp"

#include "SimulatorBox.hpp"
#include <boost/asio.hpp>

class BufferResponseWriter final : public ResponseWriter {
private:
    boost::asio::streambuf& buf;

public:
    explicit BufferResponseWriter(boost::asio::streambuf& buf_)
        : buf(buf_)
    {
    }

    BufferResponseWriter(const BufferResponseWriter&) = delete;
    BufferResponseWriter& operator=(const BufferResponseWriter&) = delete;
    BufferResponseWriter(BufferResponseWriter&&) = delete;
    BufferResponseWriter& operator=(BufferResponseWriter&&) = delete;
    ~BufferResponseWriter() override = default;

    bool write(const std::string& message) final
    {
        if (buf.size() + message.size() <= buf.max_size()) {
            buf.sputn(message.c_str(), static_cast<std::streamsize>(message.size()));
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
            buf.sputn(message.c_str(), static_cast<std::streamsize>(message.size()));
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
private:
    boost::asio::streambuf _bufferIn;
    boost::asio::streambuf _bufferOut;
    CboxConnectionManager& _connectionManager;
    bool _writing = false;

public:
    explicit CboxConnection(CboxConnectionManager& connectionManager_);

    CboxConnection(const CboxConnection&) = delete;
    CboxConnection& operator=(const CboxConnection&) = delete;
    CboxConnection(CboxConnection&&) = delete;
    CboxConnection& operator=(CboxConnection&&) = delete;
    virtual ~CboxConnection() = default;

    virtual void start();
    virtual void stop();
    // virtual dispatch because only derived class knows stream type to pass to templated async read/write
    virtual void async_write_impl(boost::asio::streambuf& buffer_out, std::shared_ptr<CboxConnection> self) = 0;
    virtual void async_read_impl(boost::asio::streambuf& buffer_in, std::shared_ptr<CboxConnection> self) = 0;

    void start_read();
    void start_write();
    void finish_write(std::error_code ec, std::size_t bytes_transferred);
    void finish_read(std::error_code ec, std::size_t bytes_transferred);

protected:
    void handle_read(std::error_code ec, std::size_t bytes_transferred);
    void handle_write(std::error_code ec, std::size_t bytes_transferred);

    auto& bufferIn()
    {
        return _bufferIn;
    }

    auto& bufferOut()
    {
        return _bufferOut;
    }
};
