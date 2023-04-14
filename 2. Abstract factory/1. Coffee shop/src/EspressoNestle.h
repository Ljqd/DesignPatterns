#pragma once

#include "Espresso.h"

class EspressoNestle : public Espresso
{
public:
    EspressoNestle(float componentsCost, float cost) : Espresso(componentsCost, cost) {};
};