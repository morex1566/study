#pragma once

// getter setter property�� ����� �⺻ Ŭ���� ����
// Q : getter setter ���� �� ���� �������� ĸ��ȭ ǥ��?
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

// �Ϲ� Ŭ������ ���
// is - a ������ ��쿡�� ���, has - a ������ ��쿡�� �������� ����
// virtual �Ҹ��ڸ� ���ؼ� �θ� �����ͷ� �ڽ��� ����
// �ڽ��� �θ� �����ڸ� ȣ�� parent() ���
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

// �߻�Ŭ������ ��Ӱ� ����
/*
* c++ ������ �������̽��� ����, ���� �����Լ��� ������ �߻�Ŭ������ ����
* c++�� ���� ����� �����Ѵ�.
* �߻�Ŭ������ ���� ���õ� ��ü�� ���� ����ϴ� ����� ���� Ȯ�� ��ų ��,
* �߻�Ŭ������ �����ڿ� �Ҹ��ڸ� �ۼ����ִ� ���� ����.
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