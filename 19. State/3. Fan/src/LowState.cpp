#include "LowState.h"

#include "Fan.h"
#include "MediumState.h"

LowState::LowState(Fan* fan) : fan(fan)
{}

void LowState::turnUp()
{
    std::cout << "Fan is on medium" << std::endl;
    fan->setState(new MediumState(fan));
}

void LowState::turnDown()
{
    std::cout << "Fan is alredy on low" << std::endl;
}