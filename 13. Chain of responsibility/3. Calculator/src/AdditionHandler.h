#pragma once

#include "AbstractCalculatorHandler.h"

class AdditionHandler : public AbstractCalculatorHandler
{
public:
    virtual float evaluate(const std::string& input) override {
        std::cout << "Addition... ";


        std::regex expression(R"((-?\d+)\s*([\+])\s*(-?\d+))");
        std::smatch match;

        if (std::regex_search(input, match, expression)) {
            std::cout << "Success!" << '\n';;

            float num1 = std::stoi(match[1]);
            float num2 = std::stoi(match[3]);

            return num1 + num2;
        }

        std::cout << "Failed." << '\n';

        if (handler != nullptr)
            return handler->evaluate(input);
        return 0;
    }
};