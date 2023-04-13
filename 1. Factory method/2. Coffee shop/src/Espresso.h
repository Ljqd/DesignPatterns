#pragma once

#include <string>

#include "Coffee.h"

class Espresso : public Coffee
{
public:
    Espresso(float componentsCost, float cost);

    std::string getName() const override;
};