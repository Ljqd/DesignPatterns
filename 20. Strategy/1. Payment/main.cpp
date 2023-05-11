// 1. Payment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "src/PaymentContext.h"
#include "src/BankAccoungStrategy.h"
#include "src/PayPalStrategy.h"
#include "src/GooglePayStrategy.h"

int main() {
    PaymentContext context;

    context.setPaymentStrategy(new BankAccountStrategy());
    context.pay(100);

    context.setPaymentStrategy(new PayPalStrategy());
    context.pay(200);

    context.setPaymentStrategy(new GooglePayStrategy());
    context.pay(300);

    return 0;
}









