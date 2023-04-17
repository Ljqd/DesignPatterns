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
        CarBuilder<CarType>& setWheels(std::unique_ptr<Wheels> wheels);
    protected:
        std::unique_ptr<Car> car;
    };

    template<typename CarType>
    CarBuilder<CarType>::CarBuilder()
    {
        reset();
    }

    template<typename CarType>
    void CarBuilder<CarType>::reset()
    {
        car = std::make_unique<CarType>();
    }

    template<typename CarType>
    std::unique_ptr<Car> CarBuilder<CarType>::getCar()
    {
        return std::move(car);
    }

    template<typename CarType>
    CarBuilder<CarType>& CarBuilder<CarType>::setColor(Color color)
    {
        car->setColor(color);
        return *this;
    }

    template<typename CarType>
    CarBuilder<CarType>& CarBuilder<CarType>::setEngine(std::unique_ptr<Engine> engine)
    {
        car->setEngine(engine);
        return *this;
    }

    template<typename CarType>
    CarBuilder<CarType>& CarBuilder<CarType>::setTransmission(std::unique_ptr<Transmission> transmission)
    {
        car->setTransmission(transmission);
        return *this;
    }

    template<typename CarType>
    CarBuilder<CarType>& CarBuilder<CarType>::setWheels(std::unique_ptr<Wheels> wheels)
    {
        car->setWheels(wheels);
        return *this;
    }
}

