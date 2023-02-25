#include "Truck.h"


float Truck::deliveryCost(int distance, int cargo)
{
    std::cout << "Hi, I'm a very specific truck!" << std::endl;
    return distance * cargo * costTonnPerKm;
}