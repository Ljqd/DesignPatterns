#pragma once

#include <memory>
#include <string>

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
		Engine& getEngine();
		Transmission& getTransmission();
		Wheels& getWheels();

		virtual std::string getString() const = 0;
		
		virtual std::unique_ptr<Car> clone() = 0;

	protected:
		virtual std::string getCarName() const = 0;
		std::string getComponentsString() const;

		Color color;
		std::unique_ptr<Engine> engine;
		std::unique_ptr<Transmission> transmission;
		std::unique_ptr<Wheels> wheels;
	};

};