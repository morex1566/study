#include "Class.h"

MyClass::MyClass()
{
    myField = 0.0f;
}

MyClass::~MyClass()
{
}

float MyClass::GetField()
{
    return myField;
}

void MyClass::SetField(float source)
{
    myField = source;
}

Transportation::Transportation()
{
    speed = 1.0f;
    metric = 0.0f;
}

Transportation::~Transportation()
{
}

void Transportation::Move()
{
    metric += speed;
}

void Transportation::SetSpeed(float source)
{
    speed = source;
}

float Transportation::GetSpeed()
{
    return speed;
}

float Transportation::GetMetric()
{
    return metric;
}

Car::Car()
    : Transportation()
{
    speed = 2.0f;
}

Car::~Car()
{
}

void Car::Move()
{
    metric += speed * 2;
}

Plane::Plane()
{
    speed = 4.0f;
}

Plane::~Plane()
{
}

void Plane::Move()
{
    metric += speed * 4;
}

Vehicle::Vehicle()
{
    speed = 1.0f;
    metric = 0.0f;
}

Vehicle::~Vehicle()
{
}

void Vehicle::BoostSpeed()
{
    speed = speed * 2;
}

void Vehicle::SetSpeed(float source)
{
    speed = source;
}

float Vehicle::GetSpeed()
{
    return speed;
}

float Vehicle::GetMetric()
{
    return metric;
}

Motorcycle::Motorcycle()
    : Vehicle()
{
    speed = 2.0f;
    metric = 0.0f;
}

Motorcycle::~Motorcycle()
{

}

void Motorcycle::Move()
{
    metric += speed * 2;    
}
