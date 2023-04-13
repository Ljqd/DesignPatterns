#include "CappuccinoMachine.h"

CappuccinoMachine::CappuccinoMachine(float componentsCost, float coffeePrice)
{
    if (componentsCost <= 0)
        throw("CappuccinoMachine: componentCost <= 0");
    if (coffeePrice <= 0)
        throw("CappuccinoMachine: price <= 0");

    this->componentsCost = componentsCost;
    this->coffeePrice = coffeePrice;
}


std::unique_ptr<Coffee> CappuccinoMachine::getCoffee()
{
    return std::make_unique<Cappuccino>(componentsCost, coffeePrice);
}