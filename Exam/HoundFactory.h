#pragma once

#include "MonsterFactory.h"

class HoundFactory : public MonsterFactory
{
public:
    std::shared_ptr<Monster> createLowLevel() override;
    std::shared_ptr<Monster> createAverageLevel() override;
    std::shared_ptr<Monster> createHighLevel() override;

    std::shared_ptr<Monster> createCustomLevel(int level) override;
};

