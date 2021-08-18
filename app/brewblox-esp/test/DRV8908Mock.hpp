#pragma once
#include "MockSpiDevice.hpp"
#include <array>

class DRV8908Mock : public MockSpiDevice {
public:
    DRV8908Mock(uint8_t ssPin)
        : MockSpiDevice(ssPin)
    {
    }

    virtual void process() override final
    {
        if (masterToSlave.size() >= 2) {
            auto byte1 = masterToSlave.front();
            masterToSlave.pop_front();
            auto byte2 = masterToSlave.front();
            masterToSlave.pop_front();
            auto address = byte1 & ~uint8_t{0xC0};
            bool isRead = byte1 & uint8_t{0xC0};

            // first byte returned is always status
            slaveToMaster.push_back(registers[int(DRV8908::RegAddr::IC_STAT)]);
            // second byte is always value of register before write
            slaveToMaster.push_back(registers[address]);
            if (isRead) {
            } else {
                registers[address] = byte2;
            }
        }
    }

    std::array<uint8_t, int(DRV8908::RegAddr::OLD_CTRL_6) + 1> registers{};
};
