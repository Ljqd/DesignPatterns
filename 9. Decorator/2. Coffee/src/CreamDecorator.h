#pragma once

#include "Beverage.h"

class CreamDecorator : public BaseBeverageDecorator
{
public:
    CreamDecorator(Beverage* beverage) : wrapper(beverage) {};

    std::string description() const override {
        return wrapper->description() + " with cream";
    }

    float cost() const override {
        return wrapper->cost() + 10;
    }

protected:
    Beverage* wrapper;
};