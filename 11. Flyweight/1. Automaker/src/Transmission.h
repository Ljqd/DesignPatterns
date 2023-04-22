#pragma once

#include <memory>
#include <string>

namespace CarModule
{
    class Transmission
    {
    public:
        virtual std::shared_ptr<Transmission> clone() = 0;

        void setGears(size_t gears) {
            this->gears = gears;
        }

        size_t getGears() const {
            return this->gears;
        }

        std::string getString() const {
            return "Transmission: gears = " + std::to_string(gears) + ";";
        }

        bool operator==(const Transmission& t) {
            return t.gears == this->gears;
        }

    protected:
        size_t gears;
    };
}