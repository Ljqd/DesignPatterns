#pragma once

#include <iostream>
#include <memory>

#include "CoffeeMachine.h"
#include "AmericanoMachine.h"
#include "CappuccinoMachine.h"
#include "EspressoMachine.h"
#include "LatteMachine.h"


class CoffeeShop
{
public:
    void start()
    {
        float baseComponentsCost = 10;
        float basePrice = 15;

        std::unique_ptr<CoffeeMachine> americanoMachine = std::make_unique<AmericanoMachine>(baseComponentsCost, basePrice);
        std::unique_ptr<CoffeeMachine> cappuccinoMachine = std::make_unique<CappuccinoMachine>(baseComponentsCost + 3, basePrice + 3);
        std::unique_ptr<CoffeeMachine> espressoMachine = std::make_unique<EspressoMachine>(baseComponentsCost + 7, basePrice + 7);
        std::unique_ptr<CoffeeMachine> latteMachine = std::make_unique<LatteMachine>(baseComponentsCost + 11, basePrice + 11);

        std::unique_ptr<Coffee> americano = americanoMachine->getCoffee();
        std::unique_ptr<Coffee> cappuccino = cappuccinoMachine->getCoffee();
        std::unique_ptr<Coffee> espresso = espressoMachine->getCoffee();
        std::unique_ptr<Coffee> latte = latteMachine->getCoffee();

        std::cout << americano->getName() << '\n';
        std::cout << cappuccino->getName() << '\n';
        std::cout << espresso->getName() << '\n';
        std::cout << latte->getName() << '\n';
    }
};