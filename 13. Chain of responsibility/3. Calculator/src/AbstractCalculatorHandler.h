#pragma once

#include <iostream>
#include <string>
#include <regex>

#include "CalculatorHandler.h"

class AbstractCalculatorHandler : public CalculatorHandler
{
public:
    AbstractCalculatorHandler() : handler(nullptr) {};

    virtual void setNext(CalculatorHandler* nextHandler) override {
        handler = nextHandler;
    }

    virtual float evaluate(const std::string& input) override {
        if (handler != nullptr)
            return handler->evaluate(input);
        return 0;
    }

protected:
    CalculatorHandler* handler;
};