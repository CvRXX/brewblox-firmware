#include "blocks/BlockFactory.hpp"
#include "blocks/ActuatorAnalogMockBlock.hpp"
#include "blocks/ActuatorLogicBlock.hpp"
#include "blocks/ActuatorOffsetBlock.hpp"
#include "blocks/ActuatorPwmBlock.hpp"
#include "blocks/BalancerBlock.hpp"
#include "blocks/DS2408Block.hpp"
#include "blocks/DS2413Block.hpp"
#include "blocks/DigitalActuatorBlock.hpp"
#include "blocks/FastPwmBlock.hpp"
#include "blocks/MockPinsBlock.hpp"
#include "blocks/MotorValveBlock.hpp"
#include "blocks/MutexBlock.hpp"
#include "blocks/PidBlock.hpp"
#include "blocks/SequenceBlock.hpp"
#include "blocks/SetpointProfileBlock.hpp"
#include "blocks/SetpointSensorPairBlock.hpp"
#include "blocks/TempSensorCombiBlock.hpp"
#include "blocks/TempSensorExternalBlock.hpp"
#include "blocks/TempSensorMockBlock.hpp"
#include "blocks/TempSensorOneWireBlock.hpp"

static const cbox::ObjectFactory blocksFactory({
    cbox::makeFactoryEntry<TempSensorOneWireBlock>(),
    cbox::makeFactoryEntry<SetpointSensorPairBlock>(),
    cbox::makeFactoryEntry<TempSensorMockBlock>(),
    cbox::makeFactoryEntry<ActuatorAnalogMockBlock>(),
    cbox::makeFactoryEntry<PidBlock>(),
    cbox::makeFactoryEntry<ActuatorPwmBlock>(),
    cbox::makeFactoryEntry<ActuatorOffsetBlock>(),
    cbox::makeFactoryEntry<BalancerBlock>(),
    cbox::makeFactoryEntry<MutexBlock>(),
    cbox::makeFactoryEntry<SetpointProfileBlock>(),
    cbox::makeFactoryEntry<DS2413Block>(),
    cbox::makeFactoryEntry<DigitalActuatorBlock>(),
    cbox::makeFactoryEntry<DS2408Block>(),
    cbox::makeFactoryEntry<MotorValveBlock>(),
    cbox::makeFactoryEntry<ActuatorLogicBlock>(),
    cbox::makeFactoryEntry<MockPinsBlock>(),
    cbox::makeFactoryEntry<TempSensorCombiBlock>(),
    cbox::makeFactoryEntry<TempSensorExternalBlock>(),
    cbox::makeFactoryEntry<SequenceBlock>(),
    cbox::makeFactoryEntry<FastPwmBlock>(),
});

cbox::CboxExpected<std::shared_ptr<cbox::Object>> makeBlock(cbox::obj_type_t t)
{
    return blocksFactory.make(t);
}
