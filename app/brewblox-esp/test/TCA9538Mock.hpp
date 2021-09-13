#pragma once
#include "MockI2CDevice.hpp"
#include <array>
#include <cassert>

class TCA9538Mock : public MockI2CDevice {
public:
    TCA9538Mock(uint8_t lower_address)
        : MockI2CDevice(lower_address + 0x70)
    {
    }

    virtual void process() override final
    {

        auto command = sdaBytes.front();
        sdaBytes.pop_front();
        currentAddress = command;

        // subsequent bytes are writes
        while (sdaBytes.size()) {
            assert(currentAddress < 4);
            auto byte = sdaBytes.front();
            sdaBytes.pop_front();
            registers[currentAddress] = byte;
            currentAddress++;
        }

        // push register values in queue as reply to read
        while (currentAddress < 4) {
            sdaBytes.push_back(registers[currentAddress++]);
        }
    }

    uint8_t currentAddress = 0;
    std::array<uint8_t, 4> registers{};
};
