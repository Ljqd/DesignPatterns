#pragma once

#include "Logistics.h"
#include "Truck.h"


class SeaLogistics : public Logistics
{
public:
    void planDelivery(int distance, int cargo);
};