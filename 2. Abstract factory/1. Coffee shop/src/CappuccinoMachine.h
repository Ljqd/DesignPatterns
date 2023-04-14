#pragma once

#include <memory>

#include "Cappuccino.h"
#include "CoffeeMachine.h"


class CappuccinoMachine : public CoffeeMachine
{
public:
    CappuccinoMachine(float componentsCost, float coffeePrice);
    std::unique_ptr<Coffee> getCoffee() override;
};