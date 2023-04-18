#pragma once

#include "Engine.h"

namespace CarModule
{
	class GasolineEngine : public Engine
	{
	public:
		std::string getString() override {
			return "GasolineEngine: P(" + std::to_string(power) + +"), cp(" + std::to_string(capacity) + ");";
		}
	};
}