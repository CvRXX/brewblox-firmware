#include "blocks/BalancerBlock.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "pb_encode.h"
#include "proto/Balancer.pb.h"

// stream result of a bus search, with arg pointing to the onewire bus
bool streamBalancedActuators(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto balancerPtr = reinterpret_cast<BalancerBlock::Balancer_t*>(*arg);
    for (const auto& requester : balancerPtr->clients()) {
        auto act = blox_Balancer_BalancedActuator();
        act.id = requester.id;
        act.requested = cnl::unwrap(requester.requested);
        act.granted = cnl::unwrap(requester.granted);
        if (!pb_encode_tag_for_field(stream, field)) {
            return false;
        }
        if (!pb_encode_submessage(stream, blox_Balancer_BalancedActuator_fields, &act)) {
            return false;
        }
    }
    return true;
}

cbox::CboxError
BalancerBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_Balancer_Block message = blox_Balancer_Block_init_zero;

    message.clients.funcs.encode = streamBalancedActuators;
    message.clients.arg = const_cast<Balancer_t*>(&balancer); // arg is not const in message, but it is in callback

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_Balancer_Block_fields,
                           // Include bytes for field tags
                           (blox_Balancer_BalancedActuator_size + 2) * balancer.clients().size());
}

cbox::CboxError
BalancerBlock::readStored(const cbox::PayloadCallback& callback) const
{
    // no settings to persist
    return callWithMessage(callback, objectId(), staticTypeId(), 0);
}

cbox::CboxError
BalancerBlock::write(const cbox::Payload&)
{
    // no settings to write (actuators register themselves)
    return cbox::CboxError::OK;
}

cbox::update_t BalancerBlock::updateHandler(const cbox::update_t& now)
{
    balancer.update();
    return now + 1000;
}

void* BalancerBlock::implements(cbox::obj_type_t iface)
{
    if (iface == brewblox_BlockType_Balancer) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<Balancer_t>()) {
        // return the member that implements the interface in this case
        Balancer_t* ptr = &balancer;
        return ptr;
    }
    return nullptr;
}
