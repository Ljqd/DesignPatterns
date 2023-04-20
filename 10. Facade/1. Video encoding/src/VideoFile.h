#pragma once

#include <iostream>
#include <string>

#include "Buffer.h"
#include "Codec.h"

class VideoFile
{
public:

    VideoFile(const std::string& name, const Buffer& videlBuffer, const Buffer& audioBuffer) {
        this->videlBuffer = videlBuffer;
        this->audioBuffer = audioBuffer;

        size_t i = name.rfind(".");

        if (i == std::string::npos)
            throw("File format is undefined!");
        

        this->name = name.substr(0, name.length() - 4);
        this->codecType = name.substr(i + 1, 3);
    }

    VideoFile(const std::string& name, const Buffer& videlBuffer) : 
        VideoFile(name, videlBuffer, Buffer(""))
    {}

    std::string getCodecType() {
        return codecType;
    }

    Buffer getVidelBuffer(Codec* codec) {
        if (codec->type() == getCodecType()) {
            return videlBuffer;
        }
        return Buffer("");
    }

    void setAudioBuffer(Buffer audioBuffer) {
        this->audioBuffer = audioBuffer;
    }

    Buffer getAudioBuffer() const {
        return audioBuffer;
    }

    std::string getName() const {
        return name;
    }

    void play(Codec* codec) {
        if (codec->type() == codecType) {
            std::cout << "Video data:" + videlBuffer.getData() << std::endl;
            if (audioBuffer == Buffer("")) {
                std::cout << "Audio data is inaccessible!" << std::endl;
                return;
            }
            std::cout << "Audio data:" + audioBuffer.getData() << std::endl;
        }
        else {
            std::cout << "Failed to play file" + name << "; \n";
            std::cout << "Codec '" << codecType << "' required!\n";
            std::cout << "Use correct codec!" << std::endl;
        }
    }

private:
    std::string name;
    std::string codecType;
    Buffer videlBuffer;
    Buffer audioBuffer;
};