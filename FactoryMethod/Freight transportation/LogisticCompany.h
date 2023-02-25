#pragma once

#include "Logistics.h"
#include "RoadLogistics.h"
#include "SeaLogistics.h"
#include "AirLogistics.h"


class LogisticCompany
{
    // this class has only one method - run, which just builds some logistic,
    // but generally, it also can have some Workers and Supplies or any other
    // information. So logistic is only one block;
public:
    enum DeliveryType
    {
        ROAD, SEA, AIR
    };

    void run(DeliveryType deliveryType)
    {
        Logistics* logistic = nullptr;

        switch (deliveryType)
        {
        case LogisticCompany::ROAD:
            logistic = new RoadLogistics();
            break;
        case LogisticCompany::SEA:
            logistic = new SeaLogistics();
            break;
        case LogisticCompany::AIR:
            logistic = new AirLogistics();
            break;
        default:
            break;
        }

        logistic->setDeliveryTariff(25); // 25$ for 1 tonn of cargo per 1 km
        logistic->planDelivery(1000, 320);
    }
};