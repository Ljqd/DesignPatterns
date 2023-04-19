#pragma once

#include <iostream>

#include "ButtonSize.h"

class Canvas; // hint with forward declaration
// otherwise, Canvas.h requires Button.h since the class has such field
// and Button requires Canvas-ptr (we need to know where to draw)

class Button
{
public:
    virtual void draw(Canvas* canvasPtr) const = 0;

    void setSize(ButtonSize* size) {
        buttonSize = size;
    }

protected:
    ButtonSize* buttonSize;
};