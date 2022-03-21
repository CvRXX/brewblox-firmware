#include "blocks/BlockFactory.hpp"
#include "blocks/OneWireBusBlock.hpp"
#include "blocks/OneWireScanningFactory.hpp"
#include "cbox/Application.hpp"
#include "cbox/CboxPtr.hpp"
#include "cbox/EepromObjectStorage.hpp"
#include "cbox/Hex.hpp"
#include "cbox/ObjectFactory.hpp"
#include "control/OneWire.hpp"
#include "spark/Brewblox.hpp"
#include "spark/SparkEepromAccess.hpp"

namespace cbox {

ObjectStorage& getStorage()
{
    static SparkEepromAccess eeprom;
    static EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

tl::expected<std::shared_ptr<cbox::Object>, cbox::CboxError> make(obj_type_t t)
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
    auto& version = versionCsv();
    auto& id = deviceIdString();
    auto hexResetReason = cbox::d2h(resetReason());
    auto hexResetReasonData = cbox::d2h(resetReasonData());

    std::string message = "<!BREWBLOX,";

    message.reserve(message.size()
                    + version.size()
                    + 1 // comma
                    + 2 // reset reason
                    + 1 // comma
                    + 2 // reset reason data
                    + 1 // comma
                    + id.size()
                    + 1 // '>' terminator
    );

    message += version;
    message += ',';
    message += hexResetReason.first;
    message += hexResetReason.second;
    message += ',';
    message += hexResetReasonData.first;
    message += hexResetReasonData.second;
    message += ',';
    message += id;
    message += '>';

    return message;
}

} // end namespace cbox
