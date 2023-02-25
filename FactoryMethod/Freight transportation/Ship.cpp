#include "Ship.h"


float Ship::deliveryCost(int distance, int cargo)
{
    std::cout << "Hi, I'm a very specific ship!" << std::endl;
    return distance * cargo * costTonnPerKm;
}