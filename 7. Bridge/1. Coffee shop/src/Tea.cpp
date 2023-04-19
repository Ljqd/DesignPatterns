#include "Tea.h"

void Tea::prepare()
{
    std::cout << "Tea has been prepared;";
}

void Tea::drink()
{
    std::cout << "Tea has been drunk;";
}

int Tea::cost() const
{
    return beverageCost;
}

std::string Tea::getString() const
{
    std::string title = "Tea";
    std::string btypeStr = beverageType->getName();
    std::string placeStr = consumptionPlace->getName();

    std::string result = title + " (" + std::to_string(beverageCost) + ")\n\t" + btypeStr + "\n\t" + placeStr + '\n';
    return result;
}