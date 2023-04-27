#include "AbstractHandler.h"

#include "Database.h"

AbstractHandler::AbstractHandler(Database* database) :
    database(database), nextHandler(nullptr) {}

bool AbstractHandler::handle(const Request& request)
{
    if (nextHandler != nullptr)
        return nextHandler->handle(request);
    return false;
}

void AbstractHandler::setNext(std::shared_ptr<Handler> handler)
{
    nextHandler = handler;
}