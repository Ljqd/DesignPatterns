#pragma once

#include "AbstractMemento.h"

class Triangle;

class SecureSnapshot : public AbstractMemento
{
public:
    SecureSnapshot(Triangle* obligator, int a, int b, int c);
    virtual void restore() override;

private:
    int a, b, c;
    Triangle* obligator;
};