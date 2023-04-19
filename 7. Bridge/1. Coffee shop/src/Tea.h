#pragma once

#include "Beverage.h"

class Tea : public Beverage
{
public:
    void prepare() override;
    void drink() override;
    int cost() const override;

    std::string getString() const override;
};