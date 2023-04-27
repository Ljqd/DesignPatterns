#pragma once

#include "FileHandler.h"

class AbstractFileHandler : public FileHandler
{
public:
    AbstractFileHandler() : nextHandler(nullptr) {}

    virtual void setNext(FileHandler* nextHandler) override {
        this->nextHandler = nextHandler;
    }
    virtual std::fstream open(const std::string& path) override {
        if (nextHandler != nullptr)
            return nextHandler->open(path);
        return {};
    }

protected:
    virtual bool isExtension(const std::string& path, const std::string& extension) {
        return path.compare(path.size() - extension.size(), extension.size(), extension) == 0;
    }

    FileHandler* nextHandler;
};