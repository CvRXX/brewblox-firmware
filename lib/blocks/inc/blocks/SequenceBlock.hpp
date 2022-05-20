#pragma once

#include "blocks/Block.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/Enabler.hpp"
#include "control/TicksTypes.hpp"
#include "proto/Sequence.pb.h"
#include "tl/expected.hpp"
#include <functional>

struct SequenceState {
    bool stored{false};
    uint16_t activeInstruction{0};
    utc_seconds_t activeInstructionStartedAt{0};
    utc_seconds_t disabledAt{0};
    duration_seconds_t disabledDuration{0};
    blox_Sequence_SequenceStatus status{blox_Sequence_SequenceStatus_UNKNOWN};
    blox_Sequence_SequenceError error{blox_Sequence_SequenceError_NONE};
};

class SequenceBlock;

using InstructionResult = tl::expected<blox_Sequence_SequenceStatus, blox_Sequence_SequenceError>;
using InstructionFunctor = std::function<InstructionResult(SequenceBlock& sequence)>;

class SequenceBlock final : public Block<brewblox_BlockType_Sequence> {
private:
    SequenceState _state;
    std::vector<cbox::obj_id_t> _changedTargets;
    std::vector<blox_Sequence_Instruction> _instructions;
    InstructionFunctor _runner{[](SequenceBlock& sequence) { return blox_Sequence_SequenceStatus_DONE; }};

    InstructionFunctor makeRunner();
    void trySaveChanges(utc_seconds_t utc);
    void transition(SequenceState&& state);

public:
    Enabler enabler;

    SequenceBlock() = default;
    ~SequenceBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
    void* implements(cbox::obj_type_t iface) override;

    void reset(uint16_t activeInstruction, utc_seconds_t activeInstructionStartedAt = 0);
    void markTargetChanged(cbox::obj_id_t objId);

    const SequenceState& state() const
    {
        return _state;
    }
};
