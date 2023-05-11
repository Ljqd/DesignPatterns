#pragma once

#include <iostream>
#include "PaymentStrategy.h"

class GooglePayStrategy : public PaymentStrategy 
{
public:
    void pay(int amount) override {
        std::cout << "Paying " << amount << " using Google Pay.\n";
    }
};