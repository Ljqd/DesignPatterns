#pragma once

#include "AbstractHandler.h"

class PasswordHandler : public AbstractHandler
{
public:
    PasswordHandler(Database* database);
    bool handle(const Request& request) override;
};