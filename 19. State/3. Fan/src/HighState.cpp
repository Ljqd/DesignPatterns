#include "HighState.h"

#include "Fan.h"
#include "MediumState.h"

HighState::HighState(Fan* fan) : fan(fan)
{}

void HighState::turnUp()
{
    std::cout << "Fan is alredy on high" << std::endl;
}

void HighState::turnDown()
{
    std::cout << "Fan is on medium" << std::endl;
    fan->setState(new MediumState(fan));
}