#pragma once

#include <string>

class Beverage
{
public:
    Beverage() : cost_(0) {};
    Beverage(float cost) : cost_(cost) {}

    virtual std::string description() const = 0;
    virtual float cost() const = 0;
protected:
    float cost_;
};

