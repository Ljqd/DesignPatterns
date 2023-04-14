#include "CoffeeMachine.h"


CoffeeMachine::CoffeeMachine(
    const std::pair<float, float>& americanoCost, const std::pair<float, float>& cappuccinoCost,
    const std::pair<float, float>& espressoCost, const std::pair<float, float>& latteCost
)
{
    setAmericanoPrice(americanoCost.first);
    setCappuccinoPrice(cappuccinoCost.first);
    setEspressoPrice(espressoCost.first);
    setLattePrice(latteCost.first);

    setAmericanoComponentsCost(americanoCost.second);
    setCappuccinoComponentsCost(cappuccinoCost.second);
    setEspressoComponentsCost(espressoCost.second);
    setLatteComponentsCost(latteCost.second);
}


void CoffeeMachine::setAmericanoPrice(float newPrice)
{
    if (newPrice <= 0)
        throw("setAmericanoPrice(): newPrice <= 0");
    americanoPrice = newPrice;
}

void CoffeeMachine::setCappuccinoPrice(float newPrice)
{
    if (newPrice <= 0)
        throw("setCappuccinoPrice(): newPrice <= 0");
    cappuccinoPrice = newPrice;
}

void CoffeeMachine::setEspressoPrice(float newPrice)
{
    if (newPrice <= 0)
        throw("setEspressoPrice(): newPrice <= 0");
    espressoPrice = newPrice;
}

void CoffeeMachine::setLattePrice(float newPrice)
{
    if (newPrice <= 0)
        throw("setLattePrice(): newPrice <= 0");
    lattePrice = newPrice;
}


void CoffeeMachine::setAmericanoComponentsCost(float newCost)
{
    if (newCost <= 0)
        throw("setAmericanoComponentsCost(): newCost <= 0");
    americanoComponentsCost = newCost;
}

void CoffeeMachine::setCappuccinoComponentsCost(float newCost)
{
    if (newCost <= 0)
        throw("setCappuccinoComponentsCost(): newCost <= 0");
    cappuccinoComponentsCost = newCost;
}

void CoffeeMachine::setEspressoComponentsCost(float newCost)
{
    if (newCost <= 0)
        throw("setEspressoComponentsCost(): newCost <= 0");
    espressoComponentsCost = newCost;
}

void CoffeeMachine::setLatteComponentsCost(float newCost)
{
    if (newCost <= 0)
        throw("setLatteComponentsCost(): newCost <= 0");
    latteComponentsCost = newCost;
}


float CoffeeMachine::getAmericanoPrice() const
{
    return americanoPrice;
}

float CoffeeMachine::getCappuccinoPrice() const
{
    return cappuccinoPrice;
}

float CoffeeMachine::getEspressoPrice() const
{
    return espressoPrice;
}

float CoffeeMachine::getLattePrice() const
{
    return lattePrice;
}


float CoffeeMachine::getAmericanoComponentsCost() const
{
    return americanoComponentsCost;
}

float CoffeeMachine::getCappuccinoComponentsCost() const
{
    return cappuccinoComponentsCost;
}

float CoffeeMachine::getEspressoComponentsCost() const
{
    return espressoComponentsCost;
}

float CoffeeMachine::getLatteComponentsCost() const
{
    return latteComponentsCost;
}


float CoffeeMachine::getProfit(int americanoNumber, int cappuccinoNumber, int espressoNumber, int latteNumber)
{
    float profit = 0;

    for (int i = 0; i <= americanoNumber; i++)
        profit += computeSingleProfit(americanoPrice, americanoComponentsCost);
    for (int i = 0; i <= cappuccinoNumber; i++)
        profit += computeSingleProfit(cappuccinoPrice, cappuccinoComponentsCost);
    for (int i = 0; i <= espressoNumber; i++)
        profit += computeSingleProfit(espressoPrice, espressoComponentsCost);
    for (int i = 0; i <= latteNumber; i++)
        profit += computeSingleProfit(lattePrice, latteComponentsCost);
    
    return profit;
}

float CoffeeMachine::computeSingleProfit(float price, float componentsCost)
{
    return price - componentsCost;
}