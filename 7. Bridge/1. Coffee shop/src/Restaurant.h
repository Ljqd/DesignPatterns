#pragma once

#include "ConsumptionPlace.h"

class Restaurant : public ConsumptionPlace
{
public:
    std::string getName() const override {
        std::cout << "ConsumptionPlace: restaurant;" << std::endl;
        return "ConsumptionPlace: restaurant;";
    }
};