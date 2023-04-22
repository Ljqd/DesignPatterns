#pragma once

#include <memory>
#include <tuple>

#include "Car.h"
#include "FlyweightContainer.h"

namespace CarModule
{
    template<typename CarType>
    class CarBuilder
    {
        using CarComponentsTuple = std::tuple<
            Color, std::shared_ptr<Engine>,
            std::shared_ptr<Transmission>, std::shared_ptr<Wheels>
        >;

    public:
        CarBuilder();

        void reset();
        std::shared_ptr<Car> getCar();

        CarBuilder<CarType>& setColor(Color color);
        CarBuilder<CarType>& setEngine(std::shared_ptr<Engine> engine);
        CarBuilder<CarType>& setTransmission(std::shared_ptr<Transmission> transmission);
        CarBuilder<CarType>& setWheels(std::shared_ptr<Wheels> wheels);
    protected:
        Color cachedColor;
        std::shared_ptr<Engine> cachedEngine;
        std::shared_ptr<Transmission> cachedTransmission;
        std::shared_ptr<Wheels> cachedWheels;

        FlyweightContainer<CarType> cachedCars;
    };

    // IMPLEMENTATIONS ===================================================

    template<typename CarType>
    CarBuilder<CarType>::CarBuilder()
    {
        reset();
        cachedCars = {};
    }

    template<typename CarType>
    void CarBuilder<CarType>::reset()
    {
        cachedColor = {};
        cachedEngine = nullptr;
        cachedTransmission = nullptr;
        cachedWheels = nullptr;
    }

    template<typename CarType>
    std::shared_ptr<Car> CarBuilder<CarType>::getCar()
    {        
        std::tuple<Color, std::shared_ptr<Engine>, std::shared_ptr<Transmission>, std::shared_ptr<Wheels>> tpl = {
            cachedColor, cachedEngine, cachedTransmission, cachedWheels 
        };
        std::shared_ptr<CarType> result = cachedCars.getCachedObject(tpl);
        reset();
        return result;
    }

    template<typename CarType>
    CarBuilder<CarType>& CarBuilder<CarType>::setColor(Color color)
    {
        this->cachedColor = color;
        return *this;
    }

    template<typename CarType>
    CarBuilder<CarType>& CarBuilder<CarType>::setEngine(std::shared_ptr<Engine> engine)
    {
        this->cachedEngine = engine;
        return *this;
    }

    template<typename CarType>
    CarBuilder<CarType>& CarBuilder<CarType>::setTransmission(std::shared_ptr<Transmission> transmission)
    {
        this->cachedTransmission = transmission;
        return *this;
    }

    template<typename CarType>
    CarBuilder<CarType>& CarBuilder<CarType>::setWheels(std::shared_ptr<Wheels> wheels)
    {
        this->cachedWheels = wheels;
        return *this;
    }
}

