#include <iostream>
#include <string>

#include "src/Coffee.h"
#include "src/Chocolate.h"
#include "src/Tea.h"

#include "src/Black.h"
#include "src/WithMilk.h"

#include "src/Terrace.h"
#include "src/Restaurant.h"

int main()
{
    Beverage* coffee = new Coffee();

    BeverageType* btype = new Black();
    ConsumptionPlace* place = new Terrace();

    coffee->setCost(30);
    coffee->setBeverageType(btype);
    coffee->setConsumptionPlace(place);

    std::string beverageStr = coffee->getString();
    std::cout << beverageStr;
}