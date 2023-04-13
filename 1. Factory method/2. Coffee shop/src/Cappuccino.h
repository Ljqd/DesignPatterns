#pragma once

#include <string>

#include "Coffee.h"

class Cappuccino : public Coffee
{
public:
    Cappuccino(float componentsCost, float cost);

    std::string getName() const override;
};