#pragma once

#include <memory>

#include "Espresso.h"
#include "CoffeeCreator.h"


class EspressoCreator : public CoffeeCreator
{
public:
    EspressoCreator(float componentsCost, float coffeePrice);
    std::unique_ptr<Coffee> getCoffee() override;
};