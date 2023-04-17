#pragma once

#include <memory>

#include "Color.h"
#include "Engine.h"
#include "Transmission.h"
#include "Wheels.h"

namespace CarModule
{

	class Car
	{
	public:
		void setColor(Color color);
		void setEngine(std::unique_ptr<Engine>& engine);
		void setTransmission(std::unique_ptr<Transmission>& transmission);
		void setWheels(std::unique_ptr<Wheels>& wheels);

		Color getColor() const;
		std::unique_ptr<Engine> getEngine();
		std::unique_ptr<Transmission> getTransmission();
		std::unique_ptr<Wheels> getWheels();

	protected:
		Color color;
		std::unique_ptr<Engine> engine;
		std::unique_ptr<Transmission> transmission;
		std::unique_ptr<Wheels> wheels;
	};

};