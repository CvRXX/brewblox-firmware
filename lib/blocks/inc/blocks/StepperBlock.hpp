#pragma once

#include "blocks/Block.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/Stepper.hpp"

class StepperBlock final : public Block<brewblox_BlockType_Stepper> {
private:
    Stepper stepper;

public:
    StepperBlock() = default;
    ~StepperBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
};
