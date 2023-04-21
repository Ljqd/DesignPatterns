#pragma once

#include <memory>

#include "CarHatchback.h"
#include "CarSedan.h"
#include "CarSuv.h"

#include "DieselEngine.h"
#include "ElectricEngine.h"
#include "GasolineEngine.h"

#include "MechanicalTransmission.h"
#include "HydraulicTransmission.h"

#include "Color.h"
#include "Wheels.h"

#include "CarBuilder.h"
#include "EngineBuilder.h"
#include "TransmissionBuilder.h"
#include "WheelsBuilder.h"

namespace CarModule
{

	class Director
	{
	public:
		static Director* getInstance();

		std::shared_ptr<Car> getStandardHatchback();
		std::shared_ptr<Car> getPremiumHatchback();
		std::shared_ptr<Car> getElectricHatchback();

		std::shared_ptr<Car> getStandardSedan();
		std::shared_ptr<Car> getPremiumSedan();
		std::shared_ptr<Car> getElectricSedan();

		std::shared_ptr<Car> getStandardSuv();
		std::shared_ptr<Car> getPremiumSuv();
		std::shared_ptr<Car> getElectricSuv();

	private:
		Director() = default;
		static Director* director;

		// temporary variables, just for demonstration
		static const size_t standardEnginePower, standardEngineCapacity;
		static const size_t premiumEnginePower, premiumEngineCapacity;

		static const Color hatchbackColor, sedanColor, suvColor;

		static const Wheels::Material standardMaterial, premiumMaterial;
		static const float standardDiameter, premiumDiameter;
	};

}