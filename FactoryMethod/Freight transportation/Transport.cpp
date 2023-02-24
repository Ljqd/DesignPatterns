#include "Transport.h"


Transport::Transport(float costTonnPerKm) : costTonnPerKm{ costTonnPerKm }
{}

void Transport::updateCostPerKm(float newCost)
{
    if (newCost <= 0)
        throw std::invalid_argument("received cost less or equal 0");
    costTonnPerKm = newCost;
}