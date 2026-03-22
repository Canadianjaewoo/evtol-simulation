#pragma once

#include <string>

class VehicleSpecs
{
public:
    VehicleSpecs(const std::string& name, 
                    double cruiseSpeed, 
                    double batteryCapacity, 
                    double Time2Charge, 
                    double energyUsePerMile, 
                    int passengerCounts, 
                    double ProbabilityFaultPerHour);
    
    const std::string& name() const;
    double cruiseSpeed() const;
    double batteryCapacity() const;
    double Time2Charge() const;
    double energyUsePerMile() const;
    int passengerCounts() const;
    double ProbabilityFaultPerHour() const;
    
    static VehicleSpecs alpha();
    static VehicleSpecs beta();
    static VehicleSpecs charlie();
    static VehicleSpecs delta();
    static VehicleSpecs echo();
    

private:
    std::string name_;
    double cruiseSpeed_;
    double batteryCapacity_;
    double Time2Charge_;
    double energyUsePerMile_;
    int passengerCounts_;
    double ProbabilityFaultPerHour_;

};

