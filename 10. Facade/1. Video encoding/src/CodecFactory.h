#pragma once

#include <string>

#include "VideoFile.h"
#include "Codec.h"

#include "MPEG4CompressionCodec.h"
#include "OggCompressionCodec.h"

class CodecFactory
{
public:
    static Codec* extract(VideoFile* file) {
        std::string type = file->getCodecType();
        if (type == "mp4") {
            return new MPEG4CompressionCodec();
        }
        else {
            return new OggCompressionCodec();
        }
    }
};