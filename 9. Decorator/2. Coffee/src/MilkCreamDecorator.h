#pragma once

#include "BaseBeverageDecorator.h"

class MilkCreamDecorator : public BaseBeverageDecorator
{
public:
    MilkCreamDecorator(Beverage* beverage) : wrapper(beverage) {};

    std::string description() const override {
        return wrapper->description() + " with milk-cream";
    }

    float cost() const override {
        return wrapper->cost() + 5;
    }

protected:
    Beverage* wrapper;
};