#pragma once

#include <iostream>

#include "PublicSnapshot.h"
#include "SecureSnapshot.h"

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


    class NestedSnapshot;
    NestedSnapshot getNestedSnapshot() {
        return NestedSnapshot(this);
    }

    PublicSnapshot getPublicSnapshot() {
        return PublicSnapshot(this, a, b, c);
    }

    SecureSnapshot getSecureSnapshot() {
        return SecureSnapshot(this, a, b, c);
    }


    void restore(NestedSnapshot& snapshot) {
        a = snapshot.getA();
        b = snapshot.getB();
        c = snapshot.getC();
    }

    void restore(PublicSnapshot& snapshot) {
        a = snapshot.a;
        b = snapshot.b;
        c = snapshot.c;
    }

    void restore(SecureSnapshot& snapshot) {
        snapshot.restore();
    }

    // <======================================================================>
    // nested class and memento functions
    class NestedSnapshot
    {
    public:
        NestedSnapshot(Triangle* originator)
            : originator(originator)
        {
            this->a = originator->a;
            this->b = originator->b;
            this->c = originator->c;
        }

        int getA() const { return a; }
        int getB() const { return b; }
        int getC() const { return c; }

    private:
        Triangle* originator;
        int a, b, c;
    };
    // <======================================================================>

protected:
    bool isExist(int a, int b, int c) const {
        return (a + b >= c) && (b + c >= a) && (a + c >= b);
    }

private:
    int a, b, c;
};