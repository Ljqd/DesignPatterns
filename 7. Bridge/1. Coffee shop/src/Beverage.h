#pragma once

#include <iostream>
#include <string>

#include "BeverageType.h"
#include "ConsumptionPlace.h"

class Beverage
{
public:
    virtual void prepare() = 0;
    virtual void drink() = 0;
    virtual int cost() const = 0;

    virtual std::string getString() const = 0;

    void setCost(int newCost) {
        beverageCost = newCost;
    }

    void setConsumptionPlace(ConsumptionPlace* ptr) {
        consumptionPlace = ptr;
    }
    void setBeverageType(BeverageType* ptr) {
        beverageType = ptr;
    }

protected:
    int beverageCost;
    BeverageType* beverageType;
    ConsumptionPlace* consumptionPlace;
};