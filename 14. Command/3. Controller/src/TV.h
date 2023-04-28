#pragma once

#include <iostream>
#include "Device.h"

class TV : public Device
{
public:
    void turnOff() override {
        std::cout << "TV turned off" << std::endl;
    }
};