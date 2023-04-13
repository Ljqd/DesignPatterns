#pragma once

#include <string>

#include "Coffee.h"

class Americano : public Coffee
{
public:
    Americano(float componentsCost, float cost);

    std::string getName() const override;
};