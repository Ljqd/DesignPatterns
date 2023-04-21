#include "MechanicalTransmission.h"

using namespace CarModule;

void MechanicalTransmission::setGears(size_t gears)
{
    if (gears > 6)
        throw("MechanicalTransmission::setGears: size_t gears > 6");
    this->gears = gears;
}

size_t MechanicalTransmission::getGears() const
{
    return gears;
}

std::shared_ptr<Transmission> MechanicalTransmission::clone() {
    return std::make_unique<MechanicalTransmission>(*this);
}