#pragma once

#include <memory>
#include "Command.h"

class Controller 
{
public:
    void setCommand(std::unique_ptr<Command> command) {
        command_ = std::move(command);
    }

    void pressButton() {
        if (command_) {
            command_->execute();
        }
    }

private:
    std::unique_ptr<Command> command_;
};