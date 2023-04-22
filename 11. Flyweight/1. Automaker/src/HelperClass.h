#pragma once

#include <memory>
#include <tuple>

#include "Car.h"
#include "Engine.h"
#include "Transmission.h"
#include "Wheels.h"

namespace CarModule
{
    template<typename CachedType, typename... Args>
    class HelperClass
    {
	public:
		static bool compare(const std::weak_ptr<CachedType>& ptr, const std::tuple<Args...>& cachedTypeInput);
		static std::shared_ptr<CachedType> getNew(const std::tuple<Args...>& cachedTypeInput);
    };

	// ============ Car implementation =========================================
	template<typename CarType>
	class HelperClass<CarType, Color, std::shared_ptr<Engine>, std::shared_ptr<Transmission>, std::shared_ptr<Wheels>>
	{
	public:
		static bool compare(
			const std::weak_ptr<CarType>& ptr, 
			const std::tuple<Color, std::shared_ptr<Engine>, std::shared_ptr<Transmission>, std::shared_ptr<Wheels>>& cachedTypeInput
		)
		{
			// cachedColor, cachedEngine, cachedTransmission, cachedWheels

			bool s0 = ptr.lock()->getColor() == std::get<0>(cachedTypeInput);
			bool s1 = ptr.lock()->getEngine() == *std::get<1>(cachedTypeInput);
			bool s2 = ptr.lock()->getTransmission() == *std::get<2>(cachedTypeInput);
			bool s3 = ptr.lock()->getWheels() == *std::get<3>(cachedTypeInput);
			return s0 && s1 && s2 && s3;
		}

		static std::shared_ptr<CarType> getNew(
			const std::tuple<Color, std::shared_ptr<Engine>, std::shared_ptr<Transmission>, std::shared_ptr<Wheels>>& cachedTypeInput
		)
		{
			std::shared_ptr<CarType> result = std::make_shared<CarType>();

			result->setColor(std::get<0>(cachedTypeInput));
			result->setEngine(std::get<1>(cachedTypeInput));
			result->setTransmission(std::get<2>(cachedTypeInput));
			result->setWheels(std::get<3>(cachedTypeInput));

			return std::make_shared<CarType>(*result);
		}
	};


	// ============ Engine implementation ====================================== 
	template<typename EngineType>
	class HelperClass<EngineType, size_t, size_t>
	{
	public:
		static bool compare(const std::weak_ptr<EngineType>& ptr, const std::tuple<size_t, size_t>& cachedTypeInput)
		{
			size_t power = std::get<0>(cachedTypeInput);
			size_t capacity = std::get <1>(cachedTypeInput);

			return (
				ptr.lock()->getPower() == power && ptr.lock()->getCapacity() == capacity
				);
		};

		static std::shared_ptr<EngineType> getNew(const std::tuple<size_t, size_t>& cachedTypeInput)
		{
			size_t power = std::get<0>(cachedTypeInput);
			size_t capacity = std::get<1>(cachedTypeInput);

			std::shared_ptr<EngineType> result = std::make_shared<EngineType>();
			result->setPower(power);
			result->setCapacity(capacity);

			return std::make_shared<EngineType>(*result);
		}
	};

	// ============ Transmission implementation ================================
	template<typename TransmissionType>
	class HelperClass<TransmissionType, size_t>
	{
	public:
		static bool compare(const std::weak_ptr<TransmissionType>& ptr, const std::tuple<size_t>& cachedTypeInput)
		{
			size_t gears = std::get<0>(cachedTypeInput);

			return ptr.lock()->getGears() == gears;
		};

		static std::shared_ptr<TransmissionType> getNew(const std::tuple<size_t>& cachedTypeInput)
		{
			size_t gears = std::get<0>(cachedTypeInput);

			std::shared_ptr<TransmissionType> result = std::make_shared<TransmissionType>();
			result->setGears(gears);

			return std::make_shared<TransmissionType>(*result);
		}
	};

	// ============ Wheels implementation ======================================
	template<>
	class HelperClass<Wheels, Wheels::Material, float>
	{
	public:
		static bool compare(const std::weak_ptr<Wheels>& ptr, const std::tuple<Wheels::Material, float>& cachedTypeInput)
		{
			Wheels::Material cachedMaterial = std::get<0>(cachedTypeInput);
			float cachedDiameter = std::get<1>(cachedTypeInput);

			return ptr.lock()->getDiameter() == cachedDiameter && ptr.lock()->getMaterial() == cachedMaterial;
		};

		static std::shared_ptr<Wheels> getNew(const std::tuple<Wheels::Material, float>& cachedTypeInput)
		{
			Wheels::Material cachedMaterial = std::get<0>(cachedTypeInput);
			float cachedDiameter = std::get<1>(cachedTypeInput);

			std::shared_ptr<Wheels> result = std::make_shared<Wheels>();
			result->setDiameter(cachedDiameter);
			result->setMaterial(cachedMaterial);

			return result;
		}
	};
}

