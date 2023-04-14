#pragma once

#include <memory>

#include "Coffee.h"


class CoffeeCreator
{
public:
    virtual std::unique_ptr<Coffee> getCoffee() = 0;

protected:
    float componentsCost;
    float coffeePrice;
};