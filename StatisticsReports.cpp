#include "StatisticsReports.h"

void StatisticsReports::collect(
    const std::vector<std::unique_ptr<Vehicle>>& fleet){
    
    double totalFlight = 0.0;
    double totalCharge = 0.0;
    double totalDistance =0.0;
    int totalFaults = 0;
    int totalPassengerMiles = 0;
    
    for (const auto& v : fleet){
        totalFlight += v->totalChargeTimeHours();
        totalCharge += v->totalChargeTimeHours();
        totalDistance += v->totalDistanceMiles();
        totalFaults += v->totalFaults();
        totalPassengerMiles += static_cast<int>(v->totalDistanceMiles() * v->passengerCounts());
    }
        
        std::cout << "Average flight time[hours]: " << totalFlight / fleet.size() << std::endl;
        std::cout << "Average charge time[hours]: " << totalCharge / fleet.size() << std::endl;
        std::cout << "Average distance[miles]: " << totalDistance / fleet.size() << std::endl;
        std::cout << "Total faults: " << totalFaults << std::endl;
        std::cout << "Total passenger miles: " << totalPassengerMiles << std::endl;
        
    }
    



