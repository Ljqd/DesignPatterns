#pragma once

class FanState {
public:
    virtual void turnUp() = 0;
    virtual void turnDown() = 0;
    virtual ~FanState() {}
};