#include <iostream>

#include "src/StringBuilder.h"
#include "src/StringContainer.h"

int main()
{
    StringBuilder builder;
    builder.append("Hello, ");
    builder.append("World!");
    builder.insert(7, "Brave New ");
    StringContainer string = builder.build();
    std::cout << string << std::endl;
}