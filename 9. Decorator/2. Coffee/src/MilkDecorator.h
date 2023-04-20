#pragma once

#include "BaseBeverageDecorator.h"

class MilkDecorator : public BaseBeverageDecorator
{
public:
    MilkDecorator(Beverage* beverage) : wrapper(beverage) {};

    std::string description() const override {
        return wrapper->description() + " with milk";
    }

    float cost() const override {
        return wrapper->cost() + 3;
    }

protected:
    Beverage* wrapper;
};