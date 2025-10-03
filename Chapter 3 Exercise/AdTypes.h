#pragma once

#include <cstdint>

#include "AdConstants.h"

#include <array>

namespace Ad
    {
    namespace Types
    {

        enum class LaneAssociationType
        {
            LEFT,
            CENTER,
            RIGHT,
            NONE,
        };

        struct VehicleType
        {
            std::int32_t id;
            LaneAssociationType lane;
            float speed_mps;
            float distance_m;
        };

        struct NeighborVehiclesType
        {
            std::array<VehicleType, Constants::NUM_VEHICLES_ON_LANE> left_lane_vehicles;
            std::array<VehicleType, Constants::NUM_VEHICLES_ON_LANE> center_lane_vehicles;
            std::array<VehicleType, Constants::NUM_VEHICLES_ON_LANE> right_lane_vehicles;
        };

        } // namespace Types
        } // namespace Ad
