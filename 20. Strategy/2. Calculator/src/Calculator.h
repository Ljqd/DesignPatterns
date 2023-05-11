#pragma once

#include "OperationStrategy.h"

class Calculator
{
public:
    void setStrategy(const OperationStrategy* strategy) {
        this->strategy = strategy;
    }

    double calculate(double a, double b) const {
        if (!strategy) {
            throw "Strategy not set";
        }
        return strategy->execute(a, b);
    }
private:
    const OperationStrategy* strategy = nullptr;
};