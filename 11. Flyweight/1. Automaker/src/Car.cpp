#include "Car.h"

using namespace CarModule;


void Car::setColor(Color color)
{
    this->color = color;
}

void Car::setEngine(std::shared_ptr<Engine>& engine)
{
    this->engine = engine;
}

void Car::setTransmission(std::shared_ptr<Transmission>& transmission)
{
    this->transmission = transmission;
}

void Car::setWheels(std::shared_ptr<Wheels>& wheels)
{
    this->wheels = wheels;
}

Color Car::getColor() const
{
    return color;
}

Engine& Car::getEngine()
{
    return *engine;
}

Transmission& Car::getTransmission()
{
    return *transmission;
}

Wheels& Car::getWheels()
{
    return *wheels;
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