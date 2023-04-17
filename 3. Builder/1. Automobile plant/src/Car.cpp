#include "Car.h"

using namespace CarModule;


void Car::setColor(Color color)
{
    this->color = color;
}

void Car::setEngine(std::unique_ptr<Engine>& engine)
{
    this->engine.reset(engine.release());
}

void Car::setTransmission(std::unique_ptr<Transmission>& transmission)
{
    this->transmission.reset(transmission.release());
}

void Car::setWheels(std::unique_ptr<Wheels>& wheels)
{
    this->wheels.reset(wheels.release());
}

Color Car::getColor() const
{
    return color;
}

std::unique_ptr<Engine> Car::getEngine()
{
    return std::move(engine);
}

std::unique_ptr<Transmission> Car::getTransmission()
{
    return std::move(transmission);
}

std::unique_ptr<Wheels> Car::getWheels()
{
    return std::move(wheels);
}

std::string Car::getString() const
{
    std::string str = "Just something";
    return str;
}