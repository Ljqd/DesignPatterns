#pragma once

#include <memory>

#include "Transport.h"

class Logistics
{
public:
    virtual float planDelivery(float distance, float cargo, float costPerTone) {
        std::unique_ptr<Transport> transport = getTransport();
        transport->setCostPerTone(costPerTone);
        return transport->computeDeliveryCost(distance, cargo);
    }
protected:
    virtual std::unique_ptr<Transport> getTransport() = 0;
};