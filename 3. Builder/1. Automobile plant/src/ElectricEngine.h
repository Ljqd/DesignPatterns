#pragma once

#include "Engine.h"

namespace CarModule
{
	class ElectricEngine : public Engine
	{
	public:

		// since these methods aren't parts of the Engine interface - remember about static_cast
		void setChargingTime(size_t time);
		size_t getChargingTime() const;

		std::string getString() override;

	private:
		size_t chargingTime;
	};
}