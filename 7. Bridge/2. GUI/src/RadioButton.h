#pragma once

#include "Button.h"

class RadioButton : public Button
{
public:
    void draw(Canvas* canvasPtr) const override {
        std::cout << "Draw RadioButton\n";
        std::cout << "\tSize:" << buttonSize->getString();
        std::cout << std::endl;
    }
};