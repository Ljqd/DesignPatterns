#pragma once

#include <memory>

#include "Latte.h"
#include "CoffeeCreator.h"


class LatteCreator : public CoffeeCreator
{
public:
    LatteCreator(float componentsCost, float coffeePrice);
    std::unique_ptr<Coffee> getCoffee() override;
};