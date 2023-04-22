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

		// At first, technically director must obtain Builder* from the outside
		// Second, disadvantage of templates => schematically:
		//     ClassA<int> and ClassA<float> is two completely different classes
		//     so you need explicitly declare each possible Builder
		//
		// Since now our builders need to share common "cache" - we need to have
		// them all as member variables. 
		// 
		// I think it's a good idea make Builder-s a Singleton            (<---) 
		//
		// Second note:
		// Car preserves only shared_ptr-s to components (Engine/Transmission)
		// but engine builder has own cache and this is its resposibility to
		// provide correct shared_tpr
		//
		// This is all about you don't have to worry about does CarA and CarB
		// really have common shared_ptr<EngineX> or they contain two separate shared_ptr
		// and our Flyweight doesn't work

		CarBuilder<CarHatchback> hatchbackBuilder;
		CarBuilder<CarSedan> sedanBuilder;
		CarBuilder<CarSuv> suvBuilder;

		EngineBuilder<DieselEngine> dieselEngineBuilder;
		EngineBuilder<ElectricEngine> electricEngineBuilder;
		EngineBuilder<GasolineEngine> gasolineEngineBuilder;

		TransmissionBuilder<MechanicalTransmission> mechanicalTransmissionBuilder;
		TransmissionBuilder<HydraulicTransmission> hydraulicTransmissionBuilder;

		WheelsBuilder wheelsBuilder;

		// temporary variables, just for demonstration
		static const size_t standardEnginePower, standardEngineCapacity;
		static const size_t premiumEnginePower, premiumEngineCapacity;

		static const Color hatchbackColor, sedanColor, suvColor;

		static const Wheels::Material standardMaterial, premiumMaterial;
		static const float standardDiameter, premiumDiameter;
	};

}