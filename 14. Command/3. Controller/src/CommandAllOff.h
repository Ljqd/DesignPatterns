#pragma once

#include <vector>
#include <memory>
#include "Device.h"
#include "Command.h"

class CommandAllOff : public Command 
{
public:
    explicit CommandAllOff(std::vector<std::shared_ptr<Device>>& devices) : devices(devices) {}

    void execute() override {
        for (const auto& device : devices) {
            device->turnOff();
        }
    }

private:
    std::vector<std::shared_ptr<Device>>& devices;
};