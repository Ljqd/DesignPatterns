#pragma once

#include <string>
#include <memory>

#include "Request.h"

class Handler
{
public:
    virtual bool handle(const Request& request) = 0;
    virtual void setNext(const Handler& handler) = 0;
    virtual void setNext(std::shared_ptr<Handler> handler) = 0;
};