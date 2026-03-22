#pragma once
#include <cstddef>

class Chargers{

public:
    Chargers(std::size_t chargerCount);
    
    bool tryAcquire();
    void release();

private:
    std::size_t total_;
    std::size_t available_;
    
  //  ~Chargers();

};
