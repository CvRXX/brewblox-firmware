#pragma once

#include <cstdint>
#include <deque>

class MockI2CDevice {
public:
    MockI2CDevice(uint8_t address)
        : address(address)
    {
    }

    void read(uint8_t data)
    {
        masterToSlave.push_back(data);
    }

    void read(const uint8_t* data, size_t size)
    {
        for (size_t i = 0; i < size; i++) {
            read(data[i]);
        }
    }

    void write(uint8_t data)
    {
        slaveToMaster.push_back(data);
        process();
    }

    void write(const uint8_t* data, size_t size)
    {
        for (size_t i = 0; i < size; i++) {
            write(data[i]);
        }
    }

    virtual void process() = 0;

    uint8_t address;

private:
    std::deque<uint8_t> masterToSlave;
    std::deque<uint8_t> slaveToMaster;
};
