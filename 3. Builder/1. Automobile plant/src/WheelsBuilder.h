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
        std::unique_ptr<Wheels> getProduct();

        WheelsBuilder& setMaterial(Wheels::Material material);
        WheelsBuilder& setDiameter(float diameter);

    private:
        std::unique_ptr<Wheels> product;
    };
}
