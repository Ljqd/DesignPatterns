#pragma once

#include <memory>

#include "Americano.h"
#include "CoffeeMachine.h"


class AmericanoMachine : public CoffeeMachine
{
public:
    AmericanoMachine(float componentsCost, float coffeePrice);
    std::unique_ptr<Coffee> getCoffee() override;
};