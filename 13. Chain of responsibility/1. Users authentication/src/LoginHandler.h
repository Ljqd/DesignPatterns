#pragma once

#include "AbstractHandler.h"

class LoginHandler : public AbstractHandler
{
public:
    LoginHandler(Database* database);

    bool handle(const Request& request) override;
};