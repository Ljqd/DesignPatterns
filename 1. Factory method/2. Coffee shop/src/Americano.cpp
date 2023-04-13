#include "Americano.h"

Americano::Americano(float componentsCost, float cost)
{
    if (componentsCost <= 0)
        throw("Americano constructor: componentCost <= 0");
    if (cost <= 0)
        throw("Americano constructor: price <= 0");

    this->componentsCost = componentsCost;
    this->price = price;
}

std::string Americano::getName() const
{
    return "Americano";
}