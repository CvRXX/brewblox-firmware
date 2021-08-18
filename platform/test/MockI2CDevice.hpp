#pragma once

#include <cstdint>
#include <deque>
#include <memory>

void removeMockI2CDevice(uint8_t address);

class MockI2CDevice {
public:
    MockI2CDevice(uint8_t address)
        : address(address)
    {
    }

    ~MockI2CDevice()
    {
    }

    void read(uint8_t* data, size_t size)
    {
        for (size_t i = 0; i < size; i++) {
            data[i] = sdaBytes.front();
            sdaBytes.pop_front();
        }
    }

    void write(const uint8_t* data, size_t size)
    {
        sdaBytes.clear();
        for (size_t i = 0; i < size; i++) {
            sdaBytes.push_back(data[i]);
        }
        process();
    }

    virtual void process() = 0;

    uint8_t address;

protected:
    std::deque<uint8_t> sdaBytes;
};

void addMockI2CDevice(std::shared_ptr<MockI2CDevice> device);