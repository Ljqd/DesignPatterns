#include "Director.h"

using namespace CarModule;

const size_t Director::standardEnginePower = 10, Director::standardEngineCapacity = 15;
const size_t Director::premiumEnginePower = 20, Director::premiumEngineCapacity = 30;

const Color Director::hatchbackColor = Color::BLUE, Director::sedanColor = Color::RED, Director::suvColor = Color::GREEN;

const Wheels::Material Director::standardMaterial = Wheels::Material::LIGHT_ALLOY, Director::premiumMaterial = Wheels::Material::STEEL;
const float Director::standardDiameter = 12, Director::premiumDiameter = 14;

Director* Director::director = nullptr;

Director* Director::getInstance()
{

    if (director == nullptr) {
        director = new Director();
    }

    return director;
}

std::shared_ptr<Car> Director::getStandardHatchback()
{
    // get engine
    dieselEngineBuilder.reset();
    std::shared_ptr<Engine> engine = dieselEngineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    mechanicalTransmissionBuilder.reset();
    std::shared_ptr<Transmission> transmission = mechanicalTransmissionBuilder.setGears(6).build();
    
    // get Wheels
    wheelsBuilder.reset();
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    hatchbackBuilder.reset();
    hatchbackBuilder.setColor(Director::hatchbackColor);
    hatchbackBuilder.setEngine(engine);
    hatchbackBuilder.setTransmission(transmission);
    hatchbackBuilder.setWheels(wheels);

    std::shared_ptr<Car> result = hatchbackBuilder.getCar();

    return result;
}