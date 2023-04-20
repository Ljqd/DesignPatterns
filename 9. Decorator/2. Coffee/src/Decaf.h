#pragma once

#include "Beverage.h"

class Decaf : public Beverage
{
public:
    Decaf(float cost) : Beverage(cost) {}

    std::string description() const override {
        return "Decaf";
    }

    float cost() const override {
        return cost_;
    }
};