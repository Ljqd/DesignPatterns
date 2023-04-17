#pragma once

#include <memory>

#include "Car.h"

namespace CarModule
{
    template<typename CarType>
    class CarBuilder
    {
    public:
        CarBuilder();

        void reset();
        std::unique_ptr<Car> getCar();

        CarBuilder<CarType>& setColor(Color color);
        CarBuilder<CarType>& setEngine(std::unique_ptr<Engine> engine);
        CarBuilder<CarType>& setTransmission(std::unique_ptr<Transmission> transmission);
        CarBuilder<CarType>& setWheels(std::unique_ptr<Wheels>);
    protected:
        std::unique_ptr<Car> car;
    };

    template<typename CarType>
    CarBuilder<CarType>::CarBuilder()
    {
        reset();
    }

    template<typename CarType>
    void reset()
    {
        car = std::make_unique<CarType>();
    }

    template<typename CarType>
    std::unique_ptr<Car> getCar()
    {
        return std::move(car);
    }

    template<typename CarType>
    CarBuilder<CarType>& setColor(Color color);

    template<typename CarType>
    CarBuilder<CarType>& setEngine(std::unique_ptr<Engine> engine);

    template<typename CarType>
    CarBuilder<CarType>& setTransmission(std::unique_ptr<Transmission> transmission);

    template<typename CarType>
    CarBuilder<CarType>& setWheels(std::unique_ptr<Wheels>);
}

