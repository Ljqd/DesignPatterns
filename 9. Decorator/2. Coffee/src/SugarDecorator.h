#pragma once

#include "BaseBeverageDecorator.h"

class SugarDecorator : public BaseBeverageDecorator
{
public:
    SugarDecorator(Beverage* beverage) : wrapper(beverage) {};

    std::string description() const override {
        std::string temp = wrapper->description();
        int index = temp.find(" with sugar");

        // assume that we don't call more then twice
        if (index != -1) {
            temp.replace(index, index + 11, " with sugar x2");
            return temp;
        }
        return temp + " with sugar";
    }

    float cost() const override {
        return wrapper->cost();
    }

protected:
    Beverage* wrapper;
};