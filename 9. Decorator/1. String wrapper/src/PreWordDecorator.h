#pragma once

#include "BaseStringDecorator.h"

class PreWordDecorator : public BaseStringDecorator
{
public:
    PreWordDecorator() : wrapper(nullptr) {};
    PreWordDecorator(BasePrintableString* strObject) {
        wrapper = strObject;
    }

    void print() override {
        // setWord() is not a part of neither BaseStringDecorator or BasePrintableString
        std::cout << "Hello";
        wrapper->print();
    }

protected:
    BasePrintableString* wrapper;
};