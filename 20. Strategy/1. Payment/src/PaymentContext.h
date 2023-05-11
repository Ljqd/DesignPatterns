#pragma once

#include <iostream>
#include "PaymentStrategy.h"

class PaymentContext 
{
public:
    void setPaymentStrategy(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    void pay(int amount) {
        if (strategy) {
            strategy->pay(amount);
        }
        else {
            std::cout << "No payment strategy set.\n";
        }
    }
private:
    PaymentStrategy* strategy;
};