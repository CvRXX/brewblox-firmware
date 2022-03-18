#include "I2cScanningFactory.hpp"
#include "blocks/BlockFactory.hpp"
#include "blocks/ExpOwGpioBlock.hpp"
#include "blocks/OneWireMultiScanningFactory.hpp"
#include "cbox/Application.hpp"
#include "cbox/FileObjectStorage.hpp"
#include "cbox/ObjectFactory.hpp"

namespace cbox {

static const ObjectFactory platformFactory{
    makeFactoryEntry<ExpOwGpioBlock>(),
};

cbox::CboxExpected<std::shared_ptr<cbox::Object>> make(obj_type_t t)
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

} // end namespace cbox
