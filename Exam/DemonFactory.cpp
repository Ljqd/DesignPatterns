#include "DemonFactory.h"

#include "Demon.h"

std::shared_ptr<Monster> DemonFactory::createLowLevel()
{
    return std::make_shared<Demon>(5);
}

std::shared_ptr<Monster> DemonFactory::createAverageLevel()
{
    return std::make_shared<Demon>(15);
}

std::shared_ptr<Monster> DemonFactory::createHighLevel()
{
    return std::make_shared<Demon>(30);
}

std::shared_ptr<Monster> DemonFactory::createCustomLevel(int level)
{
    return std::make_shared<Demon>(level);
}
