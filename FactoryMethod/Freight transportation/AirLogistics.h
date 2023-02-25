#pragma once

#include "Logistics.h"
#include "Truck.h"


class AirLogistics : public Logistics
{
public:
    void planDelivery(int distance, int cargo);
};