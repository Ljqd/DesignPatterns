#pragma once

class Device
{
public:
    virtual ~Device() = default;
    virtual void turnOff() = 0;
};