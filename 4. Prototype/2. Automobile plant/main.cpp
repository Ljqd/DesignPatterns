#include <iostream>
#include <string>

#include "src/Director.h"

int main()
{
    CarModule::Director director = {};

    // Hatchback
    std::unique_ptr<CarModule::Car> standardCar1 = director.getStandardHatchback();
    std::unique_ptr<CarModule::Car> premiumCar1 = director.getPremiumSedan();
    std::unique_ptr<CarModule::Car> electricCar1 = director.getElectricSuv();

    // clone
    std::unique_ptr<CarModule::Car> standardCar2 = standardCar1->clone();
    std::unique_ptr<CarModule::Car> premiumCar2 = premiumCar1->clone();
    std::unique_ptr<CarModule::Car> electricCar2 = electricCar1->clone();

    std::cout << "Original:\n";

    std::cout << "1 (standard)." + standardCar1->getString();
    std::cout << "2 (premium)." + premiumCar1->getString();
    std::cout << "3 (electric)." + electricCar1->getString();

    std::cout << "\nCloned:\n";

    // now let's perform some modifications:
    standardCar2->getEngine().setPower(9999);
    premiumCar2->getTransmission().setGears(2);
    electricCar2->getWheels().setDiameter(1000);


    std::cout << "1 (standard-cloned)." + standardCar2->getString();
    std::cout << "2 (premium-cloned)." + premiumCar2->getString();
    std::cout << "3 (electric-cloned)." + electricCar2->getString();

}