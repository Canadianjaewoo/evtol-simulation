#include "VehicleSpecs.h"

VehicleSpecs::VehicleSpecs(const std::string& name, 
                           double cruiseSpeed, 
                           double batteryCapacity, 
                           double Time2Charge, 
                           double energyUsePerMile, 
                           int passengerCounts, 
                           double ProbabilityFaultPerHour)
    :name_(name),
    cruiseSpeed_(cruiseSpeed),
    batteryCapacity_(batteryCapacity),
    Time2Charge_(Time2Charge),
    energyUsePerMile_(energyUsePerMile),
    passengerCounts_(passengerCounts),
    ProbabilityFaultPerHour_(ProbabilityFaultPerHour)
{
}

const std::string& VehicleSpecs::name() const{
    return name_;
}

double VehicleSpecs::cruiseSpeed() const{
    return cruiseSpeed_;
}

double VehicleSpecs::batteryCapacity() const{
    return batteryCapacity_;
}

double VehicleSpecs::Time2Charge() const{
    return Time2Charge_;
}

double VehicleSpecs::energyUsePerMile() const{
    return energyUsePerMile_;
}

int VehicleSpecs::passengerCounts() const{
    return passengerCounts_;
}

double VehicleSpecs::ProbabilityFaultPerHour() const{
    return ProbabilityFaultPerHour_;
}

VehicleSpecs VehicleSpecs::alpha(){
    return{"alpha", 120.0, 320.0, 0.6, 1.6, 4, 0.25};
}
VehicleSpecs VehicleSpecs::beta(){    
    return{"bravo", 100.0, 100.0, 0.2, 1.5, 5, 0.10};    
}
VehicleSpecs VehicleSpecs::charlie(){
    return{"charlie", 160.0, 220.0, 0.8, 2.2, 3, 0.05};    
}
VehicleSpecs VehicleSpecs::delta(){
    return{"delta", 90.0, 120.0, 0.62, 0.8, 2, 0.22};
}
VehicleSpecs VehicleSpecs::echo(){
    return{"echo", 30.0, 150.0, 0.3, 5.8, 2, 0.61};
}