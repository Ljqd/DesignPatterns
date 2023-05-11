#pragma once

#include <iostream>

#include "FanState.h"

class Fan;

class MediumState : public FanState {
public:
    MediumState(Fan* fan);

    void turnUp() override;
    void turnDown() override;
protected:
    Fan* fan;
};