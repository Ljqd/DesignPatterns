#include "EspressoMachine.h"

EspressoMachine::EspressoMachine(float componentsCost, float coffeePrice)
{
    if (componentsCost <= 0)
        throw("EspressoMachine: componentCost <= 0");
    if (coffeePrice <= 0)
        throw("EspressoMachine: price <= 0");

    this->componentsCost = componentsCost;
    this->coffeePrice = coffeePrice;
}


std::unique_ptr<Coffee> EspressoMachine::getCoffee()
{
    return std::make_unique<Espresso>(componentsCost, coffeePrice);
}