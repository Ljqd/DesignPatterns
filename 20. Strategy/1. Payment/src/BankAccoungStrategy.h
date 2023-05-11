#pragma once

#include <iostream>
#include "PaymentStrategy.h"

class BankAccountStrategy : public PaymentStrategy 
{
public:
    void pay(int amount) override {
        std::cout << "Paying " << amount << " using Bank Account.\n";
    }
};