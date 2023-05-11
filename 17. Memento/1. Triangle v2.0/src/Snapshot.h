#pragma once

class Triangle;

class Snapshot
{
public:
    Snapshot(Triangle* obligator, int a, int b, int c);
    void restore();

    bool isEmpty();

private:
    int a, b, c;
    Triangle* obligator;
};