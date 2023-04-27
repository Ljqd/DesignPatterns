#pragma once

#include "AbstractFileHandler.h"

class ExcelHandler : public AbstractFileHandler
{
public:
    virtual std::fstream open(const std::string& path) override {
        std::cout << "ExceltHandler... ";
        std::string extension = ".excel";

        if (this->isExtension(path, extension))
        {
            std::cout << "Success!" << '\n';
            return std::fstream(path);
        }

        std::cout << "Failed." << '\n';

        if (this->nextHandler != nullptr)
        {
            return this->nextHandler->open(path);
        }

        return {};
    }
};