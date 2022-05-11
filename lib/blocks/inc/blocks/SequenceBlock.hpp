#pragma once

#include "blocks/Block.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/Enabler.hpp"
#include "control/TicksTypes.hpp"
#include "proto/Sequence.pb.h"
#include "tl/expected.hpp"
#include <functional>

using InstructionResult = tl::expected<blox_Sequence_SequenceStatus, blox_Sequence_SequenceError>;

struct SequenceState {
    uint16_t activeInstruction{0};
    uint32_t activeInstructionStartedAt{0};
    uint32_t disabledAt{0};
    uint32_t disabledDuration{0};
    blox_Sequence_SequenceStatus status{blox_Sequence_SequenceStatus_UNKNOWN};
    blox_Sequence_SequenceError error{blox_Sequence_SequenceError_NONE};
};

class SequenceBlock final : public Block<brewblox_BlockType_Sequence> {
private:
    using RunnerFunc = std::function<InstructionResult(const SequenceState& state)>;

    Enabler _enabler;
    SequenceState _state;
    std::vector<blox_Sequence_Instruction> _instructions;
    RunnerFunc _runner{[](const SequenceState&) { return blox_Sequence_SequenceStatus_DONE; }};

    RunnerFunc makeRunner();

public:
    SequenceBlock() = default;
    ~SequenceBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
};
