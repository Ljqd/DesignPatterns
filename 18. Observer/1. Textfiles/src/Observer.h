#pragma once

#include <string>

class Observer {
public:
    virtual void update(const std::string& line) = 0;
};