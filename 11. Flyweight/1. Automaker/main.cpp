#include <iostream>
#include <string>

#include "src/Director.h"

int main()
{
    CarModule::Director* director = CarModule::Director::getInstance();

    // Hatchback
    std::shared_ptr<CarModule::Car> standardCar1 = director->getStandardHatchback();
    std::shared_ptr<CarModule::Car> premiumCar1 = director->getPremiumSedan();
    std::shared_ptr<CarModule::Car> electricCar1 = director->getElectricSuv();

    // clone
    std::shared_ptr<CarModule::Car> standardCar2 = standardCar1->clone();
    std::shared_ptr<CarModule::Car> premiumCar2 = premiumCar1->clone();
    std::shared_ptr<CarModule::Car> electricCar2 = electricCar1->clone();

    // now let's perform some modifications:
    standardCar2->getEngine().setPower(9999);
    premiumCar2->getTransmission().setGears(2);
    electricCar2->getWheels().setDiameter(1000);

    std::cout << "\nCloned:\n";

    std::cout << "1 (standard-cloned)." + standardCar2->getString();
    std::cout << "2 (premium-cloned)." + premiumCar2->getString();
    std::cout << "3 (electric-cloned)." + electricCar2->getString();

    std::cout << "Original:\n";

    std::cout << "1 (standard)." + standardCar1->getString();
    std::cout << "2 (premium)." + premiumCar1->getString();
    std::cout << "3 (electric)." + electricCar1->getString();

}