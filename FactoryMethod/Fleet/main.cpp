#include "Fleet.h"


int main()
{
    Fleet fleet = {};

    fleet.addNewCar(Fleet::FactoryBerlin);
    fleet.addNewCar(Fleet::FactoryHamburg);
    fleet.addNewCar(Fleet::FactoryMunich);
    fleet.addNewCar(Fleet::FactoryHamburg);

    for (int i = 0; i < fleet.numberOfCars(); i++)
    {
        std::cout << "Car #" << i << " from " << fleet[i]->getFactoryTitle() << "\n";
    }
}