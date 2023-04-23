#include "BufferedImage.h"

using namespace Gdiplus;

BufferedImage::BufferedImage(ImageFile* imageFile)
{
    this->imageFile = imageFile;
}

void BufferedImage::display()
{
    // ImageFile doesn't get a path through set function
    // it gets a path and load Bitmaps at the same time
    //
    // So, if images is different or imageFile->path is not specified - load
    if (imageFile->getImagePath() != imagePath)
        imageFile->load(imagePath);

    // expected that setHDC and setMEMDC are called already
    imageFile->display();
}


void BufferedImage::load(const std::wstring& imagePath)
{
    this->imagePath = imagePath;
}