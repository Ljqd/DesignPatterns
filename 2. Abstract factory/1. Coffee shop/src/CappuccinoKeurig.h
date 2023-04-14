#pragma once

#include "Cappuccino.h"

class CappuccinoKeurig : public Cappuccino
{
public:
    CappuccinoKeurig(float componentsCost, float cost) : Cappuccino(componentsCost, cost) {};
};