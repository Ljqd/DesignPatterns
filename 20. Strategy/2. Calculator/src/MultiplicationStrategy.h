#pragma once

#include "OperationStrategy.h"

class MultiplicationStrategy : public OperationStrategy 
{
public:
    double execute(double a, double b) const override {
        return a * b;
    }
};