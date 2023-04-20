#pragma once

#include "BaseStringDecorator.h"

class PostSpaceDecorator : public BaseStringDecorator
{
public:
    PostSpaceDecorator() : wrapper(nullptr) {};
    PostSpaceDecorator(BasePrintableString* strObject) {
        wrapper = strObject;
    }

    void print() override {
        wrapper->print();
        std::cout << " ";
    }

protected:
    BasePrintableString* wrapper;
};