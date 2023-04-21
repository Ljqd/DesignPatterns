#pragma once

#include <string>

namespace CarModule
{
    class Transmission
    {
    public:
        virtual void setGears(size_t gears) = 0;
        virtual size_t getGears() const = 0;

        std::string getString() const {
            return "Transmission: gears = " + std::to_string(gears) + ";";
        }

    protected:
        size_t gears;
    };
}