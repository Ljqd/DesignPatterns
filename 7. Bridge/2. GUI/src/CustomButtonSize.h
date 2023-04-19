#pragma once

#include "ButtonSize.h"

class CustomButtonSize : public ButtonSize
{
public:
    std::string getString() const override {
        return "CustomButtonSize";
    }

    // formally, we need to set a corresponding constructor
    // and width/height fields with get+set methods
    // but since, this is not a part of ButtonSize - we need
    // to add ExntendedButtonSize class with virtual functions
    // and use dynamic/static cast
};