#include "Coffee.h"

float Coffee::getComponentsCost() const
{
    return componentsCost;
}

float Coffee::getPrice() const
{
    return price;
}

void Coffee::setComponentsCost(float newCost)
{
    if (newCost <= 0)
        throw("Drink::setComponentsCost: newCost <= 0");
    componentsCost = newCost;
}

void Coffee::setPrice(float newPrice)
{
    if (newPrice <= 0)
        throw("Drink::setComponentsCost: newPrice <= 0");
    price = newPrice;
}