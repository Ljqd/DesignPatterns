#include "StringContainer.h"


StringContainer::StringContainer()
{
    length = 0;
    string = nullptr;
}

StringContainer::StringContainer(size_t length, const char* string)
{
    this->length = length;
    this->string = new char[length]();

    std::memcpy(this->string, string, length);
}


StringContainer::StringContainer(const StringContainer& other)
{
    length = other.length;
    string = new char[length]();

    std::memcpy(this->string, string, length);
}

StringContainer::~StringContainer()
{
    delete string;
}

char StringContainer::operator[](size_t index) const
{
    if (index > length)
        throw("StringContainer::operator[]: index > length;");
    return string[index];
}

size_t StringContainer::size() const
{
    return length;
}

std::ostream& operator<<(std::ostream& os, const StringContainer& other)
{
    for (size_t i = 0; i < other.size(); i++)
        os << other[i];
    return os;
}