#pragma once

#include "OperationStrategy.h"

class AdditionStrategy : public OperationStrategy 
{
public:
    double execute(double a, double b) const override {
        return a + b;
    }
};