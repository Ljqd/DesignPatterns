#include "AmericanoMachine.h"

AmericanoMachine::AmericanoMachine(float componentsCost, float coffeePrice)
{
    if (componentsCost <= 0)
        throw("AmericanoMachine: componentCost <= 0");
    if (coffeePrice <= 0)
        throw("AmericanoMachine: price <= 0");

    this->componentsCost = componentsCost;
    this->coffeePrice = coffeePrice;
}


std::unique_ptr<Coffee> AmericanoMachine::getCoffee()
{
    return std::make_unique<Americano>(componentsCost, coffeePrice);
}