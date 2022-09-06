#include "blocks/ActuatorLogicBlock.hpp"
#include "cbox/PayloadConversion.hpp"

blox_ActuatorLogic_Result
DigitalCompare::eval() const
{
    if (auto actPtr = m_lookup.lock()) {
        switch (m_op) {
        case blox_ActuatorLogic_DigitalOperator_OP_VALUE_IS:
            return blox_ActuatorLogic_Result(actPtr->state() == m_rhs);
        case blox_ActuatorLogic_DigitalOperator_OP_VALUE_IS_NOT:
            return blox_ActuatorLogic_Result(actPtr->state() != m_rhs);
        case blox_ActuatorLogic_DigitalOperator_OP_DESIRED_IS:
            return blox_ActuatorLogic_Result(actPtr->desiredState() == m_rhs);
        case blox_ActuatorLogic_DigitalOperator_OP_DESIRED_IS_NOT:
            return blox_ActuatorLogic_Result(actPtr->desiredState() != m_rhs);
        }
        return blox_ActuatorLogic_Result_RESULT_INVALID_DIGITAL_OP;
    }
    return blox_ActuatorLogic_Result_RESULT_BLOCK_NOT_FOUND;
}

void DigitalCompare::write(blox_ActuatorLogic_DigitalCompare& dest, bool includeNotPersisted) const
{
    dest.id = m_lookup.getId();
    dest.op = m_op;
    dest.rhs = blox_IoArray_DigitalState(m_rhs);
    if (includeNotPersisted) {
        dest.result = m_result;
    }
}

blox_ActuatorLogic_Result
AnalogCompare::eval() const
{
    if (auto pvPtr = m_lookup.lock()) {
        switch (m_op) {
        case blox_ActuatorLogic_AnalogOperator_OP_VALUE_LE:
            if (auto val = pvPtr->value()) {
                return blox_ActuatorLogic_Result(*val <= m_rhs);
            } else {
                return blox_ActuatorLogic_Result_RESULT_FALSE;
            }
        case blox_ActuatorLogic_AnalogOperator_OP_VALUE_GE:
            if (auto val = pvPtr->value()) {
                return blox_ActuatorLogic_Result(*val >= m_rhs);
            } else {
                return blox_ActuatorLogic_Result_RESULT_FALSE;
            }
        case blox_ActuatorLogic_AnalogOperator_OP_SETTING_LE:
            if (auto val = pvPtr->setting()) {
                return blox_ActuatorLogic_Result(*val <= m_rhs);
            } else {
                return blox_ActuatorLogic_Result_RESULT_FALSE;
            }
        case blox_ActuatorLogic_AnalogOperator_OP_SETTING_GE:
            if (auto val = pvPtr->setting()) {
                return blox_ActuatorLogic_Result(pvPtr->setting() >= m_rhs);
            } else {
                return blox_ActuatorLogic_Result_RESULT_FALSE;
            }
        }
        return blox_ActuatorLogic_Result_RESULT_INVALID_ANALOG_OP;
    }
    return blox_ActuatorLogic_Result_RESULT_BLOCK_NOT_FOUND;
}

void AnalogCompare::write(blox_ActuatorLogic_AnalogCompare& dest, bool includeNotPersisted) const
{
    dest.id = m_lookup.getId();
    dest.op = m_op;
    dest.rhs = cnl::unwrap(m_rhs);
    if (includeNotPersisted) {
        dest.result = m_result;
    }
}

void ActuatorLogicBlock::writeMessage(blox_ActuatorLogic_Block& message, bool includeNotPersisted) const
{
    message.targetId = target.getId();
    message.enabled = enabler.get();
    if (includeNotPersisted) {
        message.result = m_result;
        message.errorPos = m_errorPos;
    }

    for (pb_size_t i = 0; i < digitals.size() && i < 16; i++) {
        digitals[i].write(message.digital[i], includeNotPersisted);
    }
    message.digital_count = digitals.size();
    for (pb_size_t i = 0; i < analogs.size() && i < 16; i++) {
        analogs[i].write(message.analog[i], includeNotPersisted);
    }
    message.analog_count = analogs.size();

    expression.copy(message.expression, 64);
}

cbox::CboxError ActuatorLogicBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorLogic_Block message = blox_ActuatorLogic_Block_init_zero;
    writeMessage(message, true);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_ActuatorLogic_Block_fields,
                     blox_ActuatorLogic_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
ActuatorLogicBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_ActuatorLogic_Block message = blox_ActuatorLogic_Block_init_zero;
    writeMessage(message, false);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_ActuatorLogic_Block_fields,
                     blox_ActuatorLogic_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError ActuatorLogicBlock::write(const cbox::Payload& payload)
{
    blox_ActuatorLogic_Block message = blox_ActuatorLogic_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_ActuatorLogic_Block_fields)) {
        if (parser.hasField(blox_ActuatorLogic_Block_targetId_tag)) {
            target.setId(message.targetId, objectId());
        }
        if (parser.hasField(blox_ActuatorLogic_Block_enabled_tag)) {
            enabler.set(message.enabled);
        }
        if (parser.hasField(blox_ActuatorLogic_Block_digital_tag)) {
            digitals.clear();
            for (pb_size_t i = 0; i < message.digital_count; i++) {
                digitals.emplace_back(message.digital[i]);
            }
        }
        if (parser.hasField(blox_ActuatorLogic_Block_analog_tag)) {
            analogs.clear();
            for (pb_size_t i = 0; i < message.analog_count; i++) {
                analogs.emplace_back(message.analog[i]);
            }
        }
        if (parser.hasField(blox_ActuatorLogic_Block_expression_tag)) {
            expression = std::string(message.expression);
        }
    }

    return parser.status();
}

