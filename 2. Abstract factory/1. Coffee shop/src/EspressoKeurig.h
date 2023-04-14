#pragma once

#include "Espresso.h"

class EspressoKeurig : public Espresso
{
public:
    EspressoKeurig(float componentsCost, float cost) : Espresso(componentsCost, cost){};
};