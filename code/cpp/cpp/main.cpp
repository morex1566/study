#include <memory>
#include <iostream>

#include "Class.h"
#include "Attribute.h"

void main()
{
	// test inheritance class
	Transportation* mount1 = new Car();

	mount1->Move();
	std::cout << mount1->GetMetric();

	delete mount1;

	// test abstract inheritance class
	Vehicle* mount2 = new Motorcycle();

	mount2->Move();
	std::cout << mount2->GetMetric();

	delete mount2;

	Attribute* attribution = new Attribute();
	attribution->ClassTest();
	delete attribution;

	return;
}