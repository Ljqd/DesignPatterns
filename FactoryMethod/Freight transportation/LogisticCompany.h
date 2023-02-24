#pragma once

#include "Logistics.h"


class LogisticCompany
{
    // this class has only one method - run, which just builds some logistic,
    // but generally, it also can have some Workers and Supplies or any other
    // information. So logistic is only one block;
public:
    void run()
    {
        Logistics* logistic = new Logistics();
        logistic->setDeliveryTariff(0.5f); // 0.5$ for 1 tonn of cargo per 1 km
        logistic->planDelivery(Logistics::ROAD, 500, 20);

        logistic->setDeliveryTariff(10.5f); // 10.5$ for 1 tonn of cargo per 1 km
        logistic->planDelivery(Logistics::AIR, 1500, 120);

        logistic->setDeliveryTariff(50.5f); // 50.5$ for 1 tonn of cargo per 1 km
        logistic->planDelivery(Logistics::SEA, 2500, 320);
    }
};