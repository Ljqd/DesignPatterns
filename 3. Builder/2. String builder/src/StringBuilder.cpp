#include "StringBuilder.h"


StringBuilder::StringBuilder() : data(nullptr), length(0), capacity(0)
{}

StringBuilder::~StringBuilder() {
    delete[] data;
}

StringBuilder& StringBuilder::append(const char* s) {
    size_t segmentLength = std::strlen(s);
    ensure_capacity(length + segmentLength);
    std::memcpy(data + length, s, segmentLength);
    length += segmentLength;
    return *this;
}

StringBuilder& StringBuilder::insert(size_t pos, const char* s) {
    size_t segmentLength = std::strlen(s);
    ensure_capacity(length + segmentLength);
    std::memmove(data + pos + segmentLength, data + pos, length - pos);
    std::memcpy(data + pos, s, segmentLength);
    length += segmentLength;
    return *this;
}

StringContainer StringBuilder::build() {
    char* result = new char[length + 1];
    std::memcpy(result, data, length);
    result[length] = '\0';
    return StringContainer(length, result);
}

void StringBuilder::ensure_capacity(size_t requiredCapacity) {
    if (requiredCapacity <= capacity)
        return;

    size_t newCapacity = std::max(capacity * 2, requiredCapacity);
    char* newData = new char[newCapacity];

    std::memcpy(newData, data, length);
    delete[] data;

    data = newData;
    capacity = newCapacity;
}