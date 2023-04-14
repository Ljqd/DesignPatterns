#pragma once

#include <memory>

#include "Cappuccino.h"
#include "CoffeeCreator.h"


class CappuccinoCreator : public CoffeeCreator
{
public:
    CappuccinoCreator(float componentsCost, float coffeePrice);
    std::unique_ptr<Coffee> getCoffee() override;
};