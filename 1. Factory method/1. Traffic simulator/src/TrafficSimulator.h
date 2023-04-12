#pragma once

#include <memory>

#include "Logistics.h"
#include "RoadLogistics.h"
#include "SeaLogistics.h"
#include "AirLogistics.h"

class TrafficSimulator
{
public:
    float simulate() {
        std::unique_ptr<Logistics> logistic = std::make_unique<RoadLogistics>();
        float cost = logistic->planDelivery(2.0f, 500, 20);

        return cost;
    }
};