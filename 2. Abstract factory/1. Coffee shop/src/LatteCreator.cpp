#include "LatteCreator.h"

LatteCreator::LatteCreator(float componentsCost, float coffeePrice)
{
    if (componentsCost <= 0)
        throw("LatteCreator: componentCost <= 0");
    if (coffeePrice <= 0)
        throw("LatteCreator: price <= 0");

    this->componentsCost = componentsCost;
    this->coffeePrice = coffeePrice;
}

std::unique_ptr<Coffee> LatteCreator::getCoffee()
{
    return std::make_unique<Latte>(componentsCost, coffeePrice);
}