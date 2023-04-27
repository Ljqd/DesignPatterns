#pragma once

#include "AbstractHandler.h"

class PasswordHandler : public AbstractHandler
{
public:
    PasswordHandler(Database* database)
        : AbstractHandler(database) {};

    bool handle(const Request& request) override {
        if (this->database->isPasswordValid(request.login, request.password))
            return true;
        return false;
    }
};