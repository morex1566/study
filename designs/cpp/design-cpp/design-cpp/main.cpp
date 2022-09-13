#include <iostream>
#include <memory>

#include "Factory.h"
#include "Observer.h"

using namespace std;

// error! : can't use smart pointer with abstract class
void TestFactoryPattern()
{
	Vehicle* mount1 = Vehicle::Create(VehicleType::Truck);
	Vehicle* mount2 = Vehicle::Create(VehicleType::Motorcycle);

	mount1->PrintWheelCount();
	mount2->PrintWheelCount();

	delete mount1;
	delete mount2;

	return;
}

void TestObserverPattern()
{


	return;
}

int main()
{
	TestFactoryPattern();

	return 0;
}