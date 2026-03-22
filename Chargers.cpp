#include "Chargers.h"

Chargers::Chargers(std::size_t chargerCount)
    :total_(chargerCount), available_(chargerCount)
{
}

bool Chargers::tryAcquire(){
    if(available_ > 0){
        --available_;
        return true;
    }
    return false;
}

void Chargers::release(){
    ++available_;
}



