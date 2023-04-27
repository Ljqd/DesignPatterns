#pragma once

#include <string>
#include <memory>

#include "Handler.h"

class Database;

class AbstractHandler : public Handler
{
public:
    AbstractHandler(Database* database) :
        database(database), nextHandler(nullptr) {}

    bool handle(const Request& request) override {
        if (nextHandler != nullptr)
            return nextHandler->handle(request);
        return false;
    }

    void setNext(const Handler& handler) override {
        nextHandler = std::make_shared<AbstractHandler>(handler);
    }

    void setNext(std::shared_ptr<Handler> handler) override {
        nextHandler = handler;
    }

protected:
    Database* database;
    std::shared_ptr<Handler> nextHandler;
};