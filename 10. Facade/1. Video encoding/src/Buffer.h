#pragma once

#include <string>

class Buffer
{
public:
    Buffer() {
        buffer = "";
    }

    Buffer(const std::string& buffer) {
        this->buffer = buffer;
    }

    std::string getData() const {
        return buffer;
    }

    friend bool operator==(const Buffer& obj1, const Buffer& obj2) {
        return obj1.buffer == obj2.buffer;
    }

private:
    std::string buffer;
};