cbox::update_t
ActuatorLogicBlock::updateHandler(cbox::update_t now)
{
    if (!enabler.get()) {
        m_result = blox_ActuatorLogic_Result_RESULT_FALSE;
        target.release();
        return now + 1000;
    }

    if (auto targetPtr = target.lock()) {
        m_result = evaluate();
        if (m_result == blox_ActuatorLogic_Result_RESULT_TRUE) {
            targetPtr->desiredState(ActuatorDigitalBase::State::Active);
        } else {
            targetPtr->desiredState(ActuatorDigitalBase::State::Inactive);
        }
    }
    return now + 100; // update every 100ms
}

void* ActuatorLogicBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceIdImpl<Enabler>()) {
        Enabler* ptr = &enabler;
        return ptr;
    }
    return nullptr;
}

blox_ActuatorLogic_Result
ActuatorLogicBlock::evaluate()
{
    for (auto& d : digitals) {
        d.update();
    }

    for (auto& a : analogs) {
        a.update();
    }
    m_errorPos = 0;
    if (expression.empty()) {
        return blox_ActuatorLogic_Result_RESULT_EMPTY;
    }
    auto it = expression.cbegin();
    auto result = eval(it, 0);

    if (result > blox_ActuatorLogic_Result_RESULT_TRUE) {
        m_errorPos = it - expression.cbegin() - 1;
    }
    return result;
}

blox_ActuatorLogic_Result
ActuatorLogicBlock::eval(std::string::const_iterator& it, uint8_t level) const
{
    blox_ActuatorLogic_Result res = blox_ActuatorLogic_Result_RESULT_EMPTY_SUBSTRING;
    while (it < expression.cend()) {
        if (res > blox_ActuatorLogic_Result_RESULT_EMPTY_SUBSTRING) {
            return res;
        }
        auto c = *it;
        ++it;
        if ('a' <= c && c <= 'z') {
            if (res != blox_ActuatorLogic_Result_RESULT_EMPTY_SUBSTRING) {
                return blox_ActuatorLogic_Result_RESULT_UNEXPECTED_COMPARISON;
            }
            auto compare = digitals.cbegin() + (c - 'a');
            if (compare >= digitals.cend()) {
                return blox_ActuatorLogic_Result_RESULT_UNDEFINED_DIGITAL_COMPARE;
            }
            res = compare->result();
        } else if ('A' <= c && c <= 'Z') {
            if (res != blox_ActuatorLogic_Result_RESULT_EMPTY_SUBSTRING) {
                return blox_ActuatorLogic_Result_RESULT_UNEXPECTED_COMPARISON;
            }
            auto compare = analogs.cbegin() + (c - 'A');
            if (compare >= analogs.cend()) {
                return blox_ActuatorLogic_Result_RESULT_UNDEFINED_ANALOG_COMPARE;
            }
            res = compare->result();
        } else if (c == '!') {
            auto rhs = eval(it, level);
            if (rhs > blox_ActuatorLogic_Result_RESULT_TRUE) {
                return rhs; // error
            }
            if (rhs == blox_ActuatorLogic_Result_RESULT_TRUE) {
                return blox_ActuatorLogic_Result_RESULT_FALSE;
            }
            return blox_ActuatorLogic_Result_RESULT_TRUE;
        } else if (c == '|') {
            if (res == blox_ActuatorLogic_Result_RESULT_EMPTY_SUBSTRING) {
                return blox_ActuatorLogic_Result_RESULT_UNEXPECTED_OPERATOR;
            }
            auto rhs = eval(it, level);
            if (rhs > blox_ActuatorLogic_Result_RESULT_TRUE) {
                return rhs; // error
            }
            if (res == blox_ActuatorLogic_Result_RESULT_TRUE) {
                return res;
            }
            return rhs;
        } else if (c == '&') {
            if (res == blox_ActuatorLogic_Result_RESULT_EMPTY_SUBSTRING) {
                return blox_ActuatorLogic_Result_RESULT_UNEXPECTED_OPERATOR;
            }
            auto rhs = eval(it, level);
            if (rhs > blox_ActuatorLogic_Result_RESULT_TRUE) {
                return rhs; // error
            }
            if (res == blox_ActuatorLogic_Result_RESULT_TRUE) {
                return rhs;
            }
            return res;
        } else if (c == '^') {
            if (res == blox_ActuatorLogic_Result_RESULT_EMPTY_SUBSTRING) {
                return blox_ActuatorLogic_Result_RESULT_UNEXPECTED_OPERATOR;
            }
            auto rhs = eval(it, level);
            if (rhs != blox_ActuatorLogic_Result_RESULT_TRUE && rhs != blox_ActuatorLogic_Result_RESULT_FALSE) {
                return rhs; // error
            }
            if (rhs != res) {
                return blox_ActuatorLogic_Result_RESULT_TRUE;
            }
            return blox_ActuatorLogic_Result_RESULT_FALSE;
        } else if (c == '(') {
            if (res == blox_ActuatorLogic_Result_RESULT_EMPTY_SUBSTRING) {
                res = eval(it, level + 1);
            } else {
                return blox_ActuatorLogic_Result_RESULT_UNEXPECTED_OPEN_BRACKET;
            }
        } else if (c == ')') {
            if (level == 0) {
                // first check is to not overwrite earlier error
                return blox_ActuatorLogic_Result_RESULT_UNEXPECTED_CLOSE_BRACKET;
            }
            return res;
        } else {
            return blox_ActuatorLogic_Result_RESULT_UNEXPECTED_CHARACTER;
        }
    }
    if (level > 0) {
        return blox_ActuatorLogic_Result_RESULT_MISSING_CLOSE_BRACKET;
    }
    return res;
}
