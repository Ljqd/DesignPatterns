#include "Espresso.h"

Espresso::Espresso(float componentsCost, float cost)
{
    if (componentsCost <= 0)
        throw("Espresso constructor: componentCost <= 0");
    if (cost <= 0)
        throw("Espresso constructor: price <= 0");

    this->componentsCost = componentsCost;
    this->price = cost;
}

std::string Espresso::getName() const
{
    return "Espresso";
}