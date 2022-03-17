#include "blocks/BlockFactory.h"
#include "blocks/ActuatorAnalogMockBlock.h"
#include "blocks/ActuatorLogicBlock.h"
#include "blocks/ActuatorOffsetBlock.h"
#include "blocks/ActuatorPwmBlock.h"
#include "blocks/BalancerBlock.h"
#include "blocks/DS2408Block.h"
#include "blocks/DS2413Block.h"
#include "blocks/DigitalActuatorBlock.h"
#include "blocks/MockPinsBlock.h"
#include "blocks/MotorValveBlock.h"
#include "blocks/MutexBlock.h"
#include "blocks/PidBlock.h"
#include "blocks/SetpointProfileBlock.h"
#include "blocks/SetpointSensorPairBlock.h"
#include "blocks/TempSensorCombiBlock.h"
#include "blocks/TempSensorMockBlock.h"
#include "blocks/TempSensorOneWireBlock.h"

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
});

cbox::CboxExpected<std::shared_ptr<cbox::Object>> makeBlock(const cbox::obj_type_t& t)
{
    return blocksFactory.make(t);
}
