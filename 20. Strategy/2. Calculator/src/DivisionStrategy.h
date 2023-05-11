#pragma once

#include "OperationStrategy.h"

class DivisionStrategy : public OperationStrategy
{
public:
    double execute(double a, double b) const override {
        return a / b;
    }
};