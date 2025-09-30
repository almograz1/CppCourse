#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace Ad
{

    namespace Utils
    {
        float kph_to_mps(const float kph){ return kph / 3.6F;};
    }

    namespace Data
    {
    VehicleType init_ego_vehicle()
    {
        return Ad::VehicleType{.id = -1, .lane = Ad::LaneAssociationType::Center, .speed = Utils::kph_to_mps(135.0F), .relative_distance = 0.0F};
    }
    }
    namespace Visualize
    {
    void print_vehicle(const VehicleType vehicle)
    {
        std::cout << "Vehicle ID: " << vehicle.id << ", Speed: " << vehicle.speed << ", Lane: " << static_cast<std::int32_t>(vehicle.lane) << std::endl;
    }
    }

}