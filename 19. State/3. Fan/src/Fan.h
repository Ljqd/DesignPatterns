#pragma once

#include "FanState.h"

class Fan {
public:
    Fan() : state(nullptr) {}

    void setState(FanState* newState) {
        this->state = newState;
    }

    void turnUp() {
        if (state) state->turnUp();
    }

    void turnDown() {
        if (state) state->turnDown();
    }
private:
    FanState* state;
};