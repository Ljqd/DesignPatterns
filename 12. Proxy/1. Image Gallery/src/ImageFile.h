#pragma once

#include <Windows.h>
#include <gdiplus.h>
#include <iostream>

#include "DisplayObject.h"

class ImageFile : public DisplayObject
{
public:
    ImageFile();
    void display() override;
    void load(const std::wstring& imagePath);

    virtual void setHDC(HDC hdc);
    virtual void setMEMDC(HDC memDC);

    std::wstring getImagePath() const;

protected:
    std::wstring imagePath;

    BITMAP currentBitmap;
    HBITMAP oldBitmap;
    HBITMAP hBitmap;

    // just pointers
    HDC hdc;
    HDC memDC;
};