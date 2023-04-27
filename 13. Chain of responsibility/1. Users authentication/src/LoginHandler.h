#pragma once

#include "AbstractHandler.h"

class LoginHandler : public AbstractHandler
{
public:
    LoginHandler(Database* database)
        : AbstractHandler(database) {};

    bool handle(const Request& request) override {
        if (this->database->hasLogin(request.login))
            return this->nextHandler->handle(request);
        return false;
    }
};