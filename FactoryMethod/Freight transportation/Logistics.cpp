#include "Logistics.h"


Logistics::Logistics() : deliveryTariff{0}
{}

Logistics::Logistics(float deliveryTariff) : deliveryTariff{ deliveryTariff }
{}

void Logistics::setDeliveryTariff(float deliveryTariff)
{
    if (deliveryTariff <= 0)
        throw std::invalid_argument("received cost less or equal 0");
    this->deliveryTariff = deliveryTariff;
}