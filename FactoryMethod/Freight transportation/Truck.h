#pragma once

#include <iostream>
#include <stdexcept>
#include "Transport.h"


class Truck: public Transport
{
public:
    explicit Truck(float costTonnPerKm) : Transport(costTonnPerKm) {};

    float deliveryCost(int distance, int cargo);
};