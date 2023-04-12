#pragma once

#include <memory>
#include <vector>

#include "Logistics.h"
#include "RoadLogistics.h"
#include "SeaLogistics.h"
#include "AirLogistics.h"

class TrafficSimulator
{
public:
    std::vector<float> simulate() {
        std::vector<float> costs = {};

        std::unique_ptr<Logistics> logistic = std::make_unique<RoadLogistics>();
        float cost = logistic->planDelivery(2.0f, 500, 20);
        costs.push_back(cost);

        logistic = std::make_unique<AirLogistics>();
        cost = logistic->planDelivery(2.0f, 300, 20);
        costs.push_back(cost);

        logistic = std::make_unique<SeaLogistics>();
        cost = logistic->planDelivery(2.0f, 100, 20);
        costs.push_back(cost);

        return costs;
    }
};