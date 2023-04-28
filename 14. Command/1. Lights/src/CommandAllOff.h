#pragma once

#include <vector>
#include <memory>

#include "Light.h"
#include "Command.h"

class CommandAllOff : public Command 
{
public:
    explicit CommandAllOff(std::vector<std::shared_ptr<Light>> lights)
        : lights(std::move(lights)) {}

    void execute() override {
        for (const auto& light : lights) {
            light->off();
        }
    }

private:
    std::vector<std::shared_ptr<Light>> lights;
};