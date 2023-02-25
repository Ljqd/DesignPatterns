#include "Plane.h"


float Plane::deliveryCost(int distance, int cargo)
{
    std::cout << "Hi, I'm a very specific plane!" << std::endl;
    return distance * cargo * costTonnPerKm;
}