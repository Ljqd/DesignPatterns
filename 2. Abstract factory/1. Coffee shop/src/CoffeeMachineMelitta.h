#pragma once

#include "Coffee.h"
#include "AmericanoMelitta.h"
#include "CappuccinoMelitta.h"
#include "EspressoMelitta.h"
#include "LatteMelitta.h"
#include "CoffeeMachine.h"

class CoffeeMachineMelitta : public CoffeeMachine
{
public:
    CoffeeMachineMelitta(
        const std::pair<float, float>& americanoCost, const std::pair<float, float>& cappuccinoCost,
        const std::pair<float, float>& espressoCost, const std::pair<float, float>& latteCost
    ) : CoffeeMachine{ americanoCost, cappuccinoCost, espressoCost, latteCost } {};

    std::unique_ptr<Coffee> getAmericano() const override;
    std::unique_ptr<Coffee> getCappuccino() const override;
    std::unique_ptr<Coffee> getEspresso() const override;
    std::unique_ptr<Coffee> getLatte() const override;
};