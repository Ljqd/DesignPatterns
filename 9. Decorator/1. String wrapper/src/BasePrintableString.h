#pragma once

#include <iostream>
#include <string>

class BasePrintableString
{
public:
    BasePrintableString() = default;
    BasePrintableString(std::string str) : container(str) {};

    virtual void print() {
        std::cout << container;
    }

protected:
    std::string container;
};