#pragma once

#include <iostream>

#include "VideoFile.h"
#include "Buffer.h"

class AudioMixer
{
public:
    void fix(VideoFile* videoFile, Buffer audioBuffer) {
        std::cout << "AudioMixer: fixing audio..." << std::endl;
        videoFile->setAudioBuffer(audioBuffer);
    }
};