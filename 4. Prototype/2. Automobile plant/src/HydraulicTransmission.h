#pragma once

#include "Transmission.h"

namespace CarModule
{
    class HydraulicTransmission : public Transmission
    {
    public:
        void setGears(size_t gears) override;
        size_t getGears() const override;
    };
}