#pragma once

#include "StringContainer.h"


class StringBuilder {
public:
    StringBuilder();

    ~StringBuilder();
    StringBuilder& append(const char* s);
    StringBuilder& insert(size_t pos, const char* s);
    StringContainer build();

private:
    void ensure_capacity(size_t requiredCapacity);

    char* data;
    size_t length;
    size_t capacity;
};