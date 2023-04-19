#pragma once

#include "ButtonSize.h"

class SmallButtonSize : public ButtonSize
{
public:
    std::string getString() const override {
        return "SmallButtonSize";
    }
};