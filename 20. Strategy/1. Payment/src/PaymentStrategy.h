#pragma once

class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
};