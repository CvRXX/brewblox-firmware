/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
 *
 * BrewPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "control/Enabler.hpp"
#include "control/SetpointSensorPair.hpp"
#include "control/Temperature.hpp"
#include "control/TicksTypes.hpp"
#include <vector>

class SetpointProfile {
public:
    struct Point {
        utc_seconds_t time;
        temp_t temp;
    };

private:
    ControlPtr<SetpointSensorPair>& m_target;
    utc_seconds_t m_profileStartTime = 0;

    std::vector<Point> m_points;

public:
    Enabler enabler;

    explicit SetpointProfile(
        ControlPtr<SetpointSensorPair>& target) // process value to manipulate setpoint of
        : m_target(target)
        , enabler(true)
    {
    }
    SetpointProfile(const SetpointProfile&) = delete;
    SetpointProfile& operator=(const SetpointProfile&) = delete;
    ~SetpointProfile() = default;

    void addPoint(Point&& p)
    {
        m_points.push_back(std::move(p));
    }

    void removeAllPoints()
    {
        m_points.clear();
    }

    bool isDriving() const
    {
        return (enabler.get() && !m_points.empty());
    }

    void update(const utc_seconds_t& time);

    const std::vector<Point>& points() const
    {
        return m_points;
    }

    void points(std::vector<Point>&& newPoints)
    {
        m_points = newPoints;
    }

    utc_seconds_t startTime() const
    {
        return m_profileStartTime;
    }

    void startTime(utc_seconds_t v)
    {
        m_profileStartTime = v;
    }
};
