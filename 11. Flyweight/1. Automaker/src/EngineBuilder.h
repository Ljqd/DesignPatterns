#pragma once

#include <memory>
#include <tuple>

#include "Engine.h"
#include "FlyweightContainer.h"

namespace CarModule
{
    template<typename EngineType>
    class EngineBuilder
    {
    public:
        EngineBuilder();

        std::shared_ptr<Engine> build();
        void reset();
        EngineBuilder& setCapacity(size_t capacity);
        EngineBuilder& setPower(size_t power);

    protected:
        size_t cachedCapacity;
        size_t cachedPower;

        FlyweightContainer<EngineType> cachedEngines;
    };

    template<typename EngineType>
    EngineBuilder<EngineType>::EngineBuilder()
    {
        reset();
        cachedEngines = {};
    }

    template<typename EngineType>
    std::shared_ptr<Engine> EngineBuilder<EngineType>::build()
    {
        std::tuple<size_t, size_t> tpl = { cachedCapacity, cachedPower };
        std::shared_ptr<EngineType> result = std::make_shared<EngineType>(*cachedEngines.getCachedObject(tpl));
        reset();
        return std::make_shared<EngineType>(*result);
    }

    template<typename EngineType>
    void EngineBuilder<EngineType>::reset()
    {
        cachedCapacity = 0;
        cachedPower = 0;
    }

    template<typename EngineType>
    EngineBuilder<EngineType>& EngineBuilder<EngineType>::setCapacity(size_t capacity)
    {
        cachedCapacity = capacity;
        return *this;
    }

    template<typename EngineType>
    EngineBuilder<EngineType>& EngineBuilder<EngineType>::setPower(size_t power)
    {
        cachedPower = power;
        return *this;
    }
}

