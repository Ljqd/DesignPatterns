#pragma once

#include <memory>

#include "Espresso.h"
#include "CoffeeMachine.h"


class EspressoMachine : public CoffeeMachine
{
public:
    EspressoMachine(float componentsCost, float coffeePrice);
    std::unique_ptr<Coffee> getCoffee() override;
};