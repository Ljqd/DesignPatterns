#pragma once

#include "Car.h"

namespace CarModule
{
    class CarSuv : public Car
    {
    protected:
        std::string getCarName() const override {
            return "CarSuv";
        }

        std::string getString() const override {
            std::string carString = getCarName() + ": \n";
            std::string componentsString = getComponentsString();

            return carString + componentsString;
        }
    };
}