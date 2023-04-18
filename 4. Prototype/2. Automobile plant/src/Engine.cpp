#include "Engine.h"

using namespace CarModule;

void Engine::setPower(size_t power)
{
    this->power = power;
}

int Engine::getPower() const
{
    return power;
}

void Engine::setCapacity(size_t capacity)
{
    this->capacity = capacity;
}

int Engine::getCapacity() const
{
    return capacity;
}