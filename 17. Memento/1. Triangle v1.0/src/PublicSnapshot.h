#pragma once

#include "EmptyMemento.h"

class Triangle;

class PublicSnapshot : public EmptyMemento
{
public:
    PublicSnapshot(Triangle* obligator, int a, int b, int c);

    int a, b, c;

private:
    Triangle* obligator;
};