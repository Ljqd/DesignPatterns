#pragma once

#include <memory>

#include "Americano.h"
#include "CoffeeCreator.h"


class AmericanoCreator : public CoffeeCreator
{
public:
    AmericanoCreator(float componentsCost, float coffeePrice);
    std::unique_ptr<Coffee> getCoffee() override;
};