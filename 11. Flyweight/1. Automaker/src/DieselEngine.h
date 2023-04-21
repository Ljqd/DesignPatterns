#pragma once

#include "Engine.h"

namespace CarModule
{
	class DieselEngine : public Engine
	{
	public:
		std::string getString() override {
			return "DieselEngine: P(" + std::to_string(power) + +"), cp(" + std::to_string(capacity) + ");";
		}
	};
}