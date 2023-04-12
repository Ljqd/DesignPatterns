#include <iostream>

#include <memory>
#include "src/TrafficSimulator.h"

int main()
{
    std::unique_ptr<TrafficSimulator> simulator = std::unique_ptr<TrafficSimulator>();
    float cost = simulator->simulate();
    std::cout << "I'm a traffic simulator!\tSo, the total cost is: " << cost;
}