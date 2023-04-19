#pragma once

#include "ButtonSize.h"

class MediumButtonSize : public ButtonSize
{
public:
    std::string getString() const override {
        return "MediumButtonSize";
    }
};