#include "EspressoCreator.h"

EspressoCreator::EspressoCreator(float componentsCost, float coffeePrice)
{
    if (componentsCost <= 0)
        throw("EspressoCreator: componentCost <= 0");
    if (coffeePrice <= 0)
        throw("EspressoCreator: price <= 0");

    this->componentsCost = componentsCost;
    this->coffeePrice = coffeePrice;
}


std::unique_ptr<Coffee> EspressoCreator::getCoffee()
{
    return std::make_unique<Espresso>(componentsCost, coffeePrice);
}