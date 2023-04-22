#include "HydraulicTransmission.h"

using namespace CarModule;

std::shared_ptr<Transmission> HydraulicTransmission::clone() {
    return std::make_shared<HydraulicTransmission>(*this);
}