#pragma once

#include <iostream>

#include "FanState.h"

class Fan;

class LowState : public FanState {
public:
    LowState(Fan* fan);
    void turnUp() override;
    void turnDown() override;
protected:
    Fan* fan;
};