#include "I2cScanningFactory.hpp"
#include "OneWireMultiScanningFactory.hpp"
#include "blocks/ExpOwGpioBlock.hpp"
#include "brewblox.hpp"
#include "cbox/FileObjectStorage.h"
#include "cbox/Injection.h"
#include "cbox/ObjectFactory.h"

namespace cbox {

cbox::ObjectContainer objects;

std::tuple<CboxError, std::shared_ptr<Object>> make(const obj_type_t& t)
{
    static const cbox::ObjectFactory platformFactory{cbox::makeFactoryEntry<ExpOwGpioBlock>()};
    static const cbox::ObjectFactory blocksFactory = brewblox::make_blocks_factory();

    auto retv = platformFactory.make(t);

    if (!std::get<1>(retv)) {
        retv = blocksFactory.make(t);
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
    static cbox::FileObjectStorage objectStore{"/blocks/"};
    return objectStore;
}

} // end namespace cbox
