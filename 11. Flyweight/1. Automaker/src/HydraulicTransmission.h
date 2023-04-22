#pragma once

#include "Transmission.h"

namespace CarModule
{
    class HydraulicTransmission : public Transmission
    {
    public:
        std::shared_ptr<Transmission> clone() override;
    };
}