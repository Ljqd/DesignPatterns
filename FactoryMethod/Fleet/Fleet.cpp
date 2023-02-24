#include "Fleet.h"


void Fleet::addNewCar(Factories factoryId)
{
    Mercedes* newMercedes = nullptr;
    if (factoryId == FactoryBerlin) newMercedes = getFromBerlin(FactoryBerlin);
    if (factoryId == FactoryHamburg) newMercedes = getFromHamburg(FactoryHamburg);
    if (factoryId == FactoryMunich) newMercedes = getFromMunich(FactoryMunich);
    cars.push_back(newMercedes);
}

void Fleet::popLastCar()
{
    return cars.pop_back();
}

size_t Fleet::numberOfCars() const
{
    return cars.size();
}

Mercedes* Fleet::operator[](int i)
{
    return cars[i];
}

const Mercedes* Fleet::operator[](int i) const
{
    return cars[i];
}

Mercedes* Fleet::getFromBerlin(Factories factoryId)
{
    return new Mercedes{ factoryId, "Berlin" };
}

Mercedes* Fleet::getFromHamburg(Factories factoryId)
{
    return new Mercedes{ factoryId, "Hamburg" };
}

Mercedes* Fleet::getFromMunich(Factories factoryId)
{
    return new Mercedes{ factoryId, "Munich" };
}