#pragma once

#include <memory>
#include <tuple>

#include "Wheels.h"
#include "FlyweightContainer.h"

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
        Wheels::Material cachedMaterial;
        float cachedDiameter;

        FlyweightContainer<Wheels> cachedWheels;
    };
}
