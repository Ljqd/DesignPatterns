#include "MechanicalTransmission.h"

using namespace CarModule;

std::shared_ptr<Transmission> MechanicalTransmission::clone() {
    return std::make_shared<MechanicalTransmission>(*this);
}