#include "ImageGallery.h"

using namespace Gdiplus;

ImageGallery::ImageGallery()
{
    inited = false;
    imageId = 0;
}

bool ImageGallery::is() const
{
    return inited;
}

void ImageGallery::init(const std::vector<std::string>& files)
{
    this->files = files;
}

void ImageGallery::drawNext(HDC hdc, HDC memDC)
{
    imageId = imageId % files.size();

    if (imageId >= images.size())
    {
        ImageFile imageFile = {};
        BufferedImage bufferedImage = { &imageFile };
        images.push_back(bufferedImage);
    }
    
    std::wstring wfile(files[imageId].begin(), files[imageId].end());
    ImageFile* image = &images[imageId];    
    image->load(wfile);
    image->setHDC(hdc);
    image->setMEMDC(memDC);
    image->display();

    imageId += 1;
}

ImageFile* ImageGallery::getCurrent()
{
    imageId = imageId % images.size();
    return &images.at(imageId);
}