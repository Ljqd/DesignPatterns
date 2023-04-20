#pragma once

#include <string>

#include "Codec.h"

class MPEG4CompressionCodec : public Codec
{
public:
    std::string type() const override {
        return "mp4";
    }
};