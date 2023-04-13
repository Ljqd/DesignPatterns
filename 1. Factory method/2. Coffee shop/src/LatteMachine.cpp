#include "LatteMachine.h"

LatteMachine::LatteMachine(float componentsCost, float coffeePrice)
{
    if (componentsCost <= 0)
        throw("Latte constructor: componentCost <= 0");
    if (coffeePrice <= 0)
        throw("Latte constructor: price <= 0");

    this->componentsCost = componentsCost;
    this->coffeePrice = coffeePrice;
}

std::unique_ptr<Coffee> LatteMachine::getCoffee()
{
    return std::make_unique<Latte>(componentsCost, coffeePrice);
}