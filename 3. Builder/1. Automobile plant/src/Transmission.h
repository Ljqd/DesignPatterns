#pragma once

namespace CarModule
{
    class Transmission
    {
    public:
        virtual void setGears(size_t gears) = 0;
        virtual size_t getGears() const = 0;

    protected:
        size_t gears;
    };
}