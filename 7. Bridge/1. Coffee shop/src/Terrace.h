#pragma once

#include "ConsumptionPlace.h"

class Terrace : public ConsumptionPlace
{
public:
    std::string getName() const override {
        std::cout << "ConsumptionPlace: terrace;" << std::endl;
        return "ConsumptionPlace: terrace;";
    }
};