#include "ElectricEngine.h"

using namespace CarModule;


void ElectricEngine::setChargingTime(size_t time)
{
    chargingTime = time;
}

size_t ElectricEngine::getChargingTime() const
{
    return chargingTime;
}