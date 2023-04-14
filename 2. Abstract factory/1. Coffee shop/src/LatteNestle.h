#pragma once

#include "Latte.h"

class LatteNestle : public Latte
{
public:
    LatteNestle(float componentsCost, float cost) : Latte(componentsCost, cost) {};
};