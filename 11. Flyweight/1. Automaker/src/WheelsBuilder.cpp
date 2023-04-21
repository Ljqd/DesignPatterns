#include "WheelsBuilder.h"

using namespace CarModule;

WheelsBuilder::WheelsBuilder()
{
    reset();
}

void WheelsBuilder::reset()
{
    product = std::make_unique<Wheels>();
}

std::shared_ptr<Wheels> WheelsBuilder::build()
{
    std::shared_ptr<Wheels> result = std::move(product);
    reset();
    return result;
}

WheelsBuilder& WheelsBuilder::setMaterial(Wheels::Material material)
{
    product->setMaterial(material);
    return *this;
}

WheelsBuilder& WheelsBuilder::setDiameter(float diameter)
{
    product->setDiameter(diameter);
    return *this;
}