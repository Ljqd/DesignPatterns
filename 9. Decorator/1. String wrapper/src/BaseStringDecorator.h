#pragma once

#include "BasePrintableString.h"

class BaseStringDecorator : public BasePrintableString
{
public:
    BaseStringDecorator() : wrapper(nullptr) {};
    BaseStringDecorator(BasePrintableString* strObject) {
        wrapper = strObject;
    }

    void print() override {
        wrapper->print();
    }

protected:
    BasePrintableString* wrapper;
};