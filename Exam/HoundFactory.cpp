#include "HoundFactory.h"

#include "Hound.h"

std::shared_ptr<Monster> HoundFactory::createLowLevel()
{
    return std::make_shared<Hound>(5);
}

std::shared_ptr<Monster> HoundFactory::createAverageLevel()
{
    return std::make_shared<Hound>(15);
}

std::shared_ptr<Monster> HoundFactory::createHighLevel()
{
    return std::make_shared<Hound>(30);
}

std::shared_ptr<Monster> HoundFactory::createCustomLevel(int level)
{
    return std::make_shared<Hound>(level);
}
