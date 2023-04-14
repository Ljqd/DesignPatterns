#include "CoffeeMachineNestle.h"


std::unique_ptr<Coffee> CoffeeMachineNestle::getAmericano() const
{
    return std::make_unique<AmericanoNestle>(americanoComponentsCost, americanoPrice);
}

std::unique_ptr<Coffee> CoffeeMachineNestle::getCappuccino() const
{
    return std::make_unique<CappuccinoNestle>(cappuccinoComponentsCost, cappuccinoPrice);
}

std::unique_ptr<Coffee> CoffeeMachineNestle::getEspresso() const
{
    return std::make_unique<EspressoNestle>(espressoComponentsCost, espressoPrice);
}

std::unique_ptr<Coffee> CoffeeMachineNestle::getLatte() const
{
    return std::make_unique<LatteNestle>(latteComponentsCost, lattePrice);
}