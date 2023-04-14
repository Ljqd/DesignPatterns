#include "CappuccinoCreator.h"

CappuccinoCreator::CappuccinoCreator(float componentsCost, float coffeePrice)
{
    if (componentsCost <= 0)
        throw("CappuccinoCreator: componentCost <= 0");
    if (coffeePrice <= 0)
        throw("CappuccinoCreator: price <= 0");

    this->componentsCost = componentsCost;
    this->coffeePrice = coffeePrice;
}


std::unique_ptr<Coffee> CappuccinoCreator::getCoffee()
{
    return std::make_unique<Cappuccino>(componentsCost, coffeePrice);
}