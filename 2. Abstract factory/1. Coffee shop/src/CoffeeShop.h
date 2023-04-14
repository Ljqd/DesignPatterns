#pragma once

#include <iostream>
#include <memory>

#include "CoffeeCreator.h"
#include "AmericanoCreator.h"
#include "CappuccinoCreator.h"
#include "EspressoCreator.h"
#include "LatteCreator.h"


class CoffeeShop
{
public:
    void start()
    {
        float baseComponentsCost = 10;
        float basePrice = 15;

        std::unique_ptr<CoffeeCreator> americanoCreator = std::make_unique<AmericanoCreator>(baseComponentsCost, basePrice);
        std::unique_ptr<CoffeeCreator> cappuccinoCreator = std::make_unique<CappuccinoCreator>(baseComponentsCost + 3, basePrice + 3);
        std::unique_ptr<CoffeeCreator> espressoCreator = std::make_unique<EspressoCreator>(baseComponentsCost + 7, basePrice + 7);
        std::unique_ptr<CoffeeCreator> latteCreator = std::make_unique<LatteCreator>(baseComponentsCost + 11, basePrice + 11);

        std::unique_ptr<Coffee> americano = americanoCreator->getCoffee();
        std::unique_ptr<Coffee> cappuccino = cappuccinoCreator->getCoffee();
        std::unique_ptr<Coffee> espresso = espressoCreator->getCoffee();
        std::unique_ptr<Coffee> latte = latteCreator->getCoffee();

        std::cout << americano->getName() << '\n';
        std::cout << cappuccino->getName() << '\n';
        std::cout << espresso->getName() << '\n';
        std::cout << latte->getName() << '\n';

        float totalPrice = americano->getPrice() + cappuccino->getPrice() + espresso->getPrice() + latte->getPrice();
        std::cout << "Total profit (americano + cappuccino + espresso + latte): " << totalPrice << std::endl;
    }
};