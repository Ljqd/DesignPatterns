#pragma once

#include <string>

namespace CarModule
{
    class Wheels
    {
    public:
        enum Material
        {
            STEEL, LIGHT_ALLOY
        };

        Wheels();
        Wheels(Material material, float diameter);

        void setMaterial(Material newMaterial);
        Material getMaterial() const;

        void setDiameter(float diameter);
        float getDiameter() const;

        std::string getSring() const;

    private:
        Material material;
        float diameter;
    };
}