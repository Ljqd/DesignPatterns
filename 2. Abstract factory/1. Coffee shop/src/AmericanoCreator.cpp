#include "AmericanoCreator.h"

AmericanoCreator::AmericanoCreator(float componentsCost, float coffeePrice)
{
    if (componentsCost <= 0)
        throw("AmericanoCreator: componentCost <= 0");
    if (coffeePrice <= 0)
        throw("AmericanoCreator: price <= 0");

    this->componentsCost = componentsCost;
    this->coffeePrice = coffeePrice;
}


std::unique_ptr<Coffee> AmericanoCreator::getCoffee()
{
    return std::make_unique<Americano>(componentsCost, coffeePrice);
}