#pragma once

#include "Coffee.h"
#include "AmericanoNestle.h"
#include "CappuccinoNestle.h"
#include "EspressoNestle.h"
#include "LatteNestle.h"
#include "CoffeeMachine.h"

class CoffeeMachineNestle : public CoffeeMachine
{
public:
    CoffeeMachineNestle(
        const std::pair<float, float>& americanoCost, const std::pair<float, float>& cappuccinoCost,
        const std::pair<float, float>& espressoCost, const std::pair<float, float>& latteCost
    ) : CoffeeMachine{ americanoCost, cappuccinoCost, espressoCost, latteCost } {};

    std::unique_ptr<Coffee> getAmericano() const override;
    std::unique_ptr<Coffee> getCappuccino() const override;
    std::unique_ptr<Coffee> getEspresso() const override;
    std::unique_ptr<Coffee> getLatte() const override;
};