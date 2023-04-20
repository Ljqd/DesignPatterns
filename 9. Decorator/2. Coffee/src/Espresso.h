#pragma once

#include "Beverage.h"

class Espresso : public Beverage
{
public:
    Espresso(float cost) : Beverage(cost) {}

    std::string description() const override {
        return "Espresso";
    }

    float cost() const override {
        return cost_;
    }
};