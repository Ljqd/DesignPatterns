#pragma once

#include "BaseStringDecorator.h"

class PostEndlDecorator : public BaseStringDecorator
{
public:
    PostEndlDecorator() : wrapper(nullptr) {};
    PostEndlDecorator(BasePrintableString* strObject) {
        wrapper = strObject;
    }

    void print() override {
        wrapper->print();
        std::cout << "\n";
    }

protected:
    BasePrintableString* wrapper;
};