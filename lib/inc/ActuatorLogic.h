/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
 *
 * BrewBlox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewBlox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewBlox. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "ActuatorDigital.h"
#include <functional>
#include <memory>
#include <vector>

namespace ADLogic {
using State = ActuatorDigital::State;
enum class LogicOp : uint8_t {
    OR,
    AND
};

class Section {
protected:
    using lookup_t = std::function<std::shared_ptr<ActuatorDigital>()>;
    std::vector<lookup_t> lookups;

public:
    Section() = default;
    virtual ~Section() = default;

    void add(lookup_t&& act)
    {
        lookups.push_back(act);
    };

    void clear()
    {
        lookups.clear();
    }

    virtual LogicOp op() const = 0;
    virtual State eval() const = 0;
};

class OR : public Section {
public:
    OR() = default;
    virtual ~OR() = default;

    virtual State eval() const override final
    {
        for (auto& lookup : lookups) {
            if (lookup()->state() == State::Active) {
                return State::Active;
            }
        }
        return State::Inactive;
    };

    virtual LogicOp op() const override final
    {
        return LogicOp::OR;
    }
};

class AND : public Section {
public:
    AND() = default;
    virtual ~AND() = default;

    virtual State eval() const override final
    {
        if (lookups.size() == 0) {
            return State::Inactive;
        }
        for (auto& lookup : lookups) {
            if (lookup()->state() != State::Active) {
                return State::Inactive;
            }
        }
        return State::Active;
    };

    virtual LogicOp op() const override final
    {
        return LogicOp::AND;
    }
};

class ActuatorLogic {
private:
    struct LogicSection {
        LogicOp op;
        std::unique_ptr<Section> section;
    };
    std::vector<LogicSection> sections;
    ActuatorDigital& target;

public:
    ActuatorLogic(ActuatorDigital& act)
        : target(act){};

    ActuatorLogic(const ActuatorLogic&) = delete;
    ActuatorLogic& operator=(const ActuatorLogic&) = delete;
    ActuatorLogic(ActuatorLogic&&) = default;
    ActuatorLogic& operator=(ActuatorLogic&&) = default;

    virtual ~ActuatorLogic() = default;

    void addSection(LogicOp op, std::unique_ptr<Section>&& newSection)
    {
        if (sections.size() == 0) {
            op = LogicOp::OR;
        }
        if (sections.size() < 8) {
            sections.push_back({op, std::move(newSection)});
        }
    }

    void clear()
    {
        sections.clear();
    }

    State state() const
    {
        auto result = State::Inactive;
        for (auto& s : sections) {
            auto sectionResult = s.section->eval();
            if (s.op == LogicOp::OR) {
                if (sectionResult == State::Active) {
                    result = State::Active;
                }
            } else if (s.op == LogicOp::AND) {
                if (result == State::Active && sectionResult) {
                    result = State::Active;
                } else {
                    result = State::Inactive;
                }
            } else {
                return State::Unknown;
            }
        }
        return result;
    }

    void update()
    {
        target.state(state());
    }

    const std::vector<LogicSection>& sectionList() const
    {
        return sections;
    };
};
} // end namespace ADLogic

using ActuatorLogic = ADLogic::ActuatorLogic;