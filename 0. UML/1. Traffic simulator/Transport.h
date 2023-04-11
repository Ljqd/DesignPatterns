#pragma once

class Transport
{
public:
    virtual void setCostPerTone(float newCost) {
        costPerTone = newCost;
    }
    virtual float computeDeliveryCost(float distance, float cargo) {
        return distance * cargo * costPerTone;
    }

protected:
    float costPerTone;
};