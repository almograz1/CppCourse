#pragma once

#include "AdTypes.h"

namespace Ad
{
    namespace Utils
    {

        float kph_to_mps(const float kph);

    } // namespace Utils

    namespace Data
    {

        Types::VehicleType init_ego_vehicle();
        Types::NeighborVehiclesType init_vehicles();

    } // namespace Data

    namespace Visualize
    {

    void print_neighbour_vehicle_presence_in_range(const float range, const Types::NeighborVehiclesType &vehicles);


    void print_vehicle(const Ad::Types::VehicleType &vehicle);

    void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType &vehicles);

    void print_scene(const Ad::Types::VehicleType &ego_vehicle, const Types::NeighborVehiclesType &vehicles);

    } // namespace Visualize

} // namespace Ad
