#pragma once

#include <memory>
#include "Monster.h"

class MonsterFactory
{
public:
    virtual std::shared_ptr<Monster> createLowLevel() = 0;
    virtual std::shared_ptr<Monster> createAverageLevel() = 0;
    virtual std::shared_ptr<Monster> createHighLevel() = 0;

    virtual std::shared_ptr<Monster> createCustomLevel(int level) = 0;
};

