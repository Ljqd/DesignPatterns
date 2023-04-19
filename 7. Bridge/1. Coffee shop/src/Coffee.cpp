#include "Coffee.h"

void Coffee::prepare()
{
    std::cout << "Coffee has been prepared;";
}

void Coffee::drink()
{
    std::cout << "Coffee has been drunk;";
}

int Coffee::cost() const
{
    return beverageCost;
}

std::string Coffee::getString() const
{
    std::string title = "Tea";
    std::string btypeStr = beverageType->getName();
    std::string placeStr = consumptionPlace->getName();

    std::string result = title + " (" + std::to_string(beverageCost) + ")\n\t" + btypeStr + "\n\t" + placeStr + '\n';
    return result;
}