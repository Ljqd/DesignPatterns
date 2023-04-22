#include "WheelsBuilder.h"

using namespace CarModule;

WheelsBuilder::WheelsBuilder()
{
    reset();
    cachedWheels = {};
}

void WheelsBuilder::reset()
{
    cachedMaterial = {};
    cachedDiameter = {};
}

std::shared_ptr<Wheels> WheelsBuilder::build()
{
    std::tuple<Wheels::Material, float> tpl = { cachedMaterial, cachedDiameter };
    std::shared_ptr<Wheels> result = std::make_shared<Wheels>(*cachedWheels.getCachedObject(tpl));
    reset();
    return result;
}

WheelsBuilder& WheelsBuilder::setMaterial(Wheels::Material material)
{
    cachedMaterial = material;
    return *this;
}

WheelsBuilder& WheelsBuilder::setDiameter(float diameter)
{
    cachedDiameter = diameter;
    return *this;
}