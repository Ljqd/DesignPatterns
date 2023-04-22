#pragma once

#include <memory>
#include <vector>
#include <algorithm>

#include <tuple>

#include "Car.h"
#include "Engine.h"
#include "Transmission.h"
#include "Wheels.h"

#include "HelperClass.h"

namespace CarModule
{
	template<typename CachedType>
	class FlyweightContainer
	{
	public:
		// check cache and return shared_ptr or create new, add to cache and return
		template<typename... Args>
		std::shared_ptr<CachedType> getCachedObject(const std::tuple<Args...>& cachedTypeInput);

	private:
		// remove expired weak_ptr from cache
		void eraseExpired();

        std::vector<std::weak_ptr<CachedType>> cache;
	};


	// IMPLEMENTATIONS ===================================================
	template<typename CachedType>
	template<typename... Args>
	std::shared_ptr<CachedType> FlyweightContainer<CachedType>::getCachedObject(const std::tuple<Args...>& cachedTypeInput)
	{
		eraseExpired();
		for (const std::weak_ptr<CachedType>& ptr : cache) {
			if (HelperClass<CachedType, Args...>::compare(ptr, cachedTypeInput))
				return ptr.lock();
		}
		std::shared_ptr<CachedType> result = HelperClass<CachedType, Args...>::getNew(cachedTypeInput);
		std::weak_ptr<CachedType> weak(result);
		cache.emplace_back(weak);

		return result;
	}

	template<typename CachedType>
	void FlyweightContainer<CachedType>::eraseExpired()
	{
		// two options: this or implement Observer pattern which sends signal when shared_ptr is expired
		auto toErase = std::remove_if(
			cache.begin(), cache.end(),
			[](const std::weak_ptr<CachedType>& weak_ptr) {
				return weak_ptr.expired();
			}
		);
		cache.erase(toErase, cache.end());
	}
}