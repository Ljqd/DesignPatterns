#include "Chocolate.h"

void Chocolate::prepare()
{
    std::cout << "Chocolate has been prepared;";
}

void Chocolate::drink()
{
    std::cout << "Chocolate has been drunk;";
}

int Chocolate::cost() const
{
    return beverageCost;
}

std::string Chocolate::getString() const
{
    std::string title = "Chocolate";
    std::string btypeStr = beverageType->getName();
    std::string placeStr = consumptionPlace->getName();

    std::string result = title + " (" + std::to_string(beverageCost) + ")\n\t" + btypeStr + "\n\t" + placeStr + '\n';
    return result;
}