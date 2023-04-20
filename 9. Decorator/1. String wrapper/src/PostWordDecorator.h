#pragma once

#include "BaseStringDecorator.h"

class PostWordDecorator : public BaseStringDecorator
{
public:
    PostWordDecorator() : wrapper(nullptr) {};
    PostWordDecorator(BasePrintableString* strObject) {
        wrapper = strObject;
    }

    void print() override {
        // setWord() is not a part of neither BaseStringDecorator or BasePrintableString
        wrapper->print();
        std::cout << "world";
    }

protected:
    BasePrintableString* wrapper;
};