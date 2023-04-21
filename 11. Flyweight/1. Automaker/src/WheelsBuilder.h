#pragma once

#include <memory>

#include "Wheels.h"

namespace CarModule
{
    class WheelsBuilder
    {
    public:
        WheelsBuilder();

        void reset();
        std::shared_ptr<Wheels> build();

        WheelsBuilder& setMaterial(Wheels::Material material);
        WheelsBuilder& setDiameter(float diameter);

    private:
        std::shared_ptr<Wheels> product;
    };
}
