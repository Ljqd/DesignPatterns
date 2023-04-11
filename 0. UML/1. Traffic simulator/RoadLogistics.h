#pragma once

#include <memory>

#include "Logistics.h"
#include "Truck.h"

class RoadLogistics : public Logistics
{
protected:
    std::unique_ptr<Transport> getTransport() override {
        return std::make_unique<Truck>();
    }
};