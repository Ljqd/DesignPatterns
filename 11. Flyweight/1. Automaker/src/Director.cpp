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
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::shared_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::shared_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();
    
    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(Director::hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::shared_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::shared_ptr<Car> Director::getPremiumHatchback()
{
    // get engine
    EngineBuilder<GasolineEngine> engineBuilder = {};
    std::shared_ptr<Engine> engine = engineBuilder.setPower(premiumEnginePower).setCapacity(premiumEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::shared_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(premiumDiameter).setMaterial(premiumMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::shared_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::shared_ptr<Car> Director::getElectricHatchback()
{
    // get engine
    EngineBuilder<ElectricEngine> engineBuilder = {};
    std::shared_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(premiumEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::shared_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(premiumMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::shared_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::shared_ptr<Car> Director::getStandardSedan()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::shared_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::shared_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarSedan> builder = {};
    builder.setColor(Director::sedanColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::shared_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::shared_ptr<Car> Director::getPremiumSedan()
{
    // get engine
    EngineBuilder<GasolineEngine> engineBuilder = {};
    std::shared_ptr<Engine> engine = engineBuilder.setPower(premiumEnginePower).setCapacity(premiumEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::shared_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(premiumDiameter).setMaterial(premiumMaterial).build();

    // Finally, the car builder
    CarBuilder<CarSedan> builder = {};
    builder.setColor(sedanColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::shared_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::shared_ptr<Car> Director::getElectricSedan()
{
    // get engine
    EngineBuilder<ElectricEngine> engineBuilder = {};
    std::shared_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(premiumEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::shared_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(premiumMaterial).build();

    // Finally, the car builder
    CarBuilder<CarSedan> builder = {};
    builder.setColor(sedanColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::shared_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::shared_ptr<Car> Director::getStandardSuv()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::shared_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::shared_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarSuv> builder = {};
    builder.setColor(suvColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::shared_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::shared_ptr<Car> Director::getPremiumSuv()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::shared_ptr<Engine> engine = engineBuilder.setPower(premiumEnginePower).setCapacity(premiumEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::shared_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(premiumDiameter).setMaterial(premiumMaterial).build();

    // Finally, the car builder
    CarBuilder<CarSuv> builder = {};
    builder.setColor(suvColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::shared_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::shared_ptr<Car> Director::getElectricSuv()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::shared_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(premiumEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::shared_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::shared_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(premiumMaterial).build();

    // Finally, the car builder
    CarBuilder<CarSuv> builder = {};
    builder.setColor(suvColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::shared_ptr<Car> result = builder.getCar();

    return std::move(result);
}