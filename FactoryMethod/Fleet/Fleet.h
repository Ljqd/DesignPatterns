#pragma once

#include <iostream>
#include <vector>
#include "Mercedes.h"


class Fleet
{
private:
    std::vector<Mercedes*> cars;

public:
    enum Factories
    {
        FactoryBerlin,
        FactoryHamburg,
        FactoryMunich
    };

    void addNewCar(Factories factoryId);
    void popLastCar();

    size_t numberOfCars() const;

    Mercedes* operator[](int i);
    const Mercedes* operator[](int i) const;

private:
    Mercedes* getFromBerlin(Factories factoryId);
    Mercedes* getFromHamburg(Factories factoryId);
    Mercedes* getFromMunich(Factories factoryId);
};