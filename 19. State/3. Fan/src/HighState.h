#pragma once

#include <iostream>

#include "FanState.h"

class Fan;

class HighState : public FanState {
public:
    HighState(Fan* fan);

    void turnUp() override;
    void turnDown() override;
protected:
    Fan* fan;
};