#pragma once

#include "BaseStringDecorator.h"

class PostComaDecorator : public BaseStringDecorator
{
public:
    PostComaDecorator() : wrapper(nullptr) {};
    PostComaDecorator(BasePrintableString* strObject) {
        wrapper = strObject;
    }

    void print() override {
        wrapper->print();
        std::cout << ",";
    }

protected:
    BasePrintableString* wrapper;
};