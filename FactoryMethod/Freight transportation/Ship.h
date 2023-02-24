#pragma once

#include <iostream>
#include <stdexcept>
#include "Transport.h"


class Ship: public Transport
{
public:
    explicit Ship(float costTonnPerKm) : Transport(costTonnPerKm) {};

    float deliveryCost(int distance, int cargo);
};