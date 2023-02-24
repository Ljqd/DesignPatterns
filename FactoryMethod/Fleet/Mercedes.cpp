#include "Mercedes.h"


Mercedes::Mercedes(int factoryId, const std::string& factoryTitle) :
    factoryTitle{ factoryTitle }, factoryId{ factoryId }
{
    std::cout << "Created new Mercedes on " << factoryTitle << "'s factory;" << std::endl;
}

std::string Mercedes::getFactoryTitle() const
{
    return factoryTitle;
}

int Mercedes::getFactoryId() const
{
    return factoryId;
}

void Mercedes::setFactoryId(int factoryId)
{
    this->factoryId = factoryId;
}

void Mercedes::setFactoryTitle(const std::string& factoryTitle)
{
    this->factoryTitle = factoryTitle;
}