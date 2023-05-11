#include "MediumState.h"

#include "Fan.h"
#include "HighState.h"
#include "LowState.h"

MediumState::MediumState(Fan* fan) : fan(fan)
{}

void MediumState::turnUp()
{
    std::cout << "Fan is on high" << std::endl;
    fan->setState(new HighState(fan));
}

void MediumState::turnDown()
{
    std::cout << "Fan is on low" << std::endl;
    fan->setState(new LowState(fan));
}