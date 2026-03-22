
#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Vehicle.h"


class StatisticsReports{
public:
    void collect(const std::vector<std::unique_ptr<Vehicle>>& fleet);
};


