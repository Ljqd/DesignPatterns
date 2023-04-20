#pragma once

#include <string>

class Codec
{
public:
    virtual std::string type() const = 0;
};