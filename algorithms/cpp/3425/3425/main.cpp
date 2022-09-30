#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

class GoStack
{

private:
	stack<long> arr;
	bool isError;

private:
	void error()
	{
		isError = false;
	}
	// Get value passed by parameter and pop them.
	void getFirstWithSecond(long& first, long& second)
	{
		first = arr.top();
		arr.pop();
		second = arr.top();
		arr.pop();
	}
	
public:
	GoStack()
	{
		isError = true;
	}
	~GoStack()
	{
	}

	void NUM(long value)
	{
		if (value < 0 || value > pow(10, 9)) { return error(); }

		arr.push(value);
	}
	void POP()
	{
		if (arr.empty()) { return error(); }
		
		arr.pop();
	}
	void INV()
	{
		if (arr.empty()) { return error(); }

		arr.top() *= -1;
	}
	void DUP()
	{
		if (arr.empty()) { return error(); }

		arr.push(arr.top());
	}
	void SWP()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;

		getFirstWithSecond(value1, value2);
		arr.push(value1);
		arr.push(value2);
	}
	void ADD()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;

		getFirstWithSecond(value1, value2);
		arr.push(value1 + value2);
	}
	void SUB()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;

		getFirstWithSecond(value1, value2);
		arr.push(value2 - value1);
	}
	void MUL()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;

		getFirstWithSecond(value1, value2);
		arr.push(value1 * value2);
	}
	void DIV()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;
		bool onFlag; // Notify changing sign

		onFlag = false;
		getFirstWithSecond(value1, value2);
		if (value1 == 0) { return error(); }
		if (value1 < 0)
		{
			value1 *= -1;
			onFlag = true;
		}
		if (value2 < 0)
		{
			value2 *= -1;
			onFlag = true;
		}

		onFlag ? arr.push(-(value2 / value1)) :
				 arr.push(value2 / value1);
	}
	void MOD()
	{
		if (arr.size() < 2) { return error(); }

		long value1, value2;
		bool onFlag;

		onFlag = false;
		getFirstWithSecond(value1, value2);
		if (value1 == 0) { return error(); }
		if (value1 < 0)
		{
			value1 *= -1;
			onFlag = true;
		}
		if (value2 < 0)
		{
			value2 *= -1;
			onFlag = true;
		}
		onFlag ? arr.push(-(value2 % value1)) :
				 arr.push(value2 % value1);
	}

	size_t GetSize()
	{
		return arr.size();
	}
	bool IsError()
	{
		return isError;
	}

	void Test()
	{
		while (!arr.empty())
		{
			cout << arr.top() << endl;
			arr.pop();
		}
	}
	
};

int main()
{
	GoStack stack;
	
	stack.NUM(1);
	stack.NUM(2);
	stack.SWP();
	stack.MOD();
	stack.Test();

	return 0;
}