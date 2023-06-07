#include "ZombieFactory.h"

#include "Zombie.h"

std::shared_ptr<Monster> ZombieFactory::createLowLevel()
{
    return std::make_shared<Zombie>(5);
}

std::shared_ptr<Monster> ZombieFactory::createAverageLevel()
{
    return std::make_shared<Zombie>(15);
}

std::shared_ptr<Monster> ZombieFactory::createHighLevel()
{
    return std::make_shared<Zombie>(30);
}

std::shared_ptr<Monster> ZombieFactory::createCustomLevel(int level)
{
    return std::make_shared<Zombie>(level);
}

