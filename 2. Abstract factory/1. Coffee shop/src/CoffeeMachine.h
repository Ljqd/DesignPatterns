#pragma once

#include <memory>

#include "Coffee.h"

class CoffeeMachine
{
public:
    virtual std::unique_ptr<Coffee> getAmericano() const = 0;
    virtual std::unique_ptr<Coffee> getCappuccino() const = 0;
    virtual std::unique_ptr<Coffee> getEspresso() const = 0;
    virtual std::unique_ptr<Coffee> getLatte() const = 0;
};