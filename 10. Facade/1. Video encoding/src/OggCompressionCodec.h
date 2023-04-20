#pragma once

#include <string>

#include "Codec.h"

class OggCompressionCodec : public Codec
{
public:
    std::string type() const override {
        return "ogg";
    }
};