#include "ImpFactory.h"

#include "Imp.h"

std::shared_ptr<Monster> ImpFactory::createLowLevel()
{
    return std::make_shared<Imp>(5);
}

std::shared_ptr<Monster> ImpFactory::createAverageLevel()
{
    return std::make_shared<Imp>(15);
}

std::shared_ptr<Monster> ImpFactory::createHighLevel()
{
    return std::make_shared<Imp>(30);
}

std::shared_ptr<Monster> ImpFactory::createCustomLevel(int level)
{
    return std::make_shared<Imp>(level);
}
