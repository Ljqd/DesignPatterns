#include <iostream>
#include <string>

#include "src/Director.h"

int main()
{
    CarModule::Director* director = CarModule::Director::getInstance();

    // Hatchback
    std::shared_ptr<CarModule::Car> standardCar1 = director->getStandardHatchback();
    std::shared_ptr<CarModule::Car> standardCar2 = director->getStandardHatchback();

    std::cout << ((*standardCar1) == (*standardCar2)) << std::endl;

}