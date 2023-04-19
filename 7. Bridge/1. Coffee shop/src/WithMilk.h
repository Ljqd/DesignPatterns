#pragma once

#include "BeverageType.h"

class WithMilk : public BeverageType
{
public:
    std::string getName() const override {
        std::cout << "BeverageType: with milk;" << std::endl;
        return "BeverageType: with milk;";
    }
};