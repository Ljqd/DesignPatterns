#pragma once

#include <string>
#include <memory>

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

        std::shared_ptr<Wheels> clone();

    private:
        Material material;
        float diameter;
    };
}