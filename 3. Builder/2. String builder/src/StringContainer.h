#pragma once

#include <iostream>
#include <stdio.h>
#include <string.h>

// Remember that the "string" is immutable in C++
// So, all these STD methods "replace" the string, not "modify" it
// 
// 
// In general, if we really wanted to implement "own" string class
// we would have to reimplement all the STD string methods
// add all necessary C++ constructors
// 
// 
// But for now let's limit ourselves to the [] and ostream<< operators.
class StringContainer
{
public:
    StringContainer();
    StringContainer(size_t length, const char* string);
    StringContainer(const StringContainer& other);
    ~StringContainer();

    char operator[](size_t index) const;

    size_t size() const;

    friend std::ostream& operator<<(std::ostream& os, const StringContainer& other);

private:
    size_t length;
    char* string;
};