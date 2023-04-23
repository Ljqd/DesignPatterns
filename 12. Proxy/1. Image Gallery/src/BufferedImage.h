#pragma once

#include <Windows.h>
#include <gdiplus.h>

#include "ImageFile.h"

class BufferedImage : public ImageFile
{
public:
    BufferedImage(ImageFile* imageFile);

    void display() override;
    void load(const std::wstring& imagePath);
protected:
    ImageFile* imageFile;
    std::wstring imagePath;
};

