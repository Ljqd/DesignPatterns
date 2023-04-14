#pragma once

#include "Coffee.h"
#include "AmericanoKeurig.h"
#include "CappuccinoKeurig.h"
#include "EspressoKeurig.h"
#include "LatteKeurig.h"
#include "CoffeeMachine.h"

class CoffeeMachineKeurig : public CoffeeMachine
{
public:
    CoffeeMachineKeurig(
        const std::pair<float, float>& americanoCost, const std::pair<float, float>& cappuccinoCost,
        const std::pair<float, float>& espressoCost, const std::pair<float, float>& latteCost
    ) : CoffeeMachine{ americanoCost, cappuccinoCost, espressoCost, latteCost } {};

    std::unique_ptr<Coffee> getAmericano() const override;
    std::unique_ptr<Coffee> getCappuccino() const override;
    std::unique_ptr<Coffee> getEspresso() const override;
    std::unique_ptr<Coffee> getLatte() const override;
};