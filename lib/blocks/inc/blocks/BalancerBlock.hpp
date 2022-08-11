#pragma once

#include "blocks/Block.hpp"
#include "blocks/ConstraintsProto.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/Balancer.hpp"

class BalancerBlock final : public Block<brewblox_BlockType_Balancer> {
public:
    using Balancer_t = Balancer<blox_Constraints_AnalogConstraint_balanced_tag>;

private:
    Balancer_t balancer;

public:
    BalancerBlock() = default;
    ~BalancerBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(cbox::update_t now) override;
    void* implements(cbox::obj_type_t iface) override;

    Balancer_t& getBalancer()
    {
        return balancer;
    }
};
