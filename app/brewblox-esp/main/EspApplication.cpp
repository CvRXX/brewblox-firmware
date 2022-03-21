#include "Brewblox.hpp"
#include "I2cScanningFactory.hpp"
#include "blocks/BlockFactory.hpp"
#include "blocks/ExpOwGpioBlock.hpp"
#include "blocks/OneWireMultiScanningFactory.hpp"
#include "cbox/Application.hpp"
#include "cbox/FileObjectStorage.hpp"
#include "cbox/Hex.hpp"
#include "cbox/ObjectFactory.hpp"

namespace cbox {

static const ObjectFactory platformFactory{
    makeFactoryEntry<ExpOwGpioBlock>(),
};

CboxExpected<std::shared_ptr<Object>> make(obj_type_t t)
{
    auto retv = platformFactory.make(t);

    if (!retv) {
        retv = makeBlock(t);
    }

    return retv;
}

std::shared_ptr<Object> scan()
{
    static OneWireMultiScanningFactory oneWireScanner;
    static I2cScanningFactory i2cScanner;

    auto retv = oneWireScanner.scan();

    if (!retv) {
        retv = i2cScanner.scan();
    }

    return retv;
}

ObjectStorage& getStorage()
{
    static FileObjectStorage objectStore{"/blocks/"};
    return objectStore;
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
