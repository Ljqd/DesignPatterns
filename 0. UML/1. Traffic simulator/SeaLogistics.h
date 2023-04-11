#pragma once

#include <memory>

#include "Logistics.h"
#include "Ship.h"

class SeaLogistics : public Logistics
{
protected:
    std::unique_ptr<Transport> getTransport() override {
        return std::make_unique<Ship>();
    }
};