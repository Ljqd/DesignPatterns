#pragma once

#include "BaseStringDecorator.h"

class PostExclaimDecorator : public BaseStringDecorator
{
public:
    PostExclaimDecorator() : wrapper(nullptr) {};
    PostExclaimDecorator(BasePrintableString* strObject) {
        wrapper = strObject;
    }

    void print() override {
        wrapper->print();
        std::cout << "!";
    }

protected:
    BasePrintableString* wrapper;
};