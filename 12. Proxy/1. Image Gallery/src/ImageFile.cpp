#include "ImageFile.h"

using namespace Gdiplus;

ImageFile::ImageFile() {
    imagePath = L"";

    currentBitmap = {};
    oldBitmap = {};
    hBitmap = {};

    hdc = nullptr;
    memDC = nullptr;
}

void ImageFile::display()
{
    // we can't move it to load, since hdc/memDC is unique
    oldBitmap = (HBITMAP)SelectObject(memDC, hBitmap);
    GetObject(hBitmap, sizeof(BITMAP), &currentBitmap);

    BitBlt(hdc, 0, 0, currentBitmap.bmWidth, currentBitmap.bmHeight, memDC, 0, 0, SRCCOPY);
    SelectObject(memDC, oldBitmap);
    DeleteObject(hBitmap);
}


void ImageFile::load(const std::wstring& imagePath)
{
    std::cout << "Loading " << imagePath.c_str() << '\n';
    this->imagePath = imagePath;

    Bitmap temp(imagePath.c_str());
    temp.GetHBITMAP(0, &hBitmap);
}

std::wstring ImageFile::getImagePath() const
{
    return imagePath;
}

void ImageFile::setHDC(HDC hdc)
{
    this->hdc = hdc;
}

void ImageFile::setMEMDC(HDC memDC)
{
    this->memDC = memDC;
}