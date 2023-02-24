#pragma once

#include <iostream>
#include <stdexcept>
#include "Truck.h"
#include "Plane.h"
#include "Ship.h"


class Logistics
{
private:
    float deliveryTariff;

public:
    enum DeliveryType
    {
        ROAD, SEA, AIR
    };

    Logistics();
    Logistics(float deliveryTariff);

    void setDeliveryTariff(float deliveryTariff);
    void planDelivery(DeliveryType deliveryType, int distance, int cargo);

private:
    Truck* planTruckDelivery(float deliveryTariff);
    Ship* planSeaDelivery(float deliveryTariff);
    Plane* planAirDelivery(float deliveryTariff);
};