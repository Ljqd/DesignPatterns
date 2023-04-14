#pragma once

#include <string>

#include "Coffee.h"

class Latte : public Coffee
{
public:
    Latte(float componentsCost, float cost);

    std::string getName() const override;
};