#pragma once

#include "Button.h"

class DropdownButton : public Button
{
public:
    void draw(Canvas* canvasPtr) const override {
        std::cout << "Draw DropdownButton\n";
        std::cout << "\tSize:" << buttonSize->getString();
        std::cout << std::endl;
    }
};