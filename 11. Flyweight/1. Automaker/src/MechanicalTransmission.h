#pragma once

#include "Transmission.h"

namespace CarModule
{
    class MechanicalTransmission : public Transmission
    {
    public:
        std::shared_ptr<Transmission> clone() override;
    };
}