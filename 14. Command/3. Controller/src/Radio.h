#pragma once

#include <iostream>
#include "Device.h"

class Radio : public Device
{
public:
    void turnOff() override {
        std::cout << "Radio turned off" << std::endl;
    }
};