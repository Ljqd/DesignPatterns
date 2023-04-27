#pragma once

#include <iostream>
#include <string>
#include <fstream>

class FileHandler
{
public:
    virtual void setNext(FileHandler* nextHandler) = 0;
    virtual std::fstream open(const std::string& path) = 0;
};