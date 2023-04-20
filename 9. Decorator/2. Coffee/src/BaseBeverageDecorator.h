#pragma once

#include "Beverage.h"

class BaseBeverageDecorator : public Beverage
{
public:
    BaseBeverageDecorator() : wrapper(nullptr) {};
	BaseBeverageDecorator(Beverage* beverage) : wrapper(beverage) {};

    std::string description() const override {
        return wrapper->description();
    }

    float cost() const override {
        return wrapper->cost();
    }

protected:
	Beverage* wrapper;
};