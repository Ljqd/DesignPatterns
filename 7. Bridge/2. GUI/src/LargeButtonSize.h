#pragma once

#include "ButtonSize.h"

class LargeButtonSize : public ButtonSize
{
public:
    std::string getString() const override {
        return "LargeButtonSize";
    }
};