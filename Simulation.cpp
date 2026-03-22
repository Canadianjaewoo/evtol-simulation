#include "Simulation.h"

Simulation::Simulation(std::vector<std::unique_ptr<Vehicle>> fleet, std::size_t chargerCount)
    :fleet_(std::move(fleet)), chargers_(chargerCount)
{
}

void Simulation::run(double durationHours, double dt){
    double time =0.0;
    
    while(time < durationHours){
        for(auto& v : fleet_){
            v->update(dt, chargers_);
        }
        time += dt;
    }
}

const std::vector<std::unique_ptr<Vehicle>>& Simulation::fleet() const{
    return fleet_;
}
