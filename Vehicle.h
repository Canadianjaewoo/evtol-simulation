#pragma once

#include <random>
#include "VehicleSpecs.h"
#include "Chargers.h"

enum class States{
    Flying,
    Waiting,
    Charging
};

class Vehicle{
public:
    Vehicle(const VehicleSpecs& specs);
    
    void update(double dt, Chargers& chargers);
    
    const VehicleSpecs& specs() const;
   
    double totalFlightTimeHours() const; 
    double totalChargeTimeHours() const;
    double totalDistanceMiles() const;
    
    int totalFaults() const;
    int passengerCounts() const;
    
private:
    void updateFlying(double dt);
    void updateWaiting(Chargers& chargers);
    void updateCharging(double dt, Chargers& charger); 
    
    VehicleSpecs specs_;
    States states_;
    
    double batteryEnergy_;
    double currentChargeTime_;
    double totalFlightTime_;
    double totalChargeTime_;
    double totalDistance_;
    int totalFaults_;
    
    std::mt19937 rng_;
    std::uniform_real_distribution<double> dist_;
};

