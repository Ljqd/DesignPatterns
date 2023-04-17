#include "Director.h"

using namespace CarModule;

const size_t Director::standardEnginePower = 10, Director::standardEngineCapacity = 15;
const size_t Director::premiumEnginePower = 20, Director::premiumEngineCapacity = 30;

const Color Director::hatchbackColor = Color::BLUE, Director::sedanColor = Color::RED, Director::suvColor = Color::GREEN;

const Wheels::Material Director::standardMaterial = Wheels::Material::LIGHT_ALLOY, Director::premiumMaterial = Wheels::Material::STEEL;
const float Director::standardDiameter = 12, Director::premiumDiameter = 14;

std::unique_ptr<Car> Director::getStandardHatchback()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::unique_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::unique_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();
    
    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::unique_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(Director::hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::unique_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::unique_ptr<Car> Director::getPremiumHatchback()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::unique_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::unique_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::unique_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::unique_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::unique_ptr<Car> Director::getElectricHatchback()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::unique_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::unique_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::unique_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::unique_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::unique_ptr<Car> Director::getStandardSedan()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::unique_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::unique_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::unique_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::unique_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::unique_ptr<Car> Director::getPremiumSedan()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::unique_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::unique_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::unique_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::unique_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::unique_ptr<Car> Director::getElectricSedan()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::unique_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::unique_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::unique_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::unique_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::unique_ptr<Car> Director::getStandardSuv()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::unique_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::unique_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::unique_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::unique_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::unique_ptr<Car> Director::getPremiumSuv()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::unique_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::unique_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::unique_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::unique_ptr<Car> result = builder.getCar();

    return std::move(result);
}

std::unique_ptr<Car> Director::getElectricSuv()
{
    // get engine
    EngineBuilder<DieselEngine> engineBuilder = {};
    std::unique_ptr<Engine> engine = engineBuilder.setPower(standardEnginePower).setCapacity(standardEngineCapacity).build();

    // get transmission
    TransmissionBuilder<MechanicalTransmission> transmissionBuilder = {};
    std::unique_ptr<Transmission> transmission = transmissionBuilder.setGears(6).build();

    // get Wheels
    WheelsBuilder wheelsBuilder = {};
    std::unique_ptr<Wheels> wheels = wheelsBuilder.setDiameter(standardDiameter).setMaterial(standardMaterial).build();

    // Finally, the car builder
    CarBuilder<CarHatchback> builder = {};
    builder.setColor(hatchbackColor);
    builder.setEngine(engine);
    builder.setTransmission(transmission);
    builder.setWheels(wheels);

    std::unique_ptr<Car> result = builder.getCar();

    return std::move(result);
}