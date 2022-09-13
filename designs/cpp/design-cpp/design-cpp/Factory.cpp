#include "Factory.h"

Vehicle* Vehicle::Create(VehicleType type)
{
	Vehicle* vehicle;

	switch (type)
	{
	case VehicleType::Truck:
		vehicle = new Truck();
		break;

	case VehicleType::Motorcycle:
		vehicle = new Motorcycle;
		break;

	default:
		vehicle = nullptr;
		break;
	}

	return vehicle;
}

int Truck::PrintWheelCount()
{
	std::cout << "truck : 4 wheels" << std::endl;
	return 0;
}

int Motorcycle::PrintWheelCount()
{
	std::cout << "motorcycle : 2 wheels" << std::endl;
	return 0;
}