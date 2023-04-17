#pragma once

#include "Engine.h"

namespace CarModule
{
	class ElectricEngine : public Engine
	{
	public:
		void setChargingTime(size_t time);
		size_t getChargingTime() const;

	private:
		size_t chargingTime;
	};
}