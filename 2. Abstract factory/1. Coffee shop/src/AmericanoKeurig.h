#pragma once

#include "Americano.h"

class AmericanoKeurig : public Americano
{
public:
    AmericanoKeurig(float componentsCost, float cost) : Americano(componentsCost, cost) {};
};