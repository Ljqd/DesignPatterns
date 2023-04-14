#pragma once

#include "Espresso.h"

class EspressoMelitta : public Espresso
{
public:
    EspressoMelitta(float componentsCost, float cost) : Espresso(componentsCost, cost) {};
};