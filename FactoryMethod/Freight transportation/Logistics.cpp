#include "Logistics.h"


Logistics::Logistics() : deliveryTariff{-1}
{}

Logistics::Logistics(float deliveryTariff) : deliveryTariff{ deliveryTariff }
{}

void Logistics::setDeliveryTariff(float deliveryTariff)
{
    if (deliveryTariff <= 0)
        throw std::invalid_argument("received cost less or equal 0");
    this->deliveryTariff = deliveryTariff;
}

void Logistics::planDelivery(DeliveryType deliveryType, int distance, int cargo)
{
    Transport* transport = nullptr;

    if (deliveryType == DeliveryType::AIR) transport = planAirDelivery(deliveryTariff);
    if (deliveryType == DeliveryType::SEA) transport = planSeaDelivery(deliveryTariff);
    if (deliveryType == DeliveryType::ROAD) transport = planTruckDelivery(deliveryTariff);

    float totalCost = transport->deliveryCost(distance, cargo);
    std::cout << "Delivery cost is " << totalCost << std::endl;
}

Truck* Logistics::planTruckDelivery(float deliveryTariff)
{
    return new Truck(deliveryTariff);
}

Ship* Logistics::planSeaDelivery(float deliveryTariff)
{
    return new Ship(deliveryTariff);
}

Plane* Logistics::planAirDelivery(float deliveryTariff)
{
    return new Plane(deliveryTariff);
}