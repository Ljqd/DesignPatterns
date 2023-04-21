#pragma once

#include "Car.h"

namespace CarModule
{
    class CarHatchback : public Car
    {
    protected:
        std::string getCarName() const override {
            return "CarHatchback";
        }

        std::string getString() const override {
            std::string carString = getCarName() + ": \n";
            std::string componentsString = getComponentsString();

            return carString + componentsString;
        }
        
        std::shared_ptr<Car> clone() override {
            // since we can't copy unique_prt, we have 2 options:
            // - refuse to use unique_prt
            // - clone the object's components explicitly
            auto color = this->color;
            auto engine = this->engine->clone();
            auto transmission = this->transmission->clone();
            auto wheels = this->wheels->clone();

            std::shared_ptr<CarHatchback> newObject = std::make_unique<CarHatchback>();
            newObject->setColor(color);
            newObject->setEngine(engine);
            newObject->setTransmission(transmission);
            newObject->setWheels(wheels);

            return std::move(newObject);
        }
    };
}