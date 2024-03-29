#pragma once

#include "Transmission.h"

namespace CarModule
{
    class MechanicalTransmission : public Transmission
    {
    public:
        void setGears(size_t gears) override;
        size_t getGears() const override;

        std::unique_ptr<Transmission> clone() override;
    };
}