#include <iostream>

#include "src/Fan.h"
#include "src/LowState.h"

int main()
{
    Fan fan = {};

    LowState* lowState = new LowState(&fan);
    fan.setState(lowState);

    fan.turnDown();
    fan.turnUp();
    fan.turnUp();
    fan.turnDown();
    fan.turnUp();
    fan.turnUp();
}
