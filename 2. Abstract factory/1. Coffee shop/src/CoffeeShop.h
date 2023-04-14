#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "CoffeeMachine.h"
#include "CoffeeMachineKeurig.h"
#include "CoffeeMachineMelitta.h"
#include "CoffeeMachineNestle.h"


class CoffeeShop
{
public:
    void start()
    {
        std::cout << "CoffeeMachineKeurig.";
        process_machine<CoffeeMachineKeurig>(1, 1);
        std::cout << "CoffeeMachineMelitta.";
        process_machine<CoffeeMachineMelitta>(2, 2);
        std::cout << "CoffeeMachineNestle.";
        process_machine<CoffeeMachineNestle>(3, 3);
    }

private:
    template<typename machineType>
    void process_machine(float a, float b);
};

template<typename machineType>
void CoffeeShop::process_machine(float a, float b)
{
    float baseComponentsCost = 10;
    float basePrice = 15;

    std::pair<float, float> americanoCost = { basePrice, baseComponentsCost };
    std::pair<float, float> cappuccinoCost = { a * basePrice, b * baseComponentsCost };
    std::pair<float, float> espressoCost = { 2 * a * basePrice, 2 * b * baseComponentsCost };
    std::pair<float, float> latteCost = { 3 * a * basePrice, 3 * b * baseComponentsCost };

    std::unique_ptr<CoffeeMachine> machine = std::make_unique<machineType>(americanoCost, cappuccinoCost, espressoCost, latteCost);

    std::unique_ptr<Coffee> americano = machine->getAmericano();
    std::unique_ptr<Coffee> cappuccino = machine->getCappuccino();
    std::unique_ptr<Coffee> espresso = machine->getEspresso();
    std::unique_ptr<Coffee> latte = machine->getLatte();

    float t1 = americano->getPrice() - americano->getComponentsCost();
    float t2 = cappuccino->getPrice() - cappuccino->getComponentsCost();
    float t3 = espresso->getPrice() - espresso->getComponentsCost();
    float t4 = latte->getPrice() - latte->getComponentsCost();
    float totalPrice = t1 + t2 + t3 + t4;
    std::cout << "\tTotal profit (americano + cappuccino + espresso + latte): " << totalPrice << std::endl;
}