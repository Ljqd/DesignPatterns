#include <iostream>
#include <string>

#include "src/Director.h"

int main()
{
    CarModule::Director director = {};
    std::unique_ptr<CarModule::Car> car = director.getStandardHatchback();

    std::cout << car->getString();
}