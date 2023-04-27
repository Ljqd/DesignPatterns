#pragma once

#include <string>

class CalculatorHandler
{
public:
    virtual void setNext(CalculatorHandler* nextHandler) = 0;
    virtual float evaluate(const std::string& input) = 0;
};