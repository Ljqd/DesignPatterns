#include "Cappuccino.h"

Cappuccino::Cappuccino(float componentsCost, float cost)
{
    if (componentsCost <= 0)
        throw("Cappuccino constructor: componentCost <= 0");
    if (cost <= 0)
        throw("Cappuccino constructor: price <= 0");

    this->componentsCost = componentsCost;
    this->price = price;
}

std::string Cappuccino::getName() const
{
    return "Cappuccino";
}