#pragma once

#include "Latte.h"

class LatteKeurig : public Latte
{
public:
    LatteKeurig(float componentsCost, float cost) : Latte(componentsCost, cost) {};
};