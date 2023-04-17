#pragma once

namespace CarModule
{

	class Engine
	{
	public:
		void setPower(size_t power);
		int getPower() const;

		void setCapacity(size_t capacity);
		int getCapacity() const;

	protected:
		size_t power, capacity;
	};

}