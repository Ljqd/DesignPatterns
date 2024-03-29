#pragma once

#pragma once

#include <memory>

#include "Transmission.h"

namespace CarModule
{
    template<typename TransmissionType>
    class TransmissionBuilder
    {
    public:
        TransmissionBuilder();

        std::unique_ptr<Transmission> build();
        void reset();

        TransmissionBuilder& setGears(size_t gears);

    protected:
        std::unique_ptr<Transmission> product;
    };

    template<typename TransmissionType>
    TransmissionBuilder<TransmissionType>::TransmissionBuilder()
    {
        reset();
    }

    template<typename TransmissionType>
    std::unique_ptr<Transmission> TransmissionBuilder<TransmissionType>::build()
    {
        std::unique_ptr<Transmission> result = std::move(product);
        reset();
        return result;
    }

    template<typename TransmissionType>
    void TransmissionBuilder<TransmissionType>::reset()
    {
        product = std::make_unique<TransmissionType>();
    }

    template<typename TransmissionType>
    TransmissionBuilder<TransmissionType>& TransmissionBuilder<TransmissionType>::setGears(size_t gears)
    {
        product->setGears(gears);
        return *this;
    }
}