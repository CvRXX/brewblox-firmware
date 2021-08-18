#pragma once

#include <cstdint>
#include <deque>
#include <memory>
#include <vector>

class MockSpiDevice {
public:
    MockSpiDevice(uint8_t ssPin)
        : ssPin(ssPin)
    {
    }

    MockSpiDevice(MockSpiDevice&& other)
        : ssPin(std::move(other.ssPin))
        , masterToSlave(std::move(other.masterToSlave))
        , slaveToMaster(std::move(other.slaveToMaster))
    {
    }

    MockSpiDevice& operator=(MockSpiDevice&& other)
    {
        ssPin = std::move(ssPin);
        masterToSlave = std::move(other.masterToSlave);
        slaveToMaster = std::move(other.slaveToMaster);
        return *this;
    }

    uint8_t read()
    {
        uint8_t data = slaveToMaster.front();
        slaveToMaster.pop_front();
        return data;
    }

    void read(uint8_t* data, size_t size)
    {
        for (size_t i = 0; i < size; i++) {
            data[i] = read();
        }
    }

    void write(uint8_t data)
    {
        masterToSlave.push_back(data);
        process();
    }

    void write(const uint8_t* data, size_t size)
    {
        for (size_t i = 0; i < size; i++) {
            write(data[i]);
        }
    }

    virtual void process() = 0;

    uint8_t ssPin;

protected:
    std::deque<uint8_t> masterToSlave;
    std::deque<uint8_t> slaveToMaster;
};

void addMockSpiDevice(std::unique_ptr<MockSpiDevice>&& device);
void removeMockSpiDevice(uint8_t ssPin);