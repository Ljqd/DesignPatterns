#include "CoffeeMachineKeurig.h"


std::unique_ptr<Coffee> CoffeeMachineKeurig::getAmericano() const
{
    return std::make_unique<AmericanoKeurig>(americanoComponentsCost, americanoPrice);
}

std::unique_ptr<Coffee> CoffeeMachineKeurig::getCappuccino() const
{
    return std::make_unique<CappuccinoKeurig>(cappuccinoComponentsCost, cappuccinoPrice);
}

std::unique_ptr<Coffee> CoffeeMachineKeurig::getEspresso() const
{
    return std::make_unique<EspressoKeurig>(espressoComponentsCost, espressoPrice);
}

std::unique_ptr<Coffee> CoffeeMachineKeurig::getLatte() const
{
    return std::make_unique<LatteKeurig>(latteComponentsCost, lattePrice);
}