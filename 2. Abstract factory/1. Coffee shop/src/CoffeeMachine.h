#pragma once

#include <memory>

#include "Coffee.h"

class CoffeeMachine
{
public:
    CoffeeMachine(
        const std::pair<float, float>& americanoCost, const std::pair<float, float>& cappuccinoCost,
        const std::pair<float, float>& espressoCost, const std::pair<float, float>& latteCost
    );

    virtual std::unique_ptr<Coffee> getAmericano() const = 0;
    virtual std::unique_ptr<Coffee> getCappuccino() const = 0;
    virtual std::unique_ptr<Coffee> getEspresso() const = 0;
    virtual std::unique_ptr<Coffee> getLatte() const = 0;

    void setAmericanoPrice(float newPrice);
    void setCappuccinoPrice(float newPrice);
    void setEspressoPrice(float newPrice);
    void setLattePrice(float newPrice);

    void setAmericanoComponentsCost(float newCost);
    void setCappuccinoComponentsCost(float newCost);
    void setEspressoComponentsCost(float newCost);
    void setLatteComponentsCost(float newCost);

    float getAmericanoPrice() const;
    float getCappuccinoPrice() const;
    float getEspressoPrice() const;
    float getLattePrice() const;

    float getAmericanoComponentsCost() const;
    float getCappuccinoComponentsCost() const;
    float getEspressoComponentsCost() const;
    float getLatteComponentsCost() const;

    float getProfit(int americanoNumber, int cappuccinoNumber, int espressoNumber, int latteNumber);

protected:
    float americanoPrice, americanoComponentsCost;
    float cappuccinoPrice, cappuccinoComponentsCost;
    float espressoPrice, espressoComponentsCost;
    float lattePrice, latteComponentsCost;

    float machinePrice, maintenanceCost;

private:
    float computeSingleProfit(float price, float componentsCost);
};