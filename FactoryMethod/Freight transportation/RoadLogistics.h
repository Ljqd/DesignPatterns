#pragma once

#include "Logistics.h"
#include "Truck.h"


class RoadLogistics : public Logistics
{
public:
    void planDelivery(int distance, int cargo);
};