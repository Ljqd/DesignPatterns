#include <iostream>
#include <memory>
#include <vector>

#include "src/TrafficSimulator.h"

int main()
{
    std::unique_ptr<TrafficSimulator> simulator = std::unique_ptr<TrafficSimulator>();
    std::vector<float> costs = simulator->simulate();
    std::cout << "I'm a traffic simulator!\tSo, the total cost 1 is: " << costs[0] << std::endl;
    std::cout << "I'm a traffic simulator!\tSo, the total cost 2 is: " << costs[1] << std::endl;
    std::cout << "I'm a traffic simulator!\tSo, the total cost 3 is: " << costs[2] << std::endl;
}