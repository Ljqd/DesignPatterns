#pragma once

#include <string>
#include <vector>

#include <Windows.h>
#include <gdiplus.h>

#include "ImageFile.h"
#include "BufferedImage.h"

class ImageGallery
{
public:
    ImageGallery();

    bool is() const;
    void init(const std::vector<std::string>& files);

    void drawNext(HDC hdc, HDC memDC);

    ImageFile* getCurrent();

protected:
    std::vector<std::string> files;
    std::vector<BufferedImage> images;
    size_t imageId;

    bool inited;
};