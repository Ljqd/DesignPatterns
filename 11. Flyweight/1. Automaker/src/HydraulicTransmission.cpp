#include "HydraulicTransmission.h"

using namespace CarModule;

void HydraulicTransmission::setGears(size_t gears)
{
    if (gears > 6)
        throw("HydraulicTransmission::setGears: size_t gears > 6");
    this->gears = gears;
}

size_t HydraulicTransmission::getGears() const
{
    return gears;
}

std::unique_ptr<Transmission> HydraulicTransmission::clone() {
    return std::make_unique<HydraulicTransmission>(*this);
}