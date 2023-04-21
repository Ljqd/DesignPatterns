#pragma once

#include <memory>
#include <string>

namespace CarModule
{

	class Engine
	{
	public:
		void setPower(size_t power);
		int getPower() const;

		void setCapacity(size_t capacity);
		int getCapacity() const;

		virtual std::string getString() = 0;

		virtual std::shared_ptr<Engine> clone() = 0;

	protected:
		size_t power, capacity;
	};

}