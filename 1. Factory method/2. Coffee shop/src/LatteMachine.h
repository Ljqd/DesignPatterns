#pragma once

#include <memory>

#include "Latte.h"
#include "CoffeeMachine.h"


class LatteMachine : public CoffeeMachine
{
public:
    LatteMachine(float componentsCost, float coffeePrice);
    std::unique_ptr<Coffee> getCoffee() override;
};