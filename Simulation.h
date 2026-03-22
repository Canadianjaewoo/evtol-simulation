#pragma once

#include <vector>
#include <memory>
#include "Vehicle.h"
#include "Chargers.h"

class Simulation{
public:
    Simulation(std::vector<std::unique_ptr<Vehicle>> fleet, std::size_t chargerCount);
    
    void run(double durationHours, double dt);
    
    const std::vector<std::unique_ptr<Vehicle>>& fleet() const;
    
private:
    std::vector<std::unique_ptr<Vehicle>> fleet_;
    Chargers chargers_;

};

