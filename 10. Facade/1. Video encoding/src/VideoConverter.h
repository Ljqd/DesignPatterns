#pragma once

#include <iostream>
#include <string>

#include "VideoFile.h"
#include "MPEG4CompressionCodec.h"
#include "OggCompressionCodec.h"

#include "CodecFactory.h"

#include "BitrateReader.h"

#include "AudioMixer.h"


class VideoConverter
{
public:
    static VideoFile* convert(VideoFile* videoFile, Codec* codec) {
        std::cout << "\n======= VideoConversionFacade: conversion started. =======" << std::endl;
        Codec* sourceCodec = CodecFactory::extract(videoFile);
        Codec* destinationCodec = new MPEG4CompressionCodec();

        Buffer buffer = BitrateReader::read(videoFile, sourceCodec);
        VideoFile* videoFileConverted = BitrateReader::convert(buffer, videoFile->getName(), destinationCodec);
        AudioMixer* audioMixer = new AudioMixer();
        audioMixer->fix(videoFileConverted, videoFile->getAudioBuffer());

        std::cout << "====== VideoConversionFacade: conversion completed =======\n" << std::endl;

        return videoFileConverted;
    }
};