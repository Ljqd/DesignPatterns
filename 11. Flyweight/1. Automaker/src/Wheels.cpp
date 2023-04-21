#include "Wheels.h"

using namespace CarModule;

Wheels::Wheels() : material(Material::LIGHT_ALLOY), diameter(10)
{}

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

std::string Wheels::getSring() const
{
    // later - switch-case will do
    std::string m = material == Material::LIGHT_ALLOY ? "light alloy" : "steel";
    return "Wheels: d(" + std::to_string(diameter) + "), m(" + m + ");";
}

std::shared_ptr<Wheels> Wheels::clone()
{
    return std::make_unique<Wheels>(*this);
}

bool Wheels::operator==(const Wheels& w)
{
    bool s1 = this->getDiameter() == w.getDiameter();
    bool s2 = this->getMaterial() == w.getMaterial();
    return s1 == s2;
}