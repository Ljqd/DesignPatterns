#pragma once

#include <memory>
#include "Command.h"

class Controller
{
public:
    void setCommand(std::unique_ptr<Command> command) {
        this->command = std::move(command);
    }

    void onClick() {
        if (command) {
            command->execute();
        }
    }

private:
    std::unique_ptr<Command> command;
};