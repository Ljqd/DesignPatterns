#include "CoffeeMachineMelitta.h"


std::unique_ptr<Coffee> CoffeeMachineMelitta::getAmericano() const
{
    return std::make_unique<AmericanoMelitta>(americanoComponentsCost, americanoPrice);
}

std::unique_ptr<Coffee> CoffeeMachineMelitta::getCappuccino() const
{
    return std::make_unique<CappuccinoMelitta>(cappuccinoComponentsCost, cappuccinoPrice);
}

std::unique_ptr<Coffee> CoffeeMachineMelitta::getEspresso() const
{
    return std::make_unique<EspressoMelitta>(espressoComponentsCost, espressoPrice);
}

std::unique_ptr<Coffee> CoffeeMachineMelitta::getLatte() const
{
    return std::make_unique<LatteMelitta>(latteComponentsCost, lattePrice);
}