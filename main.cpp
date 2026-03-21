//#include <iostream>
#include <vector>
#include <memory>
#include "Simulation.h"
#include "StatisticsReports.h"
#include "Vehicle.h"
#include "VehicleSpecs.h"

int main(){
    
    std::vector<std::unique_ptr<Vehicle>> fleet;
    
    std::mt19937 gen(42); //
    std::uniform_int_distribution<int> dist(0,4);
    
    std::vector<VehicleSpecs> specs={
        VehicleSpecs::alpha(),  
        VehicleSpecs::beta(),
        VehicleSpecs::charlie(),
        VehicleSpecs::delta(),
        VehicleSpecs::echo()
    };
    
    for(int i = 0; i < 20; i++){
        fleet.push_back(std::make_unique<Vehicle>(specs[dist(gen)]));
    }
    
    Simulation sim(std::move(fleet), 3);
    
    sim.run(3.0, 1.0 / 3600.0);
    
    StatisticsReports stats;
    stats.collect(sim.fleet());
    
    return 0;
}