#pragma once

#include "Americano.h"

class AmericanoNestle : public Americano
{
public:
    AmericanoNestle(float componentsCost, float cost) : Americano(componentsCost, cost) {};
};