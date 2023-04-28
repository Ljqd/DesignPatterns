#pragma once

#include <vector>
#include <memory>

#include "Light.h"
#include "Command.h"

class CommandAllOn : public Command 
{
public:
    explicit CommandAllOn(std::vector<std::shared_ptr<Light>> lights) 
        : lights(std::move(lights)) {}

    void execute() override {
        for (const auto& light : lights) {
            light->on();
        }
    }

private:
    std::vector<std::shared_ptr<Light>> lights;
};