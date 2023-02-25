#pragma once

#include <iostream>
#include <stdexcept>


class Logistics
{
protected:
    float deliveryTariff;

public:
    Logistics();
    Logistics(float deliveryTariff);

    void setDeliveryTariff(float deliveryTariff);
    
    virtual void planDelivery(int distance, int cargo) = 0;
};