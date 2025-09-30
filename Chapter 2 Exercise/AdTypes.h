#pragma once

#include <cstdint>

#include "AdConstants.h"

namespace Ad
{
    enum class LaneAssociationType
    {
        UNKNOWN,
        LEFT,
        CENTER,
        RIGHT,
    };
    struct VehicleType
    {
        std::int64_t id;
        LaneAssociationType lane;
        float speed;// Speed (meter/s)
        float relative_distance;// Relative Distance (meter)
    };
}