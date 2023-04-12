#pragma once

#include <memory>

#include "Logistics.h"
#include "Plane.h"

class AirLogistics : public Logistics
{
protected:
    std::unique_ptr<Transport> getTransport() override {
        return std::make_unique<Plane>();
    }
};