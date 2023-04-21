#pragma once

#include <memory>

#include "Engine.h"

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
        std::shared_ptr<Engine> product;
    };

    template<typename EngineType>
    EngineBuilder<EngineType>::EngineBuilder()
    {
        reset();
    }

    template<typename EngineType>
    std::shared_ptr<Engine> EngineBuilder<EngineType>::build()
    {
        std::shared_ptr<Engine> result = std::move(product);
        reset();
        return result;
    }

    template<typename EngineType>
    void EngineBuilder<EngineType>::reset()
    {
        product = std::make_unique<EngineType>();
    }

    template<typename EngineType>
    EngineBuilder<EngineType>& EngineBuilder<EngineType>::setCapacity(size_t capacity)
    {
        product->setCapacity(capacity);
        return *this;
    }

    template<typename EngineType>
    EngineBuilder<EngineType>& EngineBuilder<EngineType>::setPower(size_t power)
    {
        product->setPower(power);
        return *this;
    }
}

