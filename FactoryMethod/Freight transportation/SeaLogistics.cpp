#include "SeaLogistics.h"


void SeaLogistics::planDelivery(int distance, int cargo)
{
    Transport* transport = new Truck(deliveryTariff);

    float totalCost = transport->deliveryCost(distance, cargo);
    std::cout << "Delivery cost is " << totalCost << std::endl;
}