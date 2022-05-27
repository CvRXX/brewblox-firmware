#include "virtualScreen.hpp"
#include "websocketserver.hpp"
#include <cassert>
#include <vector>
std::vector<uint64_t> graphicsBuffer;

VirtualScreen::VirtualScreen(void (*finishCallback)(void))
    : finishCallback(finishCallback)
{
}

void VirtualScreen::init()
{
}

void VirtualScreen::lock()
{
}

void VirtualScreen::unlock()
{
}

extern std::shared_ptr<listener> webSocketServer;
bool VirtualScreen::writePixels(unsigned int xs, unsigned int xe, unsigned int ys, unsigned int ye, uint8_t* pixels, uint16_t nPixels)
{
    graphicsBuffer.resize(320 * 480);
    for (uint32_t y = ys; y <= ye; y++) {
        for (uint32_t x = xs; x <= xe; x++) {
            uint16_t Rgb565 = ((*(pixels + 1)) << 8) | (*(pixels + 0));

            graphicsBuffer[((y * 480) + x)] = ((uint64_t)Rgb565 << 32) | ((y * 480) + x);
            assert(graphicsBuffer.size() != 0);

            pixels += 2;
        }
    }
    webSocketServer->flush(graphicsBuffer);
    this->finishCallback();
    return true;
}
