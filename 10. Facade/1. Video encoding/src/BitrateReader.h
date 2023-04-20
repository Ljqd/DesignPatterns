#pragma once

#include <iostream>
#include <string>

#include "Buffer.h"
#include "VideoFile.h"
#include "Codec.h"

class BitrateReader
{
public:
    static Buffer read(VideoFile* file, Codec* codec) {
        std::cout << "Codec of file:  " + codec->type() << std::endl;
        std::cout << "BitrateReader: reading file..." << std::endl;
        std::cout << "BitrateReader: decode video..." << std::endl;

        return file->getVidelBuffer(codec);
    }

    static VideoFile* convert(const Buffer& buffer, std::string name, Codec* codec) {
        std::cout << "Conversion file to format " + codec->type() << std::endl;
        std::cout << "BitrateReader: encode video..." << std::endl;
        std::cout << "BitrateReader: writing file..." << std::endl;
        
        std::string newName = name + "." + codec->type();
        return new VideoFile(newName, buffer);
    }
};