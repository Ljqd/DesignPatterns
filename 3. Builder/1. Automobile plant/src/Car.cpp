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

std::string Car::getComponentsString() const
{
    std::string colorString = {};
    switch (color)
    {
    case RED:
        colorString = "red";
        break;
    case GREEN:
        colorString = "green";
        break;
    case BLUE:
        colorString = "blue";
        break;
    default:
        break;
    }

    std::string engineString = engine->getString();
    std::string transmissionString = transmission->getString();
    std::string wheelsString = wheels->getSring();

    std::string result = "";
    for (const std::string& component : { engineString, transmissionString, wheelsString })
        result += '\t' + component + '\n';

    return result;
}