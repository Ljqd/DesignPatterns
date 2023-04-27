#include "LoginHandler.h"

#include "Database.h"

LoginHandler::LoginHandler(Database* database)
    : AbstractHandler(database) {};

bool LoginHandler::handle(const Request& request) 
{
    if (this->database->hasLogin(request.login))
        return this->nextHandler->handle(request);
    return false;
}