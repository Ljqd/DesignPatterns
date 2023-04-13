#pragma once

#include <string>

class Coffee
{
public:
    float getComponentsCost() const;
    float getPrice() const;

    void setComponentsCost(float newCost);
    void setPrice(float newPrice);

    virtual std::string getName() const = 0;

protected:
    float componentsCost;
    float price;
};