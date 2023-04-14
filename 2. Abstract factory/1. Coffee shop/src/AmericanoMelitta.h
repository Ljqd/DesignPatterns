#pragma once

#include "Americano.h"

class AmericanoMelitta : public Americano
{
public:
    AmericanoMelitta(float componentsCost, float cost) : Americano(componentsCost, cost) {};
};