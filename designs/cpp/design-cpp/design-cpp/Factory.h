#pragma once

#include <memory>
#include <iostream>

// factory pattern
/*
	what : this is object creation pattern.
		   using interface,
		   that the subject of creation is factory.
	why  : using this pattern, now the client doesn't need to know about creator's detail.
	when : we have a superclass with multiple subclass, and based on input, return subclass.
*/

// Q : different enum and enum class?
/* A: In large project, may two enum classes can collide with each other.
	  like same naming.
	  so using concept, like namespace, seperate int-type enum by class scope.
	  prevents enums from working undesirably due to int-types.
*/
enum class VehicleType
{
	Truck,
	Motorcycle,
};

class Vehicle abstract
{
public:
	virtual int PrintWheelCount() = 0;
	static Vehicle* Create(VehicleType);
};

class Truck : public Vehicle
{
public:
	int PrintWheelCount() override;
};

class Motorcycle : public Vehicle
{
public:
	int PrintWheelCount() override;
};