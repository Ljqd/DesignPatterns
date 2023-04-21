#pragma once

#include <memory>
#include <tuple>

#include "Transmission.h"
#include "FlyweightContainer.h"

namespace CarModule
{
    template<typename TransmissionType>
    class TransmissionBuilder
    {
    public:
        TransmissionBuilder();

        std::shared_ptr<Transmission> build();
        void reset();

        TransmissionBuilder& setGears(size_t gears);

    protected:
        size_t cachedGears;

        FlyweightContainer<Transmission> cachedTransmission;
    };

    // =========================================================================

    template<typename TransmissionType>
    TransmissionBuilder<TransmissionType>::TransmissionBuilder()
    {
        reset();
    }

    template<typename TransmissionType>
    std::shared_ptr<Transmission> TransmissionBuilder<TransmissionType>::build()
    {
        std::tuple<size_t> tpl = { cachedGears };
        std::shared_ptr<Transmission> result = std::make_shared<TransmissionType>(cachedTransmission.getCachedObject(tpl));
        reset();
        return result;
    }

    template<typename TransmissionType>
    void TransmissionBuilder<TransmissionType>::reset()
    {
        cachedGears = 0;
    }

    template<typename TransmissionType>
    TransmissionBuilder<TransmissionType>& TransmissionBuilder<TransmissionType>::setGears(size_t gears)
    {
        cachedGears = gears;
        return *this;
    }
}