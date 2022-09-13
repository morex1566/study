#pragma once

// getter setter property를 사용한 기본 클래스 구현
// Q : getter setter 보다 더 좋은 디자인의 캡슐화 표현?
class MyClass
{
public:
	MyClass();
	~MyClass();

	float GetField();
	void SetField(float);

private:
	float myField;
};

// 일반 클래스의 상속
// is - a 관계일 경우에는 상속, has - a 관계일 경우에는 구성으로 구현
// virtual 소멸자를 통해서 부모 포인터로 자식을 삭제
// 자식은 부모 생성자를 호출 parent() 사용
class Transportation
{
public:
	Transportation();
	virtual ~Transportation();

	virtual void Move();

	void SetSpeed(float);
	float GetSpeed();
	float GetMetric();

protected:
	float speed;
	float metric;
};

class Car : public Transportation
{
public:
	Car();
	~Car() override;

	void Move() override;
};

class Plane : public Transportation
{
public:
	Plane();
	~Plane() override;

	void Move() override;
};

// 추상클래스의 상속과 구현
/*
* c++ 에서는 인터페이스가 없음, 순수 가상함수만 가지는 추상클래스로 구현
* c++은 다중 상속을 지원한다.
* 추상클래스는 서로 관련된 객체의 같이 사용하는 기능을 각자 확장 시킬 때,
* 추상클래스도 생성자와 소멸자를 작성해주는 것이 좋다.
*/
class Vehicle abstract
{
public:
	Vehicle();
	virtual ~Vehicle() = 0;
	
	void BoostSpeed();
	virtual void Move() = 0;

	void SetSpeed(float);
	float GetSpeed();
	float GetMetric();

protected:
	float speed;
	float metric;
};

class Motorcycle : public Vehicle
{
public:
	Motorcycle();
	~Motorcycle() override;

	void Move() override;
};