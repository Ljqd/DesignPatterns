#pragma once

#include <iostream>
#include <stdexcept>


class Transport
{
protected:
    float costTonnPerKm;

public:
    Transport() = delete;
    explicit Transport(float costTonnPerKm);

    void updateCostPerKm(float newCost);

    virtual float deliveryCost(int distance, int cargo) = 0;
};