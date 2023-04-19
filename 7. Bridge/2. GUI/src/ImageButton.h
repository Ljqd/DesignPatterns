#pragma once

#include "Button.h"

class ImageButton : public Button
{
public:
    void draw(Canvas* canvasPtr) const override {
        std::cout << "Draw Image button\n";
        std::cout << "\tSize:" << buttonSize->getString();
        std::cout << std::endl;
    }
};