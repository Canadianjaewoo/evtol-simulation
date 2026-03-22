
#include "Vehicle.h"

Vehicle::Vehicle(const VehicleSpecs& specs)
    :specs_(specs),
    states_(States::Flying),
    batteryEnergy_(specs.batteryCapacity()),
    currentChargeTime_(0.0),
    totalFlightTime_(0.0),
    totalChargeTime_(0.0),
    totalDistance_(0.0),
    totalFaults_(0),
    //rng_(42),
    rng_(std::random_device{}()),
    dist_(0.0, 1.0){}

void Vehicle::update(double dt, Chargers& chargers){
    if(states_ == States::Flying)
        updateFlying(dt);
    else if(states_ == States::Waiting)
        updateWaiting(chargers);
    else if(states_ == States::Charging)
        updateCharging(dt, chargers);
}


void Vehicle::updateFlying(double dt){
    
    double energyUsePerHour = specs_.cruiseSpeed() * specs_.energyUsePerMile();
    batteryEnergy_ -= energyUsePerHour * dt;
    
    totalFlightTime_ += dt;
    totalDistance_ += specs_.cruiseSpeed() * dt;
    
    double faultProb = specs_.ProbabilityFaultPerHour() * dt;
    if(dist_(rng_) < faultProb){
        totalFaults_++;
    }
    //transition: flying to waiting
    if(batteryEnergy_ <= 0.0){
        batteryEnergy_ =0.0;
        states_ = States::Waiting;
    }
}    

void Vehicle::updateWaiting(Chargers& chargers){
    //wating to charging
    if(chargers.tryAcquire()){
        states_ = States::Charging;
        currentChargeTime_ = 0.0;
    }
}


void Vehicle::updateCharging(double dt, Chargers& chargers){
    currentChargeTime_ += dt;
    totalChargeTime_ += dt;
    //charging to flying
    if(currentChargeTime_ >= specs_.Time2Charge()){
        batteryEnergy_ = specs_.batteryCapacity();
        //currentChargeTime_ = 0.0;
        chargers.release();
        states_ = States::Flying;
    }
}

//getters
const VehicleSpecs& Vehicle::specs() const{
    return specs_;
}

double Vehicle::totalFlightTimeHours() const{
    return totalFlightTime_;
}

double Vehicle::totalChargeTimeHours() const{
    return totalChargeTime_;
}

double Vehicle::totalDistanceMiles() const{
    return totalDistance_;
}

int Vehicle::totalFaults() const{
    return totalFaults_;
}

int Vehicle::passengerCounts() const{
    return specs_.passengerCounts();
}