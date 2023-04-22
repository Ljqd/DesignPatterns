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
		void setEngine(std::shared_ptr<Engine> engine);
		void setTransmission(std::shared_ptr<Transmission> transmission);
		void setWheels(std::shared_ptr<Wheels> wheels);

		Color getColor() const;
		Engine& getEngine();
		Transmission& getTransmission();
		Wheels& getWheels();

		virtual std::string getString() const = 0;
		
		virtual std::shared_ptr<Car> clone() = 0;

		bool operator==(const Car& other);

	protected:
		virtual std::string getCarName() const = 0;
		std::string getComponentsString() const;

		Color color;
		std::shared_ptr<Engine> engine;
		std::shared_ptr<Transmission> transmission;
		std::shared_ptr<Wheels> wheels;
	};

};