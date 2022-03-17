#pragma once

#include "blocks/Block.h"
#include "blocks/ConstraintsProto.h"
#include "cbox/CboxPtr.h"
#include "control/Balancer.h"

class BalancerBlock : public Block<brewblox_BlockType_Balancer> {
public:
    using Balancer_t = Balancer<blox_Constraints_AnalogConstraint_balanced_tag>;

private:
    Balancer_t balancer;

public:
    BalancerBlock() = default;
    virtual ~BalancerBlock() = default;

    virtual cbox::CboxError read(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError write(const cbox::Payload& payload) override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;
    virtual void* implements(const cbox::obj_type_t& iface) override final;

    Balancer_t& getBalancer()
    {
        return balancer;
    }
};
