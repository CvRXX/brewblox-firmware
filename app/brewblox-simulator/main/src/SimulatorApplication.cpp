#include "SimulatorSystem.hpp"
#include "blocks/BlockFactory.hpp"
#include "blocks/OneWireScanningFactory.hpp"
#include "cbox/Application.hpp"
#include "cbox/EepromObjectStorage.hpp"
#include "cbox/FileObjectStorage.hpp"
#include "cbox/Hex.hpp"

namespace cbox {

ObjectContainer& getObjects()
{
    static ObjectContainer objects;
    return objects;
}

ObjectStorage& getStorage()
{
    static FileObjectStorage objectStore{"./"};
    return objectStore;
}

ObjectStorage& getCacheStorage()
{
    static ArrayEepromAccess<2048> eeprom;
    static EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

CboxExpected<std::shared_ptr<Object>> make(obj_type_t t)
{
    return makeBlock(t);
}

std::shared_ptr<Object> scan()
{
    static OneWireScanningFactory oneWireScanner{CboxPtr<OneWire>(4)};
    return oneWireScanner.scan();
}

std::string handshakeMessage()
{
    auto version = versionCsv();
    auto id = getDeviceId();
    auto hexResetReason = cbox::d2h(resetReason());
    auto hexResetReasonData = cbox::d2h(resetReasonData());

    std::string message = "!BREWBLOX,";
    message.reserve(message.size()
                    + version.size()
                    + 1 // comma
                    + 2 // reset reason
                    + 1 // comma
                    + 2 // reset reason data
                    + 1 // comma
                    + id.size());

    message += version;
    message += ',';
    message += hexResetReason.first;
    message += hexResetReason.second;
    message += ',';
    message += hexResetReasonData.first;
    message += hexResetReasonData.second;
    message += ',';
    message += id;

    return message;
}

} // end namespace cbox
