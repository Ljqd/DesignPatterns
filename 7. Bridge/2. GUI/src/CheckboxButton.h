#pragma once

#include "Button.h"

class CheckboxButton : public Button
{
public:
    void draw(Canvas* canvasPtr) const override {
        std::cout << "Draw CheckboxButton\n";
        std::cout << "\tSize:" << buttonSize->getString();
        std::cout << std::endl;
    }
};