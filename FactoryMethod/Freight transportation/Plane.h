#pragma once

#include <iostream>
#include <stdexcept>
#include "Transport.h"


class Plane: public Transport
{
public:
    explicit Plane(float costTonnPerKm) : Transport(costTonnPerKm) {};

    float deliveryCost(int distance, int cargo);
};