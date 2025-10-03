#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

namespace Ad
{
namespace Utils
{
float kph_to_mps(const float kph)
{
    return kph / 3.6F;
}
}

namespace Visualize
{


void print_vehicle(const Ad::Types::VehicleType &vehicle)
{
    std::cout << "Vehicle ID: " << vehicle.id << ", Speed: " << vehicle.speed_mps << ", Distance: " << vehicle.distance_m << std::endl;
}

void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType &vehicles)
{
    std::cout << "Neighbor Vehicle IDs: ";
    for (const Types::VehicleType &vehicle : vehicles.left_lane_vehicles)
    {
        print_vehicle(vehicle);
    }
    for (const Types::VehicleType &vehicle : vehicles.center_lane_vehicles)
    {
        print_vehicle(vehicle);
    }
    for (const Types::VehicleType &vehicle : vehicles.right_lane_vehicles)
    {
        print_vehicle(vehicle);
    }
}

void print_scene(const Ad::Types::VehicleType &ego_vehicle, const Types::NeighborVehiclesType &vehicles)
{
    float distance = ego_vehicle.distance_m;
    std::cout << distance << std::endl;
    std::cout << "    \t  L        C        R";
    std::int32_t between_rows_offset = 20;
    for (std::int32_t i=100; i>=-100; i -= between_rows_offset)
    {
        std::cout << i;
        print_neighbour_vehicle_presence_in_range(static_cast<float>(i), vehicles);

    }

}

void print_neighbour_vehicle_presence_in_range(const float range, const Types::NeighborVehiclesType &vehicles)
{
    for (const Types::VehicleType &vehicle : vehicles.left_lane_vehicles)
    {
        if (vehicle.distance_m == range)
        {
                std::cout << "\t\t" << "|\t V \t|";
        }
        else
        {
                std::cout << "|\t\t|";
        }
    }
    for (const Types::VehicleType &vehicle : vehicles.center_lane_vehicles)
    {
        if (vehicle.distance_m == range)
        {
            std::cout << "\t V \t|";
        }
        else
        {
            std::cout << "\t\t|";
        }
    }
    for (const Types::VehicleType &vehicle : vehicles.right_lane_vehicles)
    {
        if (vehicle.distance_m == range)
            std::cout << "\t V \t|" << std::endl;
        else
            std::cout << "\t\t|" << std::endl;
    }
}
} // namespace Visualize

namespace Data
{


Ad::Types::VehicleType init_ego_vehicle()
{
    return Types::VehicleType{
        .id = Constants::EGO_VEHICLE_ID,
        .lane = Types::LaneAssociationType::CENTER,
        .speed_mps = Utils::kph_to_mps(135.0F),
        .distance_m = 0.0F,
    };
}

void init_vehicle(Types::VehicleType &vehicle, const std::int32_t id, const float speed_kph, const float distance_m, Types::LaneAssociationType lane)
{
    vehicle.id = id;
    vehicle.speed_mps = Ad::Utils::kph_to_mps(speed_kph);
    vehicle.distance_m = distance_m;
    vehicle.lane = lane;

}
Types::NeighborVehiclesType init_vehicles()
{
    auto vehicles = Types::NeighborVehiclesType{};
    init_vehicle(vehicles.left_lane_vehicles[0],0, 100.0, 20.0, Types::LaneAssociationType::LEFT);
    init_vehicle(vehicles.left_lane_vehicles[1],1, 120.0, -80.0, Types::LaneAssociationType::LEFT);
    init_vehicle(vehicles.center_lane_vehicles[0], 2, 90.0, 100.0, Types::LaneAssociationType::CENTER);
    init_vehicle(vehicles.center_lane_vehicles[1], 3, 95.0, -20.0, Types::LaneAssociationType::CENTER);
    init_vehicle(vehicles.right_lane_vehicles[0], 4, 110.0, -40.0, Types::LaneAssociationType::RIGHT);
    init_vehicle(vehicles.right_lane_vehicles[1], 5, 90.0, -80.0, Types::LaneAssociationType::RIGHT);
    return vehicles;
}

}
}
