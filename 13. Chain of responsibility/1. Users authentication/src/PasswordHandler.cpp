#include "PasswordHandler.h"

#include "Database.h"

PasswordHandler::PasswordHandler(Database* database)
    : AbstractHandler(database) {};

bool PasswordHandler::handle(const Request& request) 
{
    if (this->database->isPasswordValid(request.login, request.password))
        return true;
    return false;
}