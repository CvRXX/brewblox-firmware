#include "I2cScanningFactory.hpp"
#include "OneWireMultiScanningFactory.hpp"
#include "blocks/ExpOwGpioBlock.hpp"
#include "brewblox.hpp"
#include "cbox/CboxApplication.h"
#include "cbox/FileObjectStorage.h"
#include "cbox/ObjectFactory.h"

namespace cbox {

static const ObjectFactory platformFactory{
    makeFactoryEntry<ExpOwGpioBlock>(),
};

std::tuple<CboxError, std::shared_ptr<Object>> make(const obj_type_t& t)
{
    auto retv = platformFactory.make(t);

    if (!std::get<1>(retv)) {
        retv = brewblox::makeBlock(t);
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
