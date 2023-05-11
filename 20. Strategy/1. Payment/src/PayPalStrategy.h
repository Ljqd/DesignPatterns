#pragma once

#include <iostream>
#include "PaymentStrategy.h"

class PayPalStrategy : public PaymentStrategy 
{
public:
    void pay(int amount) override {
        std::cout << "Paying " << amount << " using PayPal.\n";
    }
};