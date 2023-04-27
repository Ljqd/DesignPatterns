#pragma once

#include <string>
#include <memory>

#include "Handler.h"

class Database;

class AbstractHandler : public Handler
{
public:
    AbstractHandler(Database* database);

    virtual bool handle(const Request& request) override;
    virtual void setNext(std::shared_ptr<Handler> handler) override;

protected:
    Database* database;
    std::shared_ptr<Handler> nextHandler;
};