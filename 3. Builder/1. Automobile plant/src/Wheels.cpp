#include "Wheels.h"

using namespace CarModule;

Wheels::Wheels(Material material, float diameter) : material(material)
{
    if (diameter < 0)
        throw("Wheels(): diameter < 0");
    this->diameter = diameter;
}

void Wheels::setMaterial(Material newMaterial)
{
    material = newMaterial;
}

Wheels::Material Wheels::getMaterial() const
{
    return material;
}

void Wheels::setDiameter(float diameter)
{
    this->diameter = diameter;
}

float Wheels::getDiameter() const
{
    return diameter;
}