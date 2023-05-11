#pragma once

#include <iostream>
#include "Snapshot.h"

class Triangle
{
public:
    Triangle(int a, int b, int c) {
        if (isExist(a, b, c)) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        else {
            this->a = 0; 
            this->b = 0; 
            this->c = 0;
        }
    }

    float getArea() const {
        float s = (a + b + c) / 2.0;
        
        return sqrt(s * (a - s) * (b - s) * (c - s));
    }
    int getPerimeter() const {
        return a + b + c;
    }

    void doubleSides() {
        a *= 2; b *= 2; c *= 2;
    }
    void reduceSides() {
        a /= 2; b /= 2; c /= 2;
    }

    void setA(int newA) { a = isExist(newA, b, c) ? newA : a; }
    void setB(int newB) { b = isExist(a, newB, c) ? newB : b; }
    void setC(int newC) { c = isExist(a, b, newC) ? newC : c; }

    void update(int a, int b, int c) {
        if (!isExist(a, b, c))
            return;

        this->a = a;
        this->b = b;
        this->c = c;
    }

    void info() {
        std::cout << "Triangle #" << this << " " << a << " " << b << " " << c << std::endl;
    }

    Snapshot getSnapshot() {
        return Snapshot(this, a, b, c);
    }

    void restore(Snapshot& snapshot) {
        snapshot.restore();
    }

protected:
    bool isExist(int a, int b, int c) const {
        return (a + b >= c) && (b + c >= a) && (a + c >= b);
    }

private:
    int a, b, c;
};