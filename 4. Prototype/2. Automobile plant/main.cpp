#include <iostream>
#include <string>

#include "src/Director.h"

int main()
{
    CarModule::Director director = {};

    // Hatchback
    std::unique_ptr<CarModule::Car> standardCar1 = director.getStandardHatchback();
    std::unique_ptr<CarModule::Car> premiumCar1 = director.getPremiumHatchback();
    std::unique_ptr<CarModule::Car> electricCar1 = director.getElectricHatchback();

    std::cout << "1 (standard)." + standardCar1->getString();
    std::cout << "1 (premium)." + premiumCar1->getString();
    std::cout << "1 (electric)." + electricCar1->getString();

    // Sedan
    std::unique_ptr<CarModule::Car> standardCar2 = director.getStandardSedan();
    std::unique_ptr<CarModule::Car> premiumCar2 = director.getPremiumSedan();
    std::unique_ptr<CarModule::Car> electricCar2 = director.getElectricSedan();

    std::cout << "2 (standard)." + standardCar2->getString();
    std::cout << "2 (premium)." + premiumCar2->getString();
    std::cout << "2 (electric)." + electricCar2->getString();

    // Suv
    std::unique_ptr<CarModule::Car> standardCar3 = director.getStandardSuv();
    std::unique_ptr<CarModule::Car> premiumCar3 = director.getPremiumSuv();
    std::unique_ptr<CarModule::Car> electricCar3 = director.getElectricSuv();

    std::cout << "3 (standard)." + standardCar3->getString();
    std::cout << "3 (premium)." + premiumCar3->getString();
    std::cout << "3 (electric)." + electricCar3->getString();
}