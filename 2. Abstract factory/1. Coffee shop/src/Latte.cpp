#include "Latte.h"

Latte::Latte(float componentsCost, float cost)
{
    if (componentsCost <= 0)
        throw("Latte constructor: componentCost <= 0");
    if (cost <= 0)
        throw("Latte constructor: price <= 0");

    this->componentsCost = componentsCost;
    this->price = cost;
}

std::string Latte::getName() const
{
    return "Latte";
}