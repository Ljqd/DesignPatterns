#pragma once

#include "OperationStrategy.h"

class SubtractionStrategy : public OperationStrategy
{
public:
    double execute(double a, double b) const override {
        return a - b;
    }
};