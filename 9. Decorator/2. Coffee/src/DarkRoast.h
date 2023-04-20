#pragma once

#include "Beverage.h"

class DarkRoast : public Beverage
{
public:
    DarkRoast(float cost) : Beverage(cost) {}

    std::string description() const override {
        return "DarkRoast";
    }

    float cost() const override {
        return cost_;
    }
